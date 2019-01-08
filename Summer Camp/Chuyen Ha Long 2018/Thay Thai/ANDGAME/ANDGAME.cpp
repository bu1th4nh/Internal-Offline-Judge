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
#define task "ANDGAME"
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


const long long mod = 1000000007;
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
int n, k;
vi a, b;
vvi C;


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
	scanf("%d", &n);
	a = b = vi(n+1, 0LL);

	FOR(i, 1, n) scanf("%lld", &a[i]), b[i] = __builtin_popcountll(a[i]);
}

//Check
void Preps()
{
    C = vvi(100, vi(100, 0LL));
    FOR(i, 0, 66) C[i][i] = C[i][0] = 1LL;
    FOR(i, 1, 64)
    {
        FORl(j, 1, i)
        {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
}
void Solve()
{
    ll res = 0LL;
    ll nim_sum = 0LL;

    FOR(i, 1, n) nim_sum ^= b[i];

    FOR(i, 1, n)
    {
        ll k = (b[i]) - (b[i] ^ nim_sum);
        if(k > 0) res = (res + 1LL * C[b[i]][k] * ((1LL << (63 - b[i])) % mod)) % mod;
    }

    cout << res << el;
}


//Main Procedure
int main()
{
    FileInit();
    Preps();
    Enter();
    Solve();
    return 0;
}
