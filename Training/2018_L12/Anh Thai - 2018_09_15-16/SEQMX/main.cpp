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
#define task "SEQMX"
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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ld, int> ldi;
typedef vector<bool> vb;
typedef vector<ld> vld;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ll res1, res2;
ld ressss;
int n, k;
vi a, ps;

//=====================================
//Functions and procedures
//Initialization and preparation
void LiveToday()
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
void LoveTomorrow()
{
    scanf("%d%d", &n, &k);

    res1 = 1LL;
    res2 = 1LL;
    a = ps = vi(n+1, 0LL);

    FOR(i, 1, n) scanf("%lld", &a[i]), ps[i] = a[i] + ps[i-1];
}

//Check
void S1()
{
    FOR(i, 1, n)
    {
        FOR(j, i+k-1, n)
        {
            if(1LL * res2 * (ps[j] - ps[i-1]) > 1LL * res1 * (j - i + 1))
            {
                res1 = ps[j] - ps[i-1];
                res2 = j - i + 1;
            }
        }
    }

    ressss = (1.0 * (res1) / (res2));
    cout << fixed << setprecision(5) << ressss << el;
}



//Process
bool find(ld query)
{
    int j = 0;
    ld tmp = 0.00000000;
    vld F(n+1, 0.0000);

    FOR(i, 1, n)
    {
        tmp = (ld)ps[i] - query * i;
        F[i] = (tmp < F[i-1]) ? tmp : F[i-1];
    }

    FOR(i, k, n)
    {
        tmp = (ld)ps[i] - query * i;
        if(tmp >= F[i-k]) return 1;
    }

    return 0;
}
void UniteForever()
{
    ld L = -1e15, R = 1e15, M = 0.000;
    while(R - L > 1e-10)
    {
        //cerr  << fixed << setprecision(15) << L << sp << M << sp << R << el;

        M = (L + R) / 2.000000;
        if(find(M)) L = M, ressss = M;
        else R = M;
    }
    cout << fixed << setprecision(5) << ressss << el;
}


//Main Procedure
int main()
{
    //LiveToday();
    LoveTomorrow();
    UniteForever();
    return 0;
}
