/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
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
using namespace std;


//=====================================
//Macros
#define task "L1L2"
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


//=====================================
//FT
struct FenwickTree
{
    typedef vector<int> vi;
    #define _(x) (x & (-x))

    vi T;
    int n;

    void update(int pos, int val)
    {
        while(pos <= n)
        {
            T[pos] = max(T[pos], val);
            pos += _(pos);
        }
    }
    int get(int pos)
    {
        int ret = 0;
        if(pos == 0) return 0;
        while(pos > 0)
        {
            ret = max(T[pos], ret);
            pos -= _(pos);
        }
        return ret;
    }


    FenwickTree(int __n)
    {
        n = __n;
        T = vi(__n+16);
    }
    FenwickTree() {}

    ~FenwickTree() {}
};




//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi d, a, F;
int n, res;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
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
	d = vi(n+1);

	FOR(i, 1, n) scanf("%d", &d[i]);
}

//Process
void Solve()
{
    a = vi(1, 0);
    FOR(i, 1, n)
    {
        if(d[i] == 1) a.push_back(d[i]+1), a.push_back(d[i]);
        else if(d[i] == n) a.push_back(d[i]), a.push_back(d[i]-1);
        else
        {
            a.push_back(d[i] + 1);
            a.push_back(d[i]);
            a.push_back(d[i] - 1);
        }
    }

    n = a.size() - 1;
    F = vi(n + 1, 0);
    FenwickTree ft(n);

    FOR(i, 1, n)
    {
        F[i] = ft.get(a[i] - 1) + 1;        //LIS, ended at a[i] - 1
        res = max(res, F[i]);               //Result update
        ft.update(a[i], F[i]);              //Tree upd.
    }

    printf("%d\n", res);
}


//Main Procedure
int main()
{
    FileDebug();
    Enter();
    Solve();
    FileClose();
    return 0;
}
