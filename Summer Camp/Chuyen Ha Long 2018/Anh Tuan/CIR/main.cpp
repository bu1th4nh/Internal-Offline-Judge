/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*
        F[u][v][i] = max(F[u][k][i-1] + F[k][v][i-1], all k) : Longest path from u->v along 2^i edges



        g[u][v][i] = Longest path from u to v along first i bit of K edges
                if i-th bit of k = 0: g[u][v][i] = g[u][v][i-1]
                if i-th bit of k = 1: g[u][v][i] = max(g[u][k][i-1] + f[k][v][i]), w/ all k of V


        ---> Matrix Multiplication: Example: K = 2^0 + 2^2 + 2^3, then m = m0 + m2 + m3

*/

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
#define task "CIR"
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


const long long inf = 1234567890;
//=====================================
//Matrices
struct Matrix
{
    typedef long long ll;
    typedef vector<ll> vi;
    typedef vector<vi> vvi;

    vvi F;
    int n;

    Matrix() {}
    Matrix(int __n, bool idMatrix = false)
    {
        n = __n;
        F = vvi(__n+10, vi(__n+10, -inf));
    }
    Matrix operator * (const Matrix &oth)
    {
        Matrix ret(n);
        FOR(i, 1, n)
        {
            FOR(j, 1, n)
            {
                FOR(k, 1, n)
                {
                    ret.F[i][j] = max(ret.F[i][j], this->F[i][k] + oth.F[k][j]);
                }
            }
        }

        return ret;
    }


};



//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<Matrix> vm;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
int n, m, kar;
ll res;
vm DP;


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

//Enter
void Enter()
{
    ll c;
    int u, v;
	scanf("%d%d%d", &n, &m, &kar);

	DP = vm(33, Matrix(n, false));

	FOR(i, 1, m)
	{
	    scanf("%d%d%lld", &u, &v, &c);
	    DP[0].F[u][v] = max(DP[0].F[u][v], c);
	}
}

//Process
void Solve()
{
    int start;
    Matrix A(n);
    bitset<33> kar98k(kar);

    res = -inf;
    FOR(i, 1, 32) DP[i] = DP[i-1] * DP[i-1];
    FOR(i, 0, 32) if(kar98k.test(i))
    {
        start = i;
        A = DP[i];
        break;
    }
    FOR(i, start + 1, 32) if(kar98k.test(i)) A = A * DP[i];
    FOR(i, 1, n)  res = max(res, A.F[i][i]);

    cout << res << el;
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
