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
#define task "MQUEEN"
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
const int inf = 1000000007;


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef bitset<32> bs32;
typedef vector<bs32> vbs;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int dp[1048][1048];
int n, res, OK;
vi destination;
vii initial;
vvi dist;

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
    char p[16];
    int px, py;
	scan(n);

	destination = vi(n+1, -1);
	initial = vii(n);

	OK = (1 << n) - 1;
	res = inf;

	FORl(i, 0, n)
	{
	    scanf("%s", &p);
	    px = p[0] - 'a';
	    py = p[1] - '1';
	    initial[i] = ii(px, py);
	}
}

//Generate distance
void genDistance()
{
    /** \brief Generate distance from initial and destination array */
    FORl(i, 0, n)
    {
        FORl(j, 0, n) dist[i][j] = max(__abs(initial[i].fi - j), __abs(initial[i].se - destination[j]));
    }
}



//DP with bit-mask
int matching(int state_1, int state_2)
{
    if(dp[state_1][state_2] > 0) return dp[state_1][state_2];
    if(state_1 == OK && state_2 == OK) return (dp[state_1][state_2] = 0);

    int ret = inf, pos = 0;
    int ss1 = OK & (~state_1);
    int ss2 = (OK & (~state_2)) & (-(OK & (~state_2)));
    int i = __builtin_ctz(ss2);


    while(ss1)
    {
        pos = ss1 & (-ss1);
        ss1 -= pos;

        minimize(ret, matching(state_1 | pos, state_2 | ss2) + dist[__builtin_ctz(pos)][i]);
    }

    return (dp[state_1][state_2] = ret);
}
void computeOptimalPath()
{
    dist = vvi(n, vi(n, 0));
    memset(dp, -1, sizeof dp);

    genDistance();
    minimize(res, matching(0, 0));
}


//Process
void Attempt(int rw, int ld, int rd, int i)
{
    if(rw == OK) {computeOptimalPath(); return;}
    int pos, p;

    pos = OK & (~(rw | ld | rd));
    while(pos)
    {
        p = pos & (-pos);
        pos -= p;

        destination[i] = __builtin_ctz(p);
        Attempt(rw | p, (ld | p) << 1, (rd | p) >> 1, i + 1);
    }
}
void Solve()
{
    Attempt(0, 0, 0, 0);
    if(res >= inf) puts("-1");
    else print(res);
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
10
c1 d1 e1 c2 d2 e2 c3 d3 a1 a2
*/

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
