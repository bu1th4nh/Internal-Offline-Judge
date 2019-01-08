/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Solution Briefing - Foreword



//=====================================
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#include <chrono>
#endif // __cplusplus

using namespace std;

// #define DEBUG
// #define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "ISLANDS"
#define maxinp ()
#define fi first
#define se second
#define pb push_back
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define r_whole(x) x.rbegin(),x.rend()
#define FOR(i, x, y) for(auto i=x; i<=y; ++i)
#define FORl(i, x, y) for(auto i=x; i<y; ++i)
#define FORb(i, x, y) for(auto i=x; i>=y; --i)
#define FORlb(i, x, y) for(auto i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP()                        \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
    freopen(task".err", "w", stderr);   \
}

//Macroes - Optional
#ifdef OPTIONAL_FEATURE
    #define pc(x) putchar(x)
    #define gc() getchar()
#endif



//=====================================
//Auxilary Functions and Fast I/O
#ifdef OPTIONAL_FEATURE
    template<class T, class R> T max(T &x, R &y)
    {
        return x > y ? x : y;
    }
    template<class T, class R> T min(T &x, R &y)
    {
        return x < y ? x : y;
    }
    template<class T, class R> void maximize(T &x, R y)
    {
        x = x > y ? x : y;
    }
    template<class T, class R> void minimize(T &x, R y)
    {
        x = x < y ? x : y;
    }
    template<class T> int getBit(T &x, int i)
    {
        return ((x >> i) & 1) == 1;
    }
    template<class T> T __abs(T &x)
    {
        return (x = (x < 0) ? -x : x);
    }
#endif
//Fast I/O
template<class T> inline void scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret = (neg) ? -ret : ret;

    #ifdef DEBUG
        cerr << "FastScan Diagnostic: " << ret << el;
    #endif
}
template<class T> void print(T x)
{
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

//=====================================
//Constants



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
typedef set<ii> sii;
int n_connected_comp, n, m;
vvi tp_concomp, adj;
vii sz_concomp;
sii edgePool;
vb avail;
ll res;

//=====================================
//Functions and procedures
//File I/O and utilities
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    #ifdef DEBUG
        FILEOP_DEBUG()
    #else
        FILEOP()
    #endif
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}


//Enter
void Enter()
{
    int u, v;
    scan(n);
    scan(m);

    avail = vb(n+1, 1);
    adj = vvi(n+1);
    res = 0LL;

    FOR(i, 1, m)
    {
        scan(u);
        scan(v);
        if(u > v) swap(u, v);
        edgePool.insert(ii(u, v));
    }

    for(ii e: edgePool)
    {
        u = e.first;
        v = e.second;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

//Check
void DFS(int u, int i)
{
    avail[u] = 0;
    tp_concomp[i].push_back(u);
    for(int v: adj[u]) if(avail[v]) DFS(v, i);
}
ll calc_cycle(int n)
{
    ll ret = 0LL;
    int q = (n - 1) >> 1;
    int p = n >> 1;

    FOR(i, 1, q) ret += 1LL * i * (n-i);
    ret += 1LL * p * (p+1) * (2*p+1) / 6;

    return ret;
}
ll calc_degen_tree(int n)
{
    ll ret = 0LL;
    FOR(i, 1, n-1) ret += 1LL * i * (n-i);
    return ret;
}

//Process
void Preps()
{
    tp_concomp = vvi(1);
    sz_concomp = vii(1);

    n_connected_comp = 0;
    FOR(i, 1, n) if(avail[i])
    {
        tp_concomp.push_back(vi());
        DFS(i, ++n_connected_comp);
        sz_concomp.push_back(ii(0, tp_concomp[n_connected_comp].size()));
    }
}
void Solve()
{
    int type;
    FOR(i, 1, n_connected_comp)
    {
        type = 2;       //1: Degenerated Tree, 2: Cycle.
        for(int u: tp_concomp[i]) if(adj[u].size() == 1)
        {
            type = 1;
            break;
        }
        sz_concomp[i].fi = type;
    }

    FOR(i, 1, n_connected_comp)
    {
        int tp = sz_concomp[i].fi;
        int sz = sz_concomp[i].se;
        res += (tp == 1) ? calc_degen_tree(sz) : calc_cycle(sz);
    }
    cout << res * 2LL << el;
}


//Main Procedure
int main()
{
//    cerr << calc_cycle(10) << el;

    FileInit();
    Enter();
    Preps();
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
