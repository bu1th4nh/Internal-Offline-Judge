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
#define task "FIBSEQ"
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
template<class T> class Matrix
{
public:

    typedef vector<T> vt;
    typedef vector<vt> vvt;

    vvt a;
    int m, n;
    long long mod;


    //Initialization
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

        FOR(i, 1, n) a[i][i] = (T)1;
    }

    //Constructors
    Matrix(long long __mod, int __m, int __n, const vvt &__a)
    {
        mod = __mod;
        a = __a;
        n = __n;
        m = __m;
    }
    Matrix(long long __mod, int __m, int __n)
    {
        mod = __mod;
        initialize(__m, __n);
    }
    Matrix(long long __mod, int __n)
    {
        mod = __mod;
        identity_matrix(__n);
    }
    Matrix() {}


    //Operators
    void operator= (const Matrix<T> &x)
    {
        mod = x.mod;
        a = x.a;
        m = x.m;
        n = x.n;
    }
    vt& operator[] (int i)
    {
        return a[i];
    }
    Matrix<T> operator * (const Matrix<T> &other)
    {
        Matrix<T> ret(mod, this->m, other.n);
        FOR(i, 1, this->m)
        {
            FOR(j, 1, other.n)
            {
                FOR(k, 1, this->n)
                {
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * other.a[k][j]) % mod;
                }
            }
        }
        return ret;
    }
    Matrix<T> operator ^ (long long k)
    {
        Matrix<T> ret(mod, this->n);
        Matrix<T> a = *this;

        if(k == 0) return Matrix(mod, this->n);
        FOR(i, 0, 63)
        {
            if((k >> i) & 1 == 1) ret = ret * a;
            a = a * a;
        }

        return ret;
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<vii> vvii;
int nTest;

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
void debugFibonacci()
{
    Matrix<ll> A(1000000007, 5, 5);
    Matrix<ll> B(1000000007, 5, 5);

    A[1][1] = 1;
    A[2][1] = 0;

    B[1] = {0, 1, 1, 0, 0};
    B[2] = {0, 1, 0, 0, 0};

    FOR(n, 1, 500)
    {
        int m = n-1;
        Matrix<ll> C = A * (B ^ m);

        //cerr << "F[" << n << "] = " << C[1][1] << el ;
    }
}
template<class T> inline void scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret *= neg ? -1 : 1;
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


//Check
void sub_1_4(int n, ll from, ll div_by)
{
    //Fibonacci Generator in nlog(k)
    vll fib;

    Matrix<ll> A(div_by, 2, 2);
    A[1] = {0, 1, 0};

    Matrix<ll> B(div_by, 2, 2);
    B[1] = {0, 1, 1};
    B[2] = {0, 1, 0};

    FORl(i, 0, n)
    {
        Matrix<ll> C = A * (B ^ (i + from - 1));
        fib.push_back(C[1][1]);

        //cerr << fib.back() << el;
    }

    //Generate all configurations
    FORl(state, 1, (1 << n))
    {
        vi smp;
        ll s = 0LL;

        FORl(i, 0, n) if((state >> i) & 1 == 1) smp.push_back(i);
        for(int x: smp) s = (s + fib[x]) % div_by;

        if(s == 0)
        {
            print(smp.size()); putchar(' ');
            for(int x: smp)
            {
                print(ll(from + x));
                putchar(' ');
            }
            putchar('\n');
            return;
        }
    }
}
void sub_2_5(int n, ll from, ll div_by)
{
    //Fibonacci Generator in nlog(k)
    vll fib(1, 0LL);
    vll ps(n+1, 0LL);

    Matrix<ll> A(div_by, 2, 2);
    A[1] = {0, 1, 0};

    Matrix<ll> B(div_by, 2, 2);
    B[1] = {0, 1, 1};
    B[2] = {0, 1, 0};

    FORl(i, 0, n)
    {
        Matrix<ll> C = A * (B ^ (i + from - 1));
        fib.push_back(C[1][1]);

        //cerr << fib.back() << el;
    }

    //Prefix Sum
    FOR(i, 1, n) ps[i] = (ps[i-1] + fib[i]);
    FOR(i, 1, n)
    {
        FOR(j, i, n) if((ps[j] - ps[i-1]) % div_by == 0)
        {
            print(j - i + 1); putchar(' ');
            FOR(k, i, j)
            {
                print(k + from - 1); putchar(' ');
            }
            putchar('\n');
            return;
        }
    }
}


//Process
void final_subtask(int n, ll from, ll div_by)
{
    //Fibonacci Generator in nlog(k)
    vll fib(n+1, 0LL);
    vll ps(n+1, 0LL);

    Matrix<ll> A(div_by, 2, 2);
    A[1] = {0, 1, 0};

    Matrix<ll> B(div_by, 2, 2);
    B[1] = {0, 1, 1};
    B[2] = {0, 1, 0};

    FORl(i, 0, min(n, 3))
    {
        Matrix<ll> C = A * (B ^ (i + from - 1));
        fib[i+1] = (C[1][1]);
    }

    FOR(i, 4, n) fib[i] = (fib[i-1] + fib[i-2]) % div_by;
    FOR(i, 1, n) ps[i] = (ps[i-1] + fib[i]) % div_by;

    //Find the contiguous sequence (i, j) which ps[j] % div == ps[i-1] % div.
    vi idx(div_by+2, -1);
    FOR(i, 0, n+1)
    {
        if(idx[ps[i]] < 0) idx[ps[i]] = i;
        else
        {
            int j = idx[ps[i]];

            print(i - j); putchar(' ');
            FOR(k, j+1, i)
            {
                print(k + from - 1); putchar(' ');
            }
            putchar('\n');
            return;
        }
    }
}


//Output
void Solve()
{
    int n;
    ll from, div_by;

    scan(nTest);
    while(nTest--)
    {
        scan(n);
        scan(from);
        scan(div_by);

        final_subtask(n, from, div_by);
    }
}



//Main Procedure
int main()
{
    FileInit();
    Solve();
    return 0;
}
