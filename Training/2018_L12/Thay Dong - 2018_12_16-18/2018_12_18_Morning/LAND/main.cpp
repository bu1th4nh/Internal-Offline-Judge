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
#define task "LAND"
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
const long long inf = 100000000000000000LL;


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vvi ps1, ps2;
int n, m, k;
ll t;


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
    int u;
	scan(m); scan(n);
	scan(k); scan(t);

	ps1 = vvi(m+1, vi(n+1, 0LL));
	ps2 = vvi(n+1, vi(m+1, 0LL));

	FOR(i, 1, m) FOR(j, 1, n) scan(u), ps1[i][j] = ps2[j][i] = u;

	//FOR(i, 1, m) {FOR(j, 1, n) cerr << ps1[i][j] << sp; cerr << el;} cerr << el;
	//FOR(i, 1, n) {FOR(j, 1, m) cerr << ps2[i][j] << sp; cerr << el;} cerr << el;

	FOR(i, 1, m) FOR(j, 1, n) ps1[i][j] += ps1[i-1][j] + ps1[i][j-1] - ps1[i-1][j-1];
	FOR(i, 1, n) FOR(j, 1, m) ps2[i][j] += ps2[i-1][j] + ps2[i][j-1] - ps2[i-1][j-1];

    //FOR(i, 1, m) {FOR(j, 1, n) cerr << ps1[i][j] << sp; cerr << el;} cerr << el;
	//FOR(i, 1, n) {FOR(j, 1, m) cerr << ps2[i][j] << sp; cerr << el;} cerr << el;
}

//Helper Function
ll getSum(int m, int n, int i1, int j1, int i2, int j2, const vvi &ps)
{
    if(i2 > m || j2 > n || i2 < 1 || j2 < 1) return inf;
    if(i1 > m || j1 > n || i1 < 1 || j1 < 1) return inf;
    return ps[i2][j2] - ps[i2][j1-1] - ps[i1-1][j2] + ps[i1-1][j1-1];
}


//Subtask 2
ll Calculate(vvi &ps, int m, int n)        //For Subtask 2
{
    //hl[c][r]: Minimum cost to buy a square piece of land with edge length r and left-contact with edge #c
    //hr[c][r]: ___________________________________________________________________right-contact with edge #c
    //fl[c][r]: Minimum cost to buy a square piece of land with edge length r on the left of edge #c
    //fr[c][r]: ____________________________________________________________________ right of edge #c

    ll ret = 0LL;
    vvi hl, hr, fl, fr;
    hl = hr = fl = fr = vvi(2*m+2, vi(2*n+2, inf));

    //cerr << m << sp << n << el;
    //Prepare hl and hr array
    FOR(c, 1, m)
    {
        FOR(r, 1, n)
        {
            FOR(i, 1, n-r+1) minimize(hl[c][r], getSum(m, n, c-r+1, i, c, i+r-1, ps));
        }
    }
    FORb(c, m, 1)
    {
        FOR(r, 1, n)
        {
            FOR(i, 1, n-r+1) minimize(hr[c][r], getSum(m, n, c, i, c+r-1, i+r-1, ps));
        }
    }

//    cerr << "HL: \n";
//    FOR(i, 1, m) {FOR(j, 1, n) {if(hl[i][j] < inf) cerr << hl[i][j] << sp; else cerr << "--- ";} cerr << el;} cerr << el;
//    cerr << "HR: \n";
//    FOR(i, 1, m) {FOR(j, 1, n) {if(hr[i][j] < inf) cerr << hr[i][j] << sp; else cerr << "--- ";} cerr << el;} cerr << el;

    //Prepare fl and fr array
    FOR(c, 1, m)
    {
        FOR(r, 1, n) fl[c][r] = min(fl[c-1][r], hl[c][r]);
    }
    FORb(c, m, 1)
    {
        FOR(r, 1, n) fr[c][r] = min(fr[c+1][r], hr[c][r]);
    }

//    cerr << "FL: \n";
//    FOR(i, 1, m) {FOR(j, 1, n) {if(fl[i][j] < inf) cerr << fl[i][j] << sp; else cerr << "--- ";}  cerr << el;} cerr << el;
//    cerr << "FR: \n";
//    FOR(i, 1, m) {FOR(j, 1, n) {if(fr[i][j] < inf) cerr << fr[i][j] << sp; else cerr << "--- ";}  cerr << el;} cerr << el;

    //Calculate the result
    FOR(c, 1, m)
    {
        FOR(r1, 1, n)
        {
            FOR(r2, 1, n) if(fl[c][r1] + fr[c+1][r2] <= t) maximize(ret, r1*r1+r2*r2);
        }
    }
    return ret;
}
void Subtask2()
{
    cout << max(Calculate(ps1, m, n), Calculate(ps2, n, m)) << el;
}


//Subtask 1.
void Subtask1()
{
    ll res = 0LL;
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            FOR(p, res+1, min(n-i+1, m-j+1))
            {
                if(getSum(m, n, i, j, i+p-1, j+p-1, ps1) <= t)
                {
                    maximize(res, p);
                }
            }
        }
    }
    cout << res * res << el;
}

//Process
void Solve()
{
    if(k == 1) Subtask1();
    else Subtask2();
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
/*
2 3 2 25
1 2 3
4 5 6
*/

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
