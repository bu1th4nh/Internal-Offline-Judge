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
#include <cassert>
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
#define task "MAXISET"
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
vvi raw, adj, mem;
int T, n, m, q;
vi scope, w;


ofstream foo;


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

//Utilities
inline int readInt()
{
    char c = 0;
    int ret = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c); c = getchar()) ret = ret * 10 + int(c - '0');

    #ifdef __debug
        cerr << ret << el;
    #endif // __debug

    return neg ? -ret : ret;
}

//Enter
void Enter()
{
    int u, v;
    n = readInt(), m = readInt();

    w = vi(n, 0);
    adj = raw = vvi(n);
    mem = vvi(n, vi(2, -1));

    for(int &x: w) x = readInt();

    FOR(i, 1, m)
    {
        u = readInt(), v = readInt();
        raw[u].pb(v);
        raw[v].pb(u);
    }

    q = readInt();
}

//Check
void DFS(int u, int par)
{
    for(int v: raw[u]) if(v != par)
    {
        adj[u].pb(v);
        DFS(v, u);
    }
}
int MIS(int u, int k)
{
    //cerr << u << sp << k << el;

    if(adj[u].empty()) return (mem[u][k] = (k == 1 && scope[u]) ? w[u] : 0);
    if(mem[u][k] != 0) return mem[u][k];

    int f_1 = 0, ret = 0;

    if(k == 0)
    {
        for(int v: adj[u]) ret += MIS(v, scope[v]);
    }
    else if(k == 1)
    {
        for(int v: adj[u]) f_1 += MIS(v, 0);
        ret = max(scope[u] * w[u] + f_1, MIS(u, 0));
    }

    return (mem[u][k] = ret);
}

//Process
void Solve()
{
    int k;
    DFS(0, -1);
    while(q--)
    {
        int res = 0;
        scope = vi(n, 0);
        mem = vvi(n, vi(2, 0));

        k = readInt();
        while(k--) scope[readInt()] = 1;

        printf("%d\n", MIS(0, 1));
    }
}


//Main Procedure
int main()
{
    T = readInt();
    while(T--)
    {
        Enter();
        Solve();
        putchar('\n');
    }
    return 0;
}

/*
1
6 5
2 4 1 3 5 2
0 1
0 2
2 3
2 4
4 5
2
3 1 3 5
4 0 1 3 5

1
8 7
7 1 4 2 4 3 6 8
0 1
0 2
1 5
5 7
2 3
2 4
4 6
1
4 4 5 6 7
*/
