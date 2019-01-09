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
#define task "BALLGMVN"
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
typedef complex<int> pt;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pt> vpt;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vpt a, b;
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

#define x real()
#define y imag()


//Enter
void Enter()
{
    int u, v;
    scan(n);
    a = b = vpt(1);
    FOR(i, 1, n)
    {
        scan(u);
        scan(v);

        a.emplace_back(u, v);
    }
    FOR(i, 1, n)
    {
        scan(u);
        scan(v);

        b.emplace_back(u, v);
    }
}

//Subtask 1
void Subtask1()
{
    FOR(i, 1, n)
    {
        FOR(j, 1, n) if(i != j)
        {
            FOR(k, 1, n)
            {
                pt A = a[j] - a[i];
                pt B = b[k] - a[j];
                if((conj(A)*B).y == 0)
                {
                    cout << i << sp << j << sp << n+i << el;
                    return;
                }
            }
        }
    }
    a.swap(b);
    FOR(i, 1, n)
    {
        FOR(j, 1, n) if(i != j)
        {
            FOR(k, 1, n)
            {
                pt A = a[j] - a[i];
                pt B = b[k] - a[j];
                if((conj(A)*B).y == 0)
                {
                    cout << n+i << sp << n+j << sp << i << el;
                    return;
                }
            }
        }
    }
    puts("-1");
}

//Subtask 2: All the constraint
inline ll hashing(pt &p)
{
    return (1LL * p.x * 10000000LL + p.y);
}
bool Parse(vpt &src, vpt &dst, int shiftX, int shiftY)
{
    FOR(i, 1, n)
    {
        unordered_map<ll, ii> mp;
        FOR(j, i+1, n) if(i != j)
        {
            pt A = src[j] - src[i];
            if(A.x < 0) A *= -1;
            A /= __gcd(__abs(A.x), __abs(A.y));

            mp.emplace(hashing(A), ii(i + shiftX, j + shiftX));
        }

        FOR(j, 1, n)
        {
            pt A = dst[j] - src[i];
            A /= __gcd(__abs(A.x), __abs(A.y));
            ll hashValue = hashing(A);

            if(mp.count(hashValue))
            {
                cout << mp[hashValue].fi << sp << mp[hashValue].se << sp << j+shiftY << el;
                return 1;
            }
        }
    }
    return 0;
}
void Subtask2()
{
    if(Parse(a, b, 0, n)) return;
    if(Parse(b, a, n, 0)) return;
    puts("-1");
}

//Output
void Solve()
{
    if(n <= 200)  Subtask1();
    else Subtask2();
}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
