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

//#define DEBUG
#define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "FARM"
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
#define what_is(x) cerr << #x << " is " << x << endl;
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
    template<class T, class R> T max(const T &__X, const R &__Y)
    {
        return __X > __Y ? __X : __Y;
    }
    template<class T, class R> T min(const T &__X, const R &__Y)
    {
        return __X < __Y ? __X : __Y;
    }
    template<class T, class R> void maximize(T &__X, R __Y)
    {
        __X = __X > __Y ? __X : __Y;
    }
    template<class T, class R> void minimize(T &__X, R __Y)
    {
        __X = __X < __Y ? __X : __Y;
    }
    template<class T> int getBit(T &__X, int __i)
    {
        return ((__X >> __i) & 1) == 1;
    }
    template<class T> bool inRange(T __L, T __R, T __X)
    {
        return __L <= __X && __X <= __R;
    }
    template<class T> T __abs(T __X)
    {
        return (__X < 0) ? -__X : __X;
    }
    template<class T> T __sqr(T __X)
    {
        return __X * __X;
    }
#endif
//Fast I/O
template<class T> inline void scan(T &__ret)
{
    __ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) __ret = __ret * 10 + c - '0';
    __ret = (neg) ? -__ret : __ret;
}
template<class T> void print(T __X)
{
    if(__X < 0)
    {
        putchar('-');
        __X *= -1;
    }

    if(__X > 9) print(__X / 10);
    putchar(__X % 10 + '0');
}

//=====================================
//Constants



//=====================================
//Typedefs
struct DisjointSet
{
    typedef vector<int> vi;
    vi lab;
    int n;

    int find(int u)
    {
        return lab[u] < 0 ? u : lab[u] = find(lab[u]);
    }
    bool unite(int u, int v)
    {
        u = find(u);
        v = find(v);

        if(u != v)
        {
            if(lab[u] < lab[v]) swap(u, v);
            lab[v] += lab[u];
            lab[v] = u;

            return 1;
        }
        return 0;
    }


    DisjointSet() {}
    DisjointSet(int __n)
    {
        n = __n;
        lab = vi(n+1, -1);
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef tuple<ll, int, int> edge;
typedef pair<int, int> ii;
typedef map<ii, int> miii;
typedef vector<edge> ve;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
miii mapPolygon, mapWeights;
ve edgeList;
int n;

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
    int u, v, w, m;

	scan(n);
	FOR(iPoly, 1, n)
	{
	    scan(m);
	    vi dist(m, 0);
	    vi vertexes(m, 0);

	    for(int &x: vertexes) scan(x);
        vertexes.emplace_back(vertexes[0]);
	    for(int &x: dist) scan(x);

	    FORl(i, 0, m)
	    {
	        u = vertexes[i], v = vertexes[i+1]; if(u > v) swap(u, v);
	        if(mapPolygon.count(ii(u, v)))
            {
                edgeList.emplace_back(dist[i], iPoly, mapPolygon[ii(u, v)]);
                mapPolygon[ii(u, v)] = -1;
            }
            else
            {
                mapPolygon[ii(u, v)] = iPoly;
                mapWeights[ii(u, v)] = dist[i];
            }
	    }
	}
}

//Check
void Solve()
{
    ll w, t1 = 0LL, t2 = 0LL;
    int u, v;

    DisjointSet ctb(n+1);
    sort(whole(edgeList));
    for(edge e: edgeList)
    {
        tie(w, u, v) = e;
        if(ctb.unite(u, v)) t1 += w;
    }


    for(auto p: mapPolygon) if(p.se != -1) edgeList.emplace_back(mapWeights[p.fi], n+1, p.se);
    ctb = DisjointSet(n+1);
    sort(whole(edgeList));
    for(edge e: edgeList)
    {
        tie(w, u, v) = e;
        if(ctb.unite(u, v)) t2 += w;
    }
    print(min(t1, t2));
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
