//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
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
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "fibseq"
#define fi first
#define se second
#define maxinp (int)()
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
int mod, n;
int nTest;
ll st;



//=====================================
//Matrix Class
#define SIZE 10

template <class _T>
class Matrix
{
public:

    _T a[SIZE][SIZE];
    int m, n;

    _T* operator[] (int i)
    {
        return a[i];
    }
    const _T* operator[] (int i) const
    {
        return a[i];
    }

    void clear(int M, int N)
    {
        m = M, n = N;
        int i, j;
        for(i=1; i<=m; ++i) for (j=1; j<=n; j++) a[i][j]=0;
    }

    void operator = (const Matrix &A);

    Matrix(int M, int N)
    {
        clear(M, N);
    }
    Matrix(int M, int N, vector<_T> &_V, int start = 0, bool IsLim = false, int stop = 0)
    {
        if(!IsLim) stop = ((int)_V.size()-1);
        clear(M, N);
        int ptr = start;
        FOR(i, 1, M)
        {
            FOR(j, 1, N)
            {
                a[i][j] = _V[ptr];
                if(ptr == stop) break;
                else ++ptr;
            }
            if(ptr == stop) break;
        }
    }

};

template <class _T> Matrix<_T>
basedMatrix(int n)
{
    Matrix <_T> R(n, n);
    FOR(i, 1, n) R[i][i] = 1;
    return R;
}

template <class _T> Matrix<_T>
operator *(const Matrix<_T> &A, const Matrix<_T> &B)
{
    Matrix<_T> C(A.m, B.n);
    FOR(i, 1, A.m)
    {
        FOR(j, 1, B.n)
        {
            FOR(k, 1, A.n)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

template <class _T> Matrix<_T>
operator ^ (const Matrix<_T> &A, ll k)
{
    if(k==0) return basedMatrix<_T> (A.n);
    if(k==1) return A;
    Matrix<_T> p = A^(k/2);
    p = p*p;
    if(k&1) return p*A;
    else return p;
}

template <class _T> void Matrix<_T> ::
operator = (const Matrix<_T> &A)
{
    FOR(i, 1, A.m)
    {
        FOR(j, 1, A.n)
        {
            a[i][j] = A[i][j];
        }
    }
    m = A.m, n = A.n;
}

int Fibonacci(ll __n)
{
    __n--;
    vector<int> sample = {1, 1, 1, 0};
    Matrix<int> A(2, 2, sample);
    A = A^__n;
    return (A[1][1]%mod);
}

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d %lld %d", &n, &st, &mod);
}

//Subtask 1+4
int GetBit(int k, int x)
{
    return ((x >> (k-1)) & 1);
}
void sub14()
{
    vi fibo;
    vll res2;
    for(ll i = st; i<=st+n+1; ++i) fibo.push_back(Fibonacci(i));
    int lim = ((1 << n) - 1);
    FOR(i, 1, lim)
    {
        int tmp = 0;
        FOR(j, 0, n)
        {
            tmp += (fibo[j]*GetBit(j, i));
            tmp %= mod;
        }
        if(!tmp)
        {
            FOR(j, 0, n)
            {
                if(GetBit(j, i) == 1) res2.push_back(1LL*(j+st));
            }
            printf("%d ", res2.size());
            FORl(j, 0, (res2.size())) printf("%lld ", res2[j]);
            printf("\n");
            return;
        }
    }
    printf("0\n");

}

//Subtask 2+3+5



//Output
void Solve()
{
    if(n <= 20) sub14();
    //Sub25();
}
void Multitest()
{
    Enter();
    Solve();
}


//Main Procedure
int main()
{
    freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);
    scanf("%d", &nTest);
    while(nTest--)
    {
        Multitest();
    }
    return 0;
}
