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
 #define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task ""
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
    template<class T> T __abs(T x)
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
class CutVertexAndBridge
{
    typedef pair<int, int> ii;
    typedef vector<bool> vb;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<ii> vii;

    vvi adj;
    vb isCut;
    vii bridge;
    int timeStamp, n;
    vi num, low, cut_vtx;

    void DFS(int u, int p)
    {
        int nChild = 0;
        low[u] = num[u] = ++timeStamp;

        for(int v: adj[u]) if(v != p)
        {
            if(num[v]) minimize(low[u], num[v]);
            else
            {
                DFS(v, u);
                ++nChild;

                minimize(low[u], low[v]);
                if(low[v] >= num[v]) bridge.push_back(ii(u, v));

                isCut[u] = (u == p && nChild >= 2) || (u != p && low[v] >= num[u]);
            }
        }
    }


public:
    void addEdge(int u, int v)
    {
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi extract_cut_vertices()
    {
        return cut_vtx;
    }
    vii extract_bridges()
    {
        return bridge;
    }
    int extract_cut_vertices_size()
    {
        return cut_vtx.size();
    }
    int extract_bridges_size()
    {
        return bridge.size();
    }
    void start()
    {
        FOR(i, 1, n) if(!num[i]) DFS(i, i);
        FOR(i, 1, n) if(isCut[i]) cut_vtx.push_back(i);
    }



    CutVertexAndBridge(int __n)
    {
        n = __n;
        timeStamp = 0;
        isCut = vb(n+1, false);
        num = vi(n+1, 0);
        low = vi(n+1, 0);
        adj = vvi(n+1);
    }
    CutVertexAndBridge() {}

    ~CutVertexAndBridge() {}
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
int n, u, v;


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


//Process
void Solve()
{
    scanf("%d", &n);

    CutVertexAndBridge loz(n);

    FOR(i, 1, n-1)
    {
        scanf("%d%d", &u, &v);
        loz.addEdge(u, v);
    }
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        scanf("%d%d", &u, &v);
        loz.addEdge(u, v);
    }

    loz.start();
    cout << loz.extract_bridges_size();
}



//Main Procedure
int main()
{
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
