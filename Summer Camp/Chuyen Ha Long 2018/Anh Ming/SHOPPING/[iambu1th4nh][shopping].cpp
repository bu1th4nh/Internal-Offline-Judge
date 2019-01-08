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
#define task ""
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


const int inf = 1234567890;
//=====================================
//Typedefs
struct SparseTable
{
    const int MAX_LOG = 20;

    typedef pair<int, int> ii;
    typedef vector<int> vi;
    typedef vector<ii> vii;
    typedef vector<vii> vvii;

    int n;
    vi nlog;
    vvii ST;

    void buildTable(const vi &a)
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
                    ST[i][j] = ii(a[j], a[j]);
                    continue;
                }
                ST[i][j] = ii(max(ST[i-1][j].fi, ST[i-1][j+cur/2].fi), min(ST[i-1][j].se, ST[i-1][j+cur/2].se));
            }
        }
    }
    int getMax(int l, int r)
    {
        int cur = nlog[r - l + 1];
        return max(ST[cur][l].fi, ST[cur][r - (1 << cur) + 1].fi);
    }
    int getMin(int l, int r)
    {
        int cur = nlog[r - l + 1];
        return min(ST[cur][l].se, ST[cur][r - (1 << cur) + 1].se);
    }


    ~SparseTable() {}
    SparseTable() {}
    SparseTable(int __n, const vi &a)
    {
        n = __n;
        nlog = vi(MAX_LOG+1);
        ST = vvii(MAX_LOG+1, vii(n+1));

        buildTable(a);
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
vi a, b, nlog;
vvi ST;
int n;

//=====================================
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

	ST = vvi(n+1, vi(20, 0));
	a = b = nlog = vi(n+1, 0);

	FOR(i, 1, n) scanf("%d", &a[i]);
	FOR(i, 1, n) scanf("%d", &b[i]);

}

//Check
void Solve()
{
    SparseTable t1(n, a);
    SparseTable t2(n, b);
    int l, r, mid, cur_res1, cur_res2;

    cur_res1 = cur_res2 = 0;

    FOR(i, 1, n-2)
    {
        l = i, r = n;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(t1.getMax(l, mid) >= t2.getMin(l, mid))
            {
                r = mid - 1;
                cur_res1 = mid;
            }
            else l = mid + 1;
            if(l == r) break;

            //cerr << "BS #1: " << l << sp << mid << sp << r << sp << cur_res1 << el;
        }


        l = i, r = n;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(t1.getMax(l, mid) < t2.getMin(l, mid))
            {
                l = mid + 1;
                cur_res2 = mid;
            }
            else r = mid - 1;
            if(l == r) break;

            //cerr << "BS #2: " << l << sp << mid << sp << r << sp << cur_res2 << el;
        }

        int x = (cur_res1 > 0) ? min(t1.getMax(i, cur_res1), t2.getMax(i, cur_res1)) : -inf;
        int y = (cur_res2 > 0) ? min(t1.getMax(i, cur_res2), t2.getMax(i, cur_res2)) : -inf;


        printf("%d ", max(x, y));
    }


    printf("%d ", max(min(t1.getMax(n-1, n-1), t2.getMin(n-1, n-1)), min(t1.getMax(n-1, n), t2.getMin(n-1, n))));
    printf("%d", min(a[n], b[n]));
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
