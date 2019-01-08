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
#define task "KFIB"
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
template<class T> struct Matrix
{
    typedef vector<T> vt;
    typedef vector<vt> vvt;

    vvt a;
    int m, n;
    T modulo;

    void initialize(int __m, int __n)
    {
        m = __m;
        n = __n;

        a = vvt(m+1, vt(n+1, T()));
    }
    void identity_matrix(int __n)
    {
        m = n = __n;
        a = vvt(n+1, vt(n+1, T()));

        FOR(i, 1, n) a[i][i] = T(1);
    }

    //Constructors
    Matrix(int __m, int __n, T __modulo)
    {
        modulo = __modulo;
        initialize(__m, __n);
    }
    Matrix(int __n, T __modulo)
    {
        modulo = __modulo;
        identity_matrix(__n);
    }
    Matrix() {}


    //Operators
    void operator= (const Matrix<T> &oth)
    {
        a = oth.a;
        m = oth.m;
        n = oth.n;
        modulo = oth.modulo;
    }
    vt& operator[] (int i)
    {
        return a[i];
    }
    Matrix<T> operator* (const Matrix<T> &other)
    {
        Matrix ret(this->m, other.n, modulo);
        FOR(i, 1, this->m)
        {
            FOR(j, 1, other.n)
            {
                FOR(k, 1, this->n)
                {
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * other.a[k][j]) % modulo;
                }
            }
        }
        return ret;
    }
    Matrix<T> operator ^ (long long k)
    {
        Matrix<T> ret(this->n, modulo);
        Matrix<T> xx = *this;

        FOR(i, 0, 35)
        {
            if((k >> i) & 1) ret = ret * xx;
            xx = xx * xx;
        }

        return ret;
    }
};

//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef map<ii, int> miii;
typedef Matrix<ll> mat;
ll ctb[131072];
int nTests;

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


//Subtask 1: mod <= 1e5
void Subtask1(ll a, ll b, ll mod)
{
    vll fibs(6*mod+10, 0LL); fibs[1] = 1 % mod;
    FOR(i, 2, 6*mod+1)
    {
        fibs[i] = (fibs[i-1] + fibs[i-2]) % mod;
    }
    FOR(i, 0, 6*mod) if(fibs[i] == a && fibs[i+1] == b)
    {
        print(i);
        putchar(el);
        return;
    }
    print(-1);
    putchar(el);
}

//Subtask 2: All the prob.
void Query(int a, int b, int mod)
{
    ii tmp;
    miii ctbers;
    int up_bound = sqrt(6LL * mod) + 1;

    ctb[0] = b, ctb[1] = a;
    FOR(i, 2, up_bound) ctb[i] = (ctb[i-2] - ctb[i-1] + mod) % mod;//, cerr << ctb[i] << sp; cerr << el;
    FORl(i, 0, up_bound)
    {
        if(ctbers.count(ii(ctb[i+1], ctb[i]))) break;
        ctbers[ii(ctb[i+1], ctb[i])] = i;
    }




//    cerr << up_bound << el;


    mat shifter, sampler, current, primals(2, 2, mod);
    primals[1][1] = primals[1][2] = primals[2][1] = 1;

    sampler = primals;
    shifter = primals ^ up_bound;


    FORl(i, 0, up_bound)
    {
        if(i == 0) tmp = ii(0, 1 % mod);
        else if(i == 1)
        {
            sampler = primals ^ (up_bound - 1);
            current = sampler * primals;

            tmp.fi = sampler[1][1] % mod;
            tmp.se = current[1][1] % mod;
        }
        else
        {
            sampler = sampler * shifter;
            current = sampler * primals;

            tmp.fi = sampler[1][1] % mod;
            tmp.se = current[1][1] % mod;
        }


        if(ctbers.find(tmp) != ctbers.end())
        {
            print(up_bound * i + ctbers[tmp]);
            putchar(el);
            return;
        }
    }
    putchar('-');
    putchar('1');
    putchar(el);
}



//Output
void Solve()
{
    ll a, b, mod;
    scan(nTests);
    while(nTests--)
    {
        scan(mod);
        scan(a);
        scan(b);

//        if(mod <= 1000000) Subtask1(a, b, mod);
//        else Query(a, b, mod);

        Query(a, b, mod);
    }
}



//Main Procedure
int main()
{
    FileInit();
    Solve();
    return 0;
}
/*
3
115295152 19830824 78140189
115295152 97971013 96787906
115295152 78140189 97971013
*/


//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
