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
#define task "RECT"
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
        return (T)1 * __X * __X;
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
namespace Geometry
{
    typedef long long ll;
    typedef complex<ll> pt;

    #define x real()
    #define y imag()

    ll operator| (const pt &a, const pt &b)
    {
        return (conj(a) * b).x;
    }
    ll operator^ (const pt &a, const pt &b)
    {
        return (conj(a) * b).y;
    }
}
using namespace Geometry;
struct diagonal
{
    typedef long long ll;
    typedef complex<ll> pt;

    pt midpoint;
    pt vct;
    ll len;

    diagonal() {}
    diagonal(pt p1, pt p2)
    {
        if(p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y)) swap(p1, p2);

        vct = p1 - p2;
        midpoint = p1 + p2;
        len = __sqr(vct.x) + __sqr(vct.y);
    }

    bool operator< (const diagonal &other) const
    {
        tuple<ll, ll, ll> t1(this->midpoint.x, this->midpoint.y, this->len);
        tuple<ll, ll, ll> t2(other.midpoint.x, other.midpoint.y, other.len);

        return t1 < t2 || (t1 == t2 && (this->vct ^ other.vct) > 0);
    }
    bool operator== (const diagonal &other) const
    {
        return this->midpoint == other.midpoint;
    }
};

//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<diagonal> vd;
typedef complex<ll> pt;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pt> vpt;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vpt vect;
vd data;
ll res;
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
    int u, v;
	scan(n);

	vect = vpt(n+1);
	res = 0LL;

	FOR(i, 1, n)
	{
	    scan(u);
	    scan(v);

	    vect[i] = pt(u, v);
	}
}


//Process
void Solve()
{
    FOR(i, 1, n)
    {
        FOR(j, i+1, n) data.push_back(diagonal(vect[i], vect[j]));
    }
    sort(whole(data));

    int j = 0, m = data.size();
    FORl(i, 0, m)
    {
        if(j <= i) j = i + 1;
        while(j <= m && data[i] == data[j] && (data[i].vct | data[i].vct) >= 0) ++j;

        if(j != i + 1) maximize(res, data[i].vct ^ data[j-1].vct);
        if(j < m && data[i] == data[j]) maximize(res, data[i].vct ^ data[j-1].vct);
    }

    print(res >> 1);
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
