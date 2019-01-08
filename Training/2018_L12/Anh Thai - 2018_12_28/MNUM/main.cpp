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
#define task "MNUM"
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi pow10, dp, pw;
int nTest;
ll n, x;

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


//Check
ll getLength(ll n)
{
    ll ret = 0LL;
    if(n <= 9) return n;

    int p = floor(log10(n));
    return dp[p] + (n - pow10[p] + 1) * (p + 1);
}
void Solve()
{
    scan(n);
    if(n == 1){pc('1'); return;}
    if(n <  6){pc('2'); return;}


    //Get the total length of src. string
    ll totalLength = getLength(n);

    //Get the position of resulting char.
    int ptr = 0; ll pos = 6LL;
    while(1)
    {
        ll tmp = (pos - 1) * 4 + 2;
        if(tmp > totalLength) break;
        pos = tmp;
    }

    //Binary search to find x: minimum integer such that getLength(x) >= pos
    ll L = 1, R = n, mid = 0LL, min_integer = 0LL;
    while(L <= R)
    {
        mid = (L + R) / 2;
        if(getLength(mid) >= pos)
        {
            min_integer = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }

    //Retrieve the result
    pos = getLength(min_integer) - pos;
    while(pos--) min_integer /= 10;
    pc(char('0' + min_integer % 10));
}


//Process
void Preps()
{
    pw = dp = pow10 = vi(18, 0LL);      //pw[i]: Number of integer from 1 w/ size i less than 10^i
    pw[1] = dp[1] = 9LL;                //dp[i]: Total size of string t = "0" + "1" + "2" + ... + "10^i-1"
    pow10[0] = 1LL;                     //dp[i]: Total size of string t = "0" + "1" + "2" + ... + "10^i-1"

    FORl(i, 2, 17)  pw[i] = pw[i-1] * 10;
    FORl(i, 2, 17)  dp[i] = dp[i-1] + pw[i] * i;
    FORl(i, 1, 17)  pow10[i] = pow10[i-1] * 10LL;


//    FOR(i, 1, 17) cerr << pw[i] << sp; cerr << el;
//    FOR(i, 1, 17) cerr << dp[i] << sp; cerr << el;
//    FOR(i, 1, 17) cerr << pow10[i] << sp; cerr << el;

}
void MULTi()
{
    scan(nTest);
    while(nTest--)
    {
        Solve();
    }
}


//Main Procedure
int main()
{
    FileInit();
    Preps();
    cerr << getLength(105);

    MULTi();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
