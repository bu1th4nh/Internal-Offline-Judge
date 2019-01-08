/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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
using namespace std;


//=====================================
//Macros
#define task "PSYCHOLOGY"
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

const long long mod = 998244353;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vll fc, rfc;
int tc;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Utilities
ll POWER(ll A, ll B)
{
    if(B == 0) return 1LL;
    if(B == 1) return (A % mod);

    ll P = POWER(A, B / 2);
    P = (P%mod * P%mod) % mod;

    return (B & 1) ? ((P * A) % mod) : P % mod;
}

//Preliminary Processing
void Prep()
{
    rfc = fc = vll(400004, 0LL);
    fc[0] = 1LL;
    FOR(i, 1, 400000) fc[i] = (1LL * fc[i-1] * (i * 1LL)) % mod;

    rfc[400000] = POWER(fc[400000], mod - 2);

    //cerr << rfc[400000] <<"\n";

    FORb(i, 400000-1, 0) rfc[i] = (rfc[i+1] * ((ll)(i + 1))) % mod;
}


//Main Procedure
int main()
{
    FileInit();

    Prep();
    //cerr << POWER(9, 1001) << "\n";
    scanf("%d", &tc);
    while(tc--)
    {
        int n, k;
        scanf("%d%d", &n, &k); --k;
        ll res = ((ll)(fc[n + k]) * (((ll)(rfc[n] * rfc[k]))% mod)) % mod;
        cout << res << "\n";
    }

    //cerr << fc[10] << "\n";

    FileClose();
    return 0;
}
