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
#define task "TOURIST"
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vii edgeList;
vvi adj, dp;
int n, m;
vll happ;
ll res1;
vi res2;

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

	res1 = 0LL;
	adj = vvi(n+1);
	happ = vll(n+1, 0LL);
	dp = vvi(n+1, vi(3, 0));

	FOR(i, 1, n)
	{
	    scan(happ[i]);
	    if(res1 < happ[i]) res1 = happ[i], res2 = {i};
	}
	FOR(i, 1, m)
	{
	    scan(u);
	    scan(v);
	    adj[u].pb(v);
	    adj[v].pb(u);

	    edgeList.emplace_back(u, v);
	    if(res1 < happ[u] + happ[v]) res1 = happ[u] + happ[v], res2 = {u, v};
	}
}

//Process
void Solve()
{
    FOR(i, 1, n) for(int v: adj[i])
    {
        if(happ[dp[i][0]] < happ[v])
        {
            dp[i][2] = dp[i][1];
            dp[i][1] = dp[i][0];
            dp[i][0] = v;
        }
        else if(happ[dp[i][1]] < happ[v])
        {
            dp[i][2] = dp[i][1];
            dp[i][1] = v;
        }
        else if(happ[dp[i][2]] < happ[v]) dp[i][2] = v;
    }

//    FOR(j, 0, 2)
//    {
//        FOR(i, 1, n) cerr << dp[i][j] << sp;cerr << el;
//    }


    FOR(i, 1, n) if(dp[i][0] > 0 && dp[i][1] > 0)
    {
        if(res1 < happ[dp[i][0]] + happ[dp[i][1]] + happ[i] && dp[i][0] != dp[i][1])
        {
            res1 = happ[dp[i][0]] + happ[dp[i][1]] + happ[i];
            res2 = {dp[i][0], i, dp[i][1]};


            //cerr << res1 << sp; for(int x: res2) cerr << x << sp; cerr << el;
        }
    }

    FORl(i, 0, m)
    {
        int u = edgeList[i].fi;
        int v = edgeList[i].se;

        for(int x: dp[u]) if(x > 0 && x != u && x != v)
        {
            for(int y: dp[v]) if(y > 0 && y != x && y != u && y != v)
            {
                if(happ[x] + happ[y] + happ[u] + happ[v] > res1)
                {
                    res1 = happ[x] + happ[y] + happ[u] + happ[v];
                    res2 = {x, u, v, y};


                    //cerr << res1 << sp; for(int x: res2) cerr << x << sp; cerr << el;
                }
            }
        }
    }


    print(res2.size()); pc(el);
    for(int x: res2) print(x), pc(sp);

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
