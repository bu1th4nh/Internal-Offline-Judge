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
#define task ""
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

//#define __debug

const int inf = 1000000007;
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vvi c, dp;
int n, m;

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

//Utilities
inline int readInt()
{
    bool neg = 0;
    int ret = 0;
    char c = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c); c = getchar()) ret = ret * 10 + int(c - '0');

    #ifdef __debug
        cerr << ret << el;
    #endif // __debug

    return neg ? -ret : ret;

}

//Enter
void Enter()
{
	n = readInt();
	m = readInt();

	//cerr << n << sp << m << el;

	dp = vvi(n, vi(1 << n, -1));
	c = vvi(n, vi(n, -1));

	FOR(i, 1, m)
	{
	    c[readInt() - 1][readInt() - 1] = readInt();
	}
}

//Check
int TSP(int state, int i)
{
    if((state == (1 << n) - 1) && c[i][0] > 0) return c[i][0];
    if((state == (1 << n) - 1) && c[i][0] < 0) return inf;
    if(dp[i][state] != -1) return dp[i][state];

    int ret = inf;
    FORl(j, 0, n)
    {
        if((state & (1 << j)) || c[i][j] < 0) continue;
        ret = min(ret, c[i][j] + TSP(state | (1 << j), j));
    }

    return (dp[i][state] = ret);
}

//Process
void Solve()
{
    printf("%d\n", TSP(1 << 0, 0));
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
