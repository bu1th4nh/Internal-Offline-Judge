/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*
        Using Sparse Table.
        S[l][r] = min(S[l][k-1], S[l+2^(k-1)][k-1])

        Choose r / F(l, r) = min{ max{a[i]} , min{b[j]} }, l <= i,j <= r

*/
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <utility>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#endif // __cplusplus


using namespace std;
//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task "shopping"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}

const bool DEF_MAX = true;
const bool DEF_MIN = false;
const int inf = 1234567890;
//=====================================
//Typedefs
struct SparseTable
{
    const int MAX_LOG = 20;


    typedef vector<int> vi;
    typedef vector<vi> vvi;

    int n;
    vvi ST;
    vi nlog;
    bool type;      //true: max, false: min

    void buildTable(vi sample)
    {
        nlog[1] = 0;
        FOR(i, 2, n) nlog[i] = nlog[i >> 1] + 1;

        FOR(i, 0, nlog[n])
        {
            int cur = 1 << i;
            FOR(j, 1, n)
            {
                if(i == 0)
                {
                    ST[i][j] = sample[j];
                    continue;
                }
                ST[i][j] = type ? max(ST[i-1][j], ST[i-1][j+cur/2]) : min(ST[i-1][j], ST[i-1][j+cur/2]);
            }
        }
    }
    int getMax(int l, int r)
    {
        int cur = nlog[r - l + 1];
        return max(ST[cur][l], ST[cur][r - (1 << cur) + 1]);
    }
    int getMin(int l, int r)
    {
        int cur = nlog[r - l + 1];
        return min(ST[cur][l], ST[cur][r - (1 << cur) + 1]);
    }


    ~SparseTable() {}
    SparseTable() {}
    SparseTable(int __n, vi &smp, bool __ttype)
    {
        n = __n;
        type = __ttype;
        nlog = vi(MAX_LOG+1);
        ST   = vvi(MAX_LOG+12, vi(n+10));

        buildTable(smp);
    }
};

//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi a, b;
int n;

//=====================================         bit.ly/ming_traihechl2018
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    FILEOP_DEBUG()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
	scanf("%d", &n);

	a = b = vi(n+1, 0);

	FOR(i, 1, n) scanf("%d", &a[i]);
	FOR(i, 1, n) scanf("%d", &b[i]);

}

//Check
void Solve()
{
    SparseTable t1(n, a, DEF_MAX);
    SparseTable t2(n, b, DEF_MIN);
    int l, r, mid, cur, res;

    cur = 0;

    FOR(i, 1, n)
    {
        l = i, r = n, res = 0;

        while(l <= r)
        {
            mid = (l + r) / 2;

            if(t1.getMax(i, mid) < t2.getMin(i, mid))
            {
                cur = mid;
                l   = mid + 1;

            }
            else r  = mid - 1;
        }

        res = max(res, min(t1.getMax(i, cur), t2.getMin(i, cur)));
        res = max(res, min(t1.getMax(i, cur+1), t2.getMin(i, cur+1)));

        printf("%d ", res);
    }



}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}

//Sample Test
/*
8
7 2 5 6 9 3 2 1
5 4 7 9 8 8 1 3

5 4 7 8 8 3 1 1
*/
