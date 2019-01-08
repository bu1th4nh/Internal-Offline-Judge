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
#define task "FGAME"
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
vvi a, F, S;
int m, n;


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

//Fast I/O
inline int readInt()
{
    char c = 0;
    int ret = 0;
    bool neg = 0;

    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }
    for(;c >= '0' && c <= '9'; c = getchar()) ret = ret * 10 + c - 48;

    return (neg) ? -ret : ret;
}

//Enter
void Enter()
{
    //scanf("%d%d", &n, &m);

    n = readInt();
    m = readInt();
    F = S = a = vvi(n+1, vi(m+1, 0LL));

    FOR(i, 1, n) FOR(j, 1, m)
    {
        S[i][j] = readInt();
        S[i][j] %= 3;
    }
}

//Check
bool check(int x, int y, int u, int v)
{
    return (S[u][v] - S[u][y-1] - S[x-1][v] + S[x-1][y-1]) % 3 == 1;
}
void Solve()
{
    FOR(i, 1, n) FOR(j, 1, m) S[i][j] += S[i-1][j] + S[i][j-1] - S[i-1][j-1];
    if(S[n][m] % 3 == 1)
    {
        puts("1");
        return;
    }
    else if(S[n][m] % 3 == 2)
    {
        puts("0");
        return;
    }
    else if(S[n][m] % 3 == 0)
    {
        FOR(i, 1, n) if(check(i, 1, n, m))
        {
            puts("1");
            return;
        }
        FOR(i, 1, m) if(check(1, i, n, m))
        {
            puts("1");
            return;
        }
        puts("0");
    }

}

//Process
void Multi()
{
    int T = 5;
    while(T--)
    {
        Enter();
        Solve();
    }
}

//Main Procedure
int main()
{
    FileInit();
    Multi();
    return 0;
}
