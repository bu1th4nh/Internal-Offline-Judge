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
#define task "DIVSET2"
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
typedef pair<ll, int> ii;
typedef vector<bool> vb;
typedef bitset<256> bs;
typedef vector<ll> vi;
typedef vector<bs> vbs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int matched, n;
vvi adj, res;
vbs cand;
vb done;
vi col;
vii a;

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
	scan(n);

	matched = n;
	a = vii(n+1);
	adj = vvi(n+1);
	cand = vbs(n+1);
	done = vb(n+1, 0);
	col = vi(n+1, 0LL);

	FOR(i, 1, n) FOR(j, 1, n) cand[i][j] = 1;
	FOR(i, 1, n) scan(a[i].fi),  a[i].se = i;
	sort(whole_1(a));
//	FOR(i, 1, n) cerr << a[i].fi << sp << a[i].se << el;
}


//Check
bool cmp(bs x, bs y)
{
    return x.count() < y.count();
}
void graphColoring()
{
    cand[0].set();
    done[0] = 1;

    while(matched)
    {
        FOR(i, 1, n)
        {
            int id = 0;
            FOR(j, 1, n) if(cand[id].count() > cand[j].count() && (!done[j]) && cand[j].count() < 256) id = j;

            if(done[id]) return;
            col[id] = cand[id]._Find_first();
            cand[id].set();
            done[id] = 1;


            --matched;
            if(matched <= 0) return;
            for(int u: adj[id]) if(!done[u]) cand[u][col[id]] = 0;
        }
    }
}


//Process
void Solve()
{
    FOR(i, 1, n)
    {
        FORl(j, 1, i) if(i != j && a[i].fi % a[j].fi == 0)
        {
            adj[i].pb(j);
            adj[j].pb(i);
        }
    }

//    FOR(i, 1, n)
//    {
//        fprintf(stderr, "%d: ", i);
//        for(int v: adj[i]) cerr << v << sp;
//        cerr << el;
//    }


    graphColoring();


    int cnt = *max_element(whole_1(col));
    res = vvi(cnt+1);
    FOR(i, 1, n) res[col[i]].pb(a[i].se);

    print(cnt), putchar(el);
    FOR(i, 1, cnt)
    {
        for(auto x: res[i]) print(x), putchar(sp);
        putchar(el);
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

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
