/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*
        Matrix:
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
#define task "KREACH"
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
//Class libraries
struct matrix
{
    typedef bitset<128> bs;
    typedef vector<bs> vbs;

    vbs T;
    int n;

    matrix(int __n)
    {
        n = __n;
        T = vbs(n+5, bs(0));
    }

    matrix operator * (const matrix &other)
    {
        matrix ret(n);

        FOR(i, 1, n) FOR(j, 1, n)
        {
            if(this->T[i].test(j)) ret.T[i] |= other.T[j];
        }

        return ret;
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<matrix> vm;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int m, n, nQuery;
vm F;


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
    int u, v;
    scanf("%d%d", &n, &m);
    F = vm(33, matrix(n));

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        F[0].T[u].set(v, 1);
    }

    FOR(i, 1, 32) F[i] = F[i-1] * F[i-1];
}

//Check
void Query()
{
    int u, k;
    scanf("%d%d", &u, &k);

    int id;
    matrix res(n);

    FORl(i, 0, 32)
    {
        if((k >> i) & 1)
        {
            id = i;
            res = F[i];
            break;
        }
    }

    FORl(i, id+1, 32)
    {
        if((k >> i) & 1)
        {
            res = res * F[i];
        }
    }
    cout << res.T[u].count() << el;
}



//Process
void Solve()
{
    scanf("%d", &nQuery);
    while(nQuery--) Query();
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
