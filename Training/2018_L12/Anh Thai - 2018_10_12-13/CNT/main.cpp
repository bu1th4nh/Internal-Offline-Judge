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
#define task "CNT"
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
vll fact, r_fact, dp;
int m, n, k;
vii a;

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
    scanf("%d%d%d", &n, &m, &k);

    a = vii(k);
    fact = r_fact = vll(3048576, 0LL);      //CHECK THE FUKKEN LIMIT OF M+N, NOT MAX(M, N), MOTHERFUCKER!!!!!!!!!!!
    dp = vll(k+100, 0LL);

    for(auto &x: a) scanf("%d%d", &x.fi, &x.se);

    sort(whole(a));
}

//Mathematical Utilities
ll __pow(ll A, ll B)
{
    ll ret = 1LL;
    FORl(i, 0, 63)
    {
        if(((B >> i) & 1) == 1) ret = (ret * A) % mod;
        A = (A * A) % mod;
    }
    return ret % mod;
}
#define what_is(x) cerr << #x << " is " << x << endl;
ll c_k_n(int kar, int n)
{
    assert(0 <= kar && kar <= n);

//    what_is(kar);
//    what_is(n);
//    what_is(fact[kar]);
//    what_is(r_fact[n]);
//    what_is(r_fact[n-kar]);
//    cerr << (fact[n] * ((r_fact[n-kar] * r_fact[kar]) % mod)) % mod << el;

    return (fact[n] * ((r_fact[n-kar] * r_fact[kar]) % mod)) % mod;
}
void Preps()
{
    fact[0] = 1LL;
    FOR(i, 1, 3000008) fact[i] = (1LL * fact[i-1] * (ll)i) % mod;
    r_fact[3000000] = __pow(fact[3000000], mod - 2);
    FORb(i, 3000000-1, 0) r_fact[i] = (r_fact[i+1] * 1LL * (i+1)) % mod;
}


//Process
void Solve()
{
    a.push_back(ii(n, m));

    FORl(i, 0, (int)a.size())
    {
        dp[i] = c_k_n(a[i].fi-1, a[i].fi+a[i].se-2);

        FORl(j, 0, i)
        {
            if(a[j].fi <= a[i].fi && a[j].se <= a[i].se)
            {
                int xi = a[i].fi, yi = a[i].se;
                int xj = a[j].fi, yj = a[j].se;

                dp[i] -= 1LL * dp[j] * c_k_n(xi - xj, xi - xj + yi - yj);
            }

            if(dp[i] < 0) dp[i] += mod * (llabs(dp[i]) / mod + 1);
            dp[i] %= mod;
        }
    }

    cout << dp[k];
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Preps();
    Solve();
    return 0;
}
