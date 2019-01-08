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
#define task "PERGAME"
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
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ll res1, res2, res;
vi vect, a;
int n;

//=====================================
//Functions and procedures1
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
	res1 = res2 = res = 0LL;
	vect = vi(n+1, 0);
	FOR(i, 1, n) scan(vect[i]);
}

//Process
void Case1()
{
	a = vect;
    FOR(i, 2, n) if(a[i] == n / 2 + 1) { swap(a[i], a[1]); ++res1; break; }
    FORb(i, n-1,  1) if(a[i] == n / 2) { swap(a[i], a[n]); ++res1; break; }

    while(true)            //Numbers in small group go to even position.
    {
        FOR(i, 2, n-1)
        {
            if(a[i] > n / 2 && i % 2 == 0)
            {
                FOR(j, i+1, n-1) if(a[j] <= n / 2 && j & 1)     { swap(a[i], a[j]); ++res1; break; }
            }
            else if(a[i] <= n / 2 && i & 1)
            {
                FOR(j, i+1, n-1) if(a[j] > n / 2 && j % 2 == 0) { swap(a[i], a[j]); ++res1; break; }
            }

            //FOR(j, 1, n) cerr << a[j] << sp; cerr << el;
            //getchar();
        }

        bool ok = 1;
        FOR(i, 1, n)
        {
            if(!((a[i] <= n / 2 && i % 2 == 0) || (a[i] > n / 2 && i & 1)))
            {
                ok = 0;
                break;
            }
        }
        if(ok) break;
    }

    //cout << res1 << el;
}
void Case2()
{
	a = vect;    FOR(i, 2, n)   if(a[i] == n / 2)     { swap(a[i], a[1]); ++res2; break; }
    FORb(i, n-1,1) if(a[i] == n / 2 + 1) { swap(a[i], a[n]); ++res2; break; }

    while(true)            //Numbers in big group go to even position.
    {
        FOR(i, 2, n-1)
        {
            if(a[i] <= n / 2 && i % 2 == 0)
            {
                FOR(j, i+1, n-1) if(a[j] > n / 2 && j & 1)     { swap(a[i], a[j]); ++res2; break; }
            }
            else if(a[i] > n / 2 && i & 1)
            {
                FOR(j, i+1, n-1) if(a[j] <= n / 2 && j % 2 == 0) { swap(a[i], a[j]); ++res2; break; }
            }

            //FOR(j, 1, n) cerr << a[j] << sp; cerr << el;
            //getchar();
        }

        bool ok = 1;
        FOR(i, 1, n)
        {
            if(!((a[i] > n / 2 && i % 2 == 0) || (a[i] <= n / 2 && i & 1)))
            {
                ok = 0;
                break;
            }
        }
        if(ok) break;
    }

    //cout << res2 << el;
}

//Output
void Solve()
{
    Case1();
    Case2();
    res = min(res1, res2);
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
