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
#define task "WGAME"
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
        return T(1) * __X * __X;
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
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vs> vvs;
typedef vector<vb> vvb;
typedef vector<vvs> vs3d;
typedef vector<vvi> vi3d;
typedef vector<vii> vvii;
typedef vector<vi3d> vi4d;
string src;
int n, m;
vi4d dp;
vs3d ok;
ll mod;
vs a;

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
    char str[2019];
    scan(m);
    scan(n);
    scan(mod);
    scanf("%s", &str);

    src = string(str);
    dp = vi4d(32, vi3d(32, vvi(32, vi(32, -1))));
    ok = vs3d(m+1, vvs(n+1));
    a = vs(m+1);

    FOR(i, 1, m)
    {
        scanf("%s", &str);
        a[i] = '$' + string(str);
    }
}

//Check
bool Verify(string s, string t)
{
    string p = s; reverse(whole(p));
    if(s != p) return 0;
    return s.find(t) != string::npos;
}

//Subtask 1: Bruteforce
void Subtask1()
{
    string tmp;
    FOR(i, 1, m)
    {
        if(a[i][1] == '#') break;
        tmp += a[i][1];
        ok[i][1].pb(tmp);
    }

    tmp = a[1][1];
    FOR(i, 2, n)
    {
        if(a[1][i] == '#') break;
        tmp += a[1][i];
        ok[1][i].pb(tmp);
    }

    FOR(i, 2, m) FOR(j, 2, n) if(a[i][j] != '#')
    {
        for(auto x: ok[i-1][j]) ok[i][j].pb(x += a[i][j]);
        for(auto x: ok[i][j-1]) ok[i][j].pb(x += a[i][j]);
    }

    int res = 0;
    for(auto x: ok[m][n]) if(Verify(x, src)) ++res;
    print(res % mod);
}


//Subtask 234: DP
ll calcSum(ll x, ll y, ll z, ll t)
{
    return (x + y + z + t) % mod;
}
ll Recur(int i, int j, int u, int v)
{
    //Out-of-bound
    if(i > u || j > v || i > m || j > n) return 0;

    //Already calculated
    if(dp[i][j][u][v] != -1) return dp[i][j][u][v];

    //Invalid case
    if(a[i][j] != a[u][v]) return dp[i][j][u][v] = 0;
    if(a[i][j] == '#' || a[u][v] == '#') return dp[i][j][u][v] = 0;

    //Base case
    if(i == u &&  j  == v) return dp[i][j][u][v] = 1;
    if(i == u && j+1 == v) return dp[i][j][u][v] = 1;
    if(j == v && i+1 == u) return dp[i][j][u][v] = 1;

    return dp[i][j][u][v] = calcSum(
            Recur(i+1, j, u, v-1),
            Recur(i+1, j, u-1, v),
            Recur(i, j+1, u, v-1),
            Recur(i, j+1, u-1, v)
    );
}
void Subtask234()
{
    ll res = Recur(1, 1, m, n);
    FOR(i, 1, m) FOR(j, 1, n) if(a[i][j] == src[0]) a[i][j] = '#';
    dp = vi4d(32, vi3d(32, vvi(32, vi(32, -1))));
    ll inv = Recur(1, 1, m, n);

    print((res - inv + mod) % mod);
}

//Output
void Solve()
{
    if(m <= 10 && n <= 10) Subtask1();
    else Subtask234();
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
