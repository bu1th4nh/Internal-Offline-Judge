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
#define task "POFP"
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

const long long mod = 1000000000LL;
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
int n, nTest;
vi res;

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


//Check
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
void Preps()
{
    res = vi(1048576, 0LL);

    res[2] = 1LL;
    FOR(i, 4, 1000000)
    {
        if(i % 2 == 0)
        {
            res[i] = (res[i-2] * __pow((i-1)*1LL , i*1LL)) % mod;
        }
    }
}

//Process
void Sub1()
{
    int x;
    Preps();
    cin >> nTest;

    FOR(i, 1, nTest)
    {
        scanf("%d", &x);
        printf("%lld\n", res[x]);
    }
}

//Process
void Magic()
{
    int x;
    res = vi(1024, 0LL);
    res[2] = 1LL;
    FOR(i, 4, 768)
    {
        if(i % 2 == 0) res[i] = res[i-2] * __pow((i-1)*1LL, i*1LL) % mod;
    }

    cin >> nTest;
    FOR(i, 1, nTest)
    {
        scanf("%d", &x);
        printf("%lld\n", res[16 + ((x-16) % 512)]);
    }
}

//Main Procedure
int main()
{
    FileInit();
    Magic();
    return 0;
}
