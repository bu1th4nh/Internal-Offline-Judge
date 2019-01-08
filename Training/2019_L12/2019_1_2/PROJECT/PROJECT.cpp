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
#define task "PROJECT"
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
const long double eps = 1e-12;

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
            if(lab[u] > lab[v]) swap(u, v);
            lab[u] += lab[v];
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
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int, int, int, int> edge;
typedef tuple<ld, int, int, int> pack;
typedef pair<int, int> ii;
typedef vector<pack> vp;
typedef vector<edge> ve;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi rtmp, res;
ve edgeList;
int n, m;

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
    int u, v, l, c;
	scan(n);
	scan(m);

	FOR(i, 1, m)
	{
	    scan(u);
	    scan(v);
	    scan(l);
	    scan(c);

	    edgeList.emplace_back(edge(c, l, u, v, i));
	}
	//sort(whole(edgeList));
}

//Check
bool checkPrice(ld netPrice)
{
    //Check if we can build a spanning tree with cost / length less or equal netPrice
    DisjointSet dsu(n);
    int u, v, id, ptr;
    ld total, edg_val;
    vp sample;
    ll c, l;

    rtmp.clear();
    for(edge e: edgeList)
    {
        tie(c, l, u, v, id) = e;
        sample.emplace_back(-(ld)l * netPrice + (ld)c, u, v, id);
    }
    sort(whole(sample));

//    for(pack p: sample)
//    {
//        tie(edg_val, u, v, id) = p;
//        cerr << fixed << setprecision(9) << edg_val << sp << u << sp << v << sp << id << el;
//    }
//    getchar();

    ptr = 0;
    total = 0.00000000;
    for(pack p: sample)
    {
        tie(edg_val, u, v, id) = p;
        if(dsu.unite(u, v))
        {
            rtmp.emplace_back(id);
            total -= edg_val;

            if(total < 0) return 0;
            ++ptr;
        }
    }

    //cerr << total << el;
    return total > eps;
}


//Process
void Solve()
{
    ld L = 0.00000000, R = 1e10, mid = 0.0000000000;

    while(L <= R - eps)
    {
        mid = (L + R) / 2;

        //cerr << mid << sp;
        if(checkPrice(mid))
        {
            R = mid - eps;
            res = rtmp;
        }
        else L = mid + eps;
    }
    for(int x: res) print(x), pc(sp);
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
