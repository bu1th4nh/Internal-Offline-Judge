/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <ratio>
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
#endif // __cplusplus

using namespace std;


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task ""
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Typedefs
struct Fraction
{
    typedef long long ll;

    ll num, den;       //Numeric - Denomination

    ~Fraction() {}

    Fraction(): num(0LL), den(1LL) {}
    Fraction(ll n, ll d)
    {
        ll p = __gcd(n, d);
        num = n / p;
        den = d / p;
    }


    void normalize(Fraction &f)
    {
        ll p = __gcd(f.num, f.den);
        f.num /= p;
        f.den /= p;
    }
    void divide_2()
    {
        if(this->num % 2 == 0) this->num /= 2LL;
        else this->den *= 2LL;
    }
    Fraction& operator += (const Fraction &other)
    {
        Fraction ret;
        ll xd = this->den, yd = other.den;
        ll xn = this->num, yn = other.num;

        ret.den = xd * yd / __gcd(xd, yd);
        ret.num = (ret.den / xd) * xn + (ret.den / yd) * yn;
        normalize(ret);


        *this = ret;
    }
    Fraction& operator -= (const Fraction &other)
    {
        Fraction ret;
        ll xd = this->den, yd = other.den;
        ll xn = this->num, yn = other.num;

        ret.den = xd * yd / __gcd(xd, yd);
        ret.num = (ret.den / xd) * xn - (ret.den / yd) * yn;
        normalize(ret);

        *this = ret;
    }
    bool operator< (const Fraction &other) const
    {
        ll xd = this->den, yd = other.den;
        ll xn = this->num, yn = other.num;

        ll p = xd * yd / __gcd(xd, yd);

        return (p / xd) * xn < (p / yd) * yn;
    }
    bool operator> (const Fraction &other) const
    {
        ll xd = this->den, yd = other.den;
        ll xn = this->num, yn = other.num;

        ll p = xd * yd / __gcd(xd, yd);

        return (p / xd) * xn > (p / yd) * yn;
    }


};
Fraction m1(const Fraction& f)
{
    return Fraction(f.den - f.num, f.num);
}

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
int n;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    FILEOP_DEBUG()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Main Procedure
int main()
{
    string t;
    char c, str[1048576];
    scanf("%d", &n);
    scanf("%s", &str); t = ' ' + string(str);

    int nM = 0, nH = 0;
    FOR(i, 1, n-1)
    {
        if(t[i] == 'M') ++nM;
        else ++nH;
    }

    if(nM > nH) cout << "M";
    else if(nM < nH) cout << "H";
    else
    {
        if(n == 1)
        {
            cout << "HM";
            return 0;
        }
        puts((t[n-1] == 'M') ? "H" : "M");
    }

    return 0;
}
