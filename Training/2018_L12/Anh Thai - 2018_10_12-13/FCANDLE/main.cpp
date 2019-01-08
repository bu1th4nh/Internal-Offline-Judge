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
#include <cassert>
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
#define task "FCANDLE"
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


const long long mod = 1000000000;
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int nTest;
vvi C;
vi dp;

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
inline ll readInt()
{
    ll ret = 0LL;
    bool neg = 0;
    char c = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    return neg ? -ret : ret;
}

//Process
void Preps()
{
    C = vvi(5120, vi(5120, 0LL));
    dp = vi(5120, 0LL);

    C[0][0] = 1LL;
    C[1][1] = 1LL;
    C[0][1] = 1LL;
    FOR(n, 1, 5000)
    {
        C[0][n] = C[n][n] = 1LL;
        FOR(k, 1, n) C[k][n] = (C[k-1][n-1] + C[k][n-1]) % mod;
    }

//    FOR(n, 1, 10)
//    {
//        FOR(k, 0, 10) cerr << C[k][n] << sp; cerr << el;
//    }

    dp[0] = dp[1] = 1LL;

    FOR(n, 2, 5000)
    {
        FOR(i, 1, n) if(i % 2 == 0)
        {
            //assert(i-1 <= n-i);

            //cerr << C[i-1][n-i] << el;

            dp[n] += 1LL * C[i-1][n-1] * ((dp[i-1] * dp[n-i]) % mod);
            dp[n] %= mod;
        }

//        cerr << dp[n] ;
//        getchar();
    }
}


//Output
void Solve()
{
    int n;
    nTest = readInt();
    while(nTest--)
    {
        string s = to_string(dp[readInt()]);
        s = string(9 - (int)s.size(), '0') + s;
        printf("%s\n", s.c_str());
    }
}



//Main Procedure
int main()
{
    FileInit();
    Preps();
    Solve();
    return 0;
}
