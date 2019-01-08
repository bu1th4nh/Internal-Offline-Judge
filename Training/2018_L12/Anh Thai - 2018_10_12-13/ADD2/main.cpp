/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//Libraries and namespaces
#include <bits/stdc++.h>
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
#define task "ADD2"
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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int nTest;
ll M, n;

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
inline ll readLL()
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
void writeLL(ll x)
{
    if(x < 0LL)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) writeLL(x / 10);
    putchar(x % 10 + '0');
}


//Indian Multiplication
ll multiMod(ll A, ll B)
{
    ll ret = 0LL;
    FORl(i, 0, 63)
    {
        if((B >> i) & 1 == 1) ret = (ret + A) % M;
        A = (A + A) % M;
    }

    return ret % M;
}
ll powerMod(ll A, ll B)         //Bonus
{
    ll ret = 1LL;
    FORl(i,0, 63)
    {
        if((B >> i) & 1 == 1) ret = (ret * A) % M;
        A = (A * A) % M;
    }

    return ret % M;
}

//Main Procedure
int main()
{
    FileInit();

    nTest = readLL();
    M = readLL();

    while(nTest--)
    {
        n = readLL();
        vi kar({n-1, n, n+1});

        for(auto &x: kar) if(x % 2 == 0)
        {
            x /= 2;
            break;
        }
        for(auto &x: kar) if(x % 3 == 0)
        {
            x /= 3;
            break;
        }

        ll res = kar[0];
        res = multiMod(res, kar[1]);
        res = multiMod(res, kar[2]);

        writeLL(res);
        putchar('\n');
    }
    return 0;
}
