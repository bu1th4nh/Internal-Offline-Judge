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
#define task "FARRAY2D"
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
vi vect, argmin, valmin;
vi best_y_per_x;
int n, m;
vvi ps;
ll s;

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
    scan(m);
    scan(s);

    vect = argmin = valmin = vi(m+3, 0LL);
    ps = vvi(n+1, vi(m+1, 0LL));


    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            scan(ps[i][j]);
            ps[i][j] += ps[i-1][j];
        }
    }
}

//Check
void Bruteforce()
{
    ii coord_res_1, coord_res_2;
    int lenX = 0, lenY = 0;
    int maxArea = -1;

    FOR(i1, 1, n) FOR(i2, i1, n)
    {
        FOR(j, 1, m) vect[j] = ps[i2][j] - ps[i1-1][j] + vect[j-1];

        valmin[m] = vect[m]+99999;
        argmin[m] = m+99999;
        FORb(i, m-1, 1) valmin[i] = (i == m-1) ? vect[i] : (vect[i+1] < valmin[i+1]) ? vect[i+1] : valmin[i+1];
        FORb(i, m-1, 1) argmin[i] = (i == m-1) ?    m    : (vect[i+1] < valmin[i+1]) ?    i+1    : argmin[i+1];

        cerr << el;
        FOR(i, 1, m) cerr << vect[i] << sp; cerr << el;
        FOR(i, 1, m) cerr << valmin[i] << sp; cerr << el;
        FOR(i, 1, m) cerr << argmin[i] << sp; cerr << el;
        cerr << el;

        int p = 1;
        FOR(j, 1, n)
        {
            while(p < j && p < m-1) p = argmin[p];
            if(vect[p]-vect[j-1] <= s && maxArea < (i2-i1+1)*(p-j+1))
            {
                maxArea = (i2-i1+1)*(p-j+1);
                coord_res_1 = ii(i1, j);
                coord_res_2 = ii(i2, p);
            }
        }
    }

    cout << maxArea << el;
    if(maxArea > 0)
    {
        cout << coord_res_1.fi << sp << coord_res_1.se << sp << coord_res_2.fi << sp << coord_res_2.se << el;
    }
}

//Main Procedure
int main()
{
    //FileInit();
    Enter();
    Bruteforce();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
