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
#define task "ARCHER"
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
    template<class T> T __abs(T x)
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
template<class T> struct point
{
    T x, y, z;

    point() {}
    point(T __x, T __y): x(__x), y(__y) {}
    point(T __x, T __y, T __z): x(__x), y(__y), z(__z) {}

    bool operator< (const point<T> &other) const
    {
        return make_tuple(this->x, this->y, this->z) < make_tuple(other.x, other.y, other.z);
    }
    point<T> operator- (const point<T> &other) const
    {
        return point<T>(this->x - other.x,
                     this->y - other.y,
                     this->z - other.z);
    }
    point<T> operator+ (const point<T> &other) const
    {
        return point<T>(this->x + other.x,
                     this->y + other.y,
                     this->z + other.z);
    }
    point<T> operator* (const T &multiplier)
    {
        return point<T>(this->x * multiplier,
                     this->y * multiplier,
                     this->z * multiplier);
    }
    T operator% (const point<T> &other)
    {
        return this->x * other.x + this->y * other.y + this->z * other.z;
    }
    void operator= (const point<T> oth)
    {
        x = oth.x;
        y = oth.y;
        z = oth.z;
    }
    void refine()
    {
        T p = __gcd(__abs(x), __gcd(__abs(y), __abs(z)));
        x /= p;
        y /= p;
        z /= p;
    }
    void invert()
    {
        x *= -1;
        y *= -1;
        z *= -1;
    }
    bool zero()
    {
        return x == 0 && y == 0 && z == 0;
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef point<int> pti;
typedef pair<int, int> ii;
typedef vector<pti> vp;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vvi label;
int n;
vp a;

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
    int x, y, z;

	scan(n);
	a = vp(n+1);
	label = vvi(n+1, vi(n+1, -1));

	FOR(i, 1, n)
	{
	    scan(x);
	    scan(y);
	    scan(z);

	    a[i] = pti(x, y, z);
	}
	sort(whole_1(a));
}

//Process
void Solve()
{
    int res = 0, cz = 0, tp = 0;

    FOR(i, 1, n)
    {
        cz = 0, tp = 0;
        map<pti, int> mp;
        FOR(j, i, n)
        {
            pti A = a[j] - a[i];
            if(A.zero())
            {
                ++cz;
                continue;
            }
            else if(A.z == 0) continue;
            else
            {
                A.refine();
                if(A.z < 0) A.invert();

                ++mp[A];
            }
        }

        for(auto x: mp) maximize(tp, x.se);
        maximize(res, tp + cz);
    }

    cout << res << el;
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
