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
#define task "INCMAT"
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
typedef tuple<int, int, int, int, ll> packs;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<packs> vp;
vvi a, ps, top_left_max, bot_right_max;
int n, m, nQuery;
vp queries;
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
    ll val;
    int x, y, u, v;

    scan(m);
    scan(n);

    a = ps = top_left_max = bot_right_max = vvi(m+2, vi(n+2, 0));
    FOR(i, 1, m)
    {
        FOR(j, 1, n) scan(a[i][j]);
    }

    scan(nQuery);
    queries = vp(nQuery);
    for(auto &p: queries) 
    {
        scan(x);
        scan(y);
        scan(u);
        scan(v);
        scan(val);

        p = packs(x, y, u, v, val);
        ps[u+1][v+1] += val;
        ps[x][v+1] -= val;
        ps[u+1][y] -= val;
        ps[x][y] += val;
    }
}

//Check
void Preps()
{
    FOR(i, 1, m)
    {
        FOR(j, 1, n) ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
    }
    FOR(i, 1, m)
    {
        FOR(j, 1, n) ps[i][j] += a[i][j];
    }

    // cerr << el;
    // FOR(i, 1, m)
    // {
    //     FOR(j, 1, n) cerr << ps[i][j] << sp;
    //     cerr << el;
    // }
    // cerr << el;

    FOR(i, 1, m)
    {
        FOR(j, 1, n) top_left_max[i][j] = max( max(top_left_max[i-1][j], top_left_max[i][j-1]), 
                                               max(top_left_max[i-1][j-1], ps[i][j]));
    }
    FORb(i, m, 1)
    {
        FORb(j, n, 1) bot_right_max[i][j] = max( max(bot_right_max[i+1][j], bot_right_max[i][j+1]),
                                                 max(bot_right_max[i+1][j+1], ps[i][j]));
    }
    
    
    // cerr << el;
    // FOR(i, 1, m)
    // {
    //     FOR(j, 1, n) cerr << top_left_max[i][j] << sp;
    //     cerr << el;
    // }
    // cerr << el;
    // cerr << el;
    // FOR(i, 1, m)
    // {
    //     FOR(j, 1, n) cerr << bot_right_max[i][j] << sp;
    //     cerr << el;
    // }
    // cerr << el;
}


//Process
void Solve()
{
    res = 1000000000000009;
    ll val, tmp;
    int x, y, u, v;

    for(auto p: queries)
    {
        tmp = 0;
        tie(x, y, u, v, val) = p;
        maximize(tmp, max(top_left_max[m][y-1],  top_left_max[x-1][n]));
        maximize(tmp, max(bot_right_max[u+1][1], bot_right_max[1][v+1]));
        maximize(tmp, top_left_max[m][n] - val);

        minimize(res, tmp);
    }
    cout << res << el;
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Preps();
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//