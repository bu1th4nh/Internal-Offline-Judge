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
#define task "PROD"
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
template<int BASE_DIGITS = 9, int BASE = 1000000000> struct BigInt
{
    typedef long long ll;

    vector<int> a;
    int sign;

    //------------------------- Copy operators -------------------------//
    BigInt& operator = (ll v)
    {
        sign = 1;
        a.clear();
        if(v < 0) sign = -1, v = -v;

        for(; v > 0; v /= BASE) a.push_back(v % BASE);
        return *this;
    }

    //----------------------------- Misc -------------------------------//
    void trim()
    {
        while(!a.empty() && !a.back()) a.pop_back();
        if(a.empty()) sign = 1;
    }
    bool isZero() const
    {
        return a.empty() || (a.size() == 1 && !a[0]);
    }


    //------------------------- Input / Output -------------------------//
    void read(const string &s)
    {
        sign = 1;
        a.clear();

        int pos = 0;
        while(pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+'))
        {
            if(s[pos] == '-') sign = -sign;
            ++pos;
        }
        for(int i = s.size()-1; i >= pos; i -= BASE_DIGITS)
        {
            int x = 0;
            for(int j = max(pos, i - BASE_DIGITS + 1); j <= i; ++j) x = x * 10 + s[j] - '0';
            a.push_back(x);
        }

        trim();
    }
    friend istream operator>> (istream &stream, const BigInt &v)
    {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
    friend ostream& operator<< (ostream &stream, const BigInt &v)
    {
        if(v.sign == -1 && !v.isZero()) stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for(int i = (int)v.a.size() - 2; i >= 0; --i) stream << setw(BASE_DIGITS) << setfill('0') << v.a[i];
        return stream;
    }

    //--------------------------- Comparison ---------------------------//
    bool operator< (const BigInt &v) const
    {
        if(sign != v.sign) return sign < v.sign;
        if(a.size() != v.a.size()) return a.size() * sign < v.a.size() * v.sign;
        for(int i = (int)a.size() - 1; i >= 0; --i)
        {
            if(a[i] != v.a[i]) return a[i] * sign < v.a[i] * v.sign;
        }
        return 0;
    }
    bool operator>  (const BigInt &v) const { return v < *this; }
    bool operator<= (const BigInt &v) const { return !(v > *this); }
    bool operator>= (const BigInt &v) const { return !(*this < v); }
    bool operator== (const BigInt &v) const { return !(*this < v) && !(v < *this);}
    bool operator!= (const BigInt &v) const { return (*this < v)  ||  (v < *this);}

    //------------------ Constructors and destructors ------------------//
    BigInt(): sign(1) { /**< \brief Default constructor */ }
    BigInt(ll v)
    {
        /**< \brief Constructor from long long */
        *this = v;
    }
    BigInt(const string &s)
    {
        /**< \brief Constructor from string */
        read(s);
    }


    //---------------------------- Operators ---------------------------//
    BigInt operator-() const
    {
        BigInt res = *this;
        if(isZero()) return res;
        res.sign = -sign;
        return res;
    }


    BigInt operator * (const BigInt &v) const
    {
        BigInt res;
        res.sign = sign * v.sign;
        res.a.resize(a.size() + v.a.size());

        FORl(i, 0, (int)a.size()) if(a[i])
        {
            for(int j = 0, carry = 0; j <= (int)v.a.size() || carry; ++j)
            {
                ll cur      = res.a[i+j] + 1LL * a[i] * (j < (int)v.a.size() ? v.a[j] : 0) + carry;
                carry       = (int) (cur / BASE);
                res.a[i+j]  = (int) (cur % BASE);
            }
        }

        res.trim();
        return res;
    }
    void operator*= (const BigInt &v) const
    {
        *this = *this * v;
    }
};


//=====================================
//Typedefs
typedef BigInt<> bi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<bi> vbi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vbi> vvbi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef vector<vvbi> vvvbi;
int m, n, k;
vvvi a;
bi res;

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
    ll u;
	scan(k);
	scan(m);
	scan(n);

	a = vvvi(k+1, vvi(m+1, vi(n+1, 0LL)));
	FOR(i, 1, k)
	{
	    FOR(j, 1, m)
	    {
	        FOR(t, 1, n)
            {
                scan(a[i][j][t]);
            }
	    }
	}
}

//Process
bi Parse(int x1, int y1, int x2, int y2)
{
    ll tmp = 0LL;

    ll mx1 = 1LL * a[1][x1][y1] * a[1][x1][y2] * a[1][x2][y1] * a[1][x2][y2];
    ll mx2 = 1LL * a[2][x1][y1] * a[2][x1][y2] * a[2][x2][y1] * a[2][x2][y2];
    ll mn1 = 1LL * a[1][x1][y1] * a[1][x1][y2] * a[1][x2][y1] * a[1][x2][y2];
    ll mn2 = 1LL * a[2][x1][y1] * a[2][x1][y2] * a[2][x2][y1] * a[2][x2][y2];

//    cerr << mx1 << el;


    if(mx1 < mx2) swap(mx1, mx2);
    if(mn1 > mn2) swap(mn1, mn2);

    FOR(i, 3, k)
    {
        tmp = a[i][x1][y1] * a[i][x1][y2] * a[i][x2][y1] * a[i][x2][y2];
        if(tmp > mx1)
        {
            mx2 = mx1;
            mx1 = tmp;
        }
        else maximize(mx2, tmp);
        if(tmp < mn1)
        {
            mn2 = mn1;
            mn1 = tmp;
        }
        else minimize(mn2, tmp);
    }

    bi xx1 = mx1;bi xx2 = mx2;
    bi nn1 = mn1;bi nn2 = mn2;

    return max(xx1 * xx2, nn1 * nn2);
}
void Solve()
{
    res = BigInt<>(0);
    FOR(x1, 1, m)
    {
        FOR(x2, x1+1, m)
        {
            FOR(y1, 1, n)
            {
                FOR(y2, y1+1, n)
                {
                    maximize(res, Parse(x1, y1, x2, y2));
                }
            }
        }
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
