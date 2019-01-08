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
#define task "CNTSEQ"
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi a, ca, pool;
int n, nQuery;
vii query, cq;

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
template<class T> inline void scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret *= neg ? -1 : 1;
}
template<class T> void print(T x)
{
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}


//Enter
void Enter()
{
	scan(n);

    a = ca = vi(n+1, 0);
    FOR(i, 1, n) scan(a[i]), pool.pb(a[i]);

    scan(nQuery);
    query = cq = vii(nQuery+1);
    FOR(i, 1, nQuery)
    {
        scan(query[i].fi);
        scan(query[i].se);

        pool.push_back(query[i].fi);
        pool.push_back(query[i].se);
    }

    sort(whole(pool));
    FOR(i, 1, n) ca[i] = lower_bound(whole(pool), a[i]) - pool.begin() + 1;
    FOR(i, 1, nQuery)
    {
        cq[i].fi = lower_bound(whole(pool), query[i].fi) - pool.begin() + 1;
        cq[i].se = lower_bound(whole(pool), query[i].se) - pool.begin() + 1;
    }
}

//Check
void sub1()
{
    vvi dp(n+1, vi(n+1, 0));

    vector<ll> rezz(pool.size()+111, 0LL);

    FOR(i, 1, n) dp[i][i] = i;
    FOR(i, 1, n)
    {
        FOR(j, i+1, n)
        {
            if(ca[dp[i][j-1]] > ca[j])
            {
                dp[i][j] = dp[i][j-1];
            }
            else dp[i][j] = j;
        }
    }

    FOR(i, 1, n)
    {
        FOR(j, i, n) ++rezz[ca[dp[i][j]]];
    }

    FOR(i, 1, (int)pool.size()+10) rezz[i] += rezz[i-1];

    FOR(i, 1, nQuery)
    {
        print(rezz[cq[i].se] - rezz[cq[i].fi-1]);
        putchar('\n');
    }
}


//Main Procedure
int main()
{
    Enter();
    sub1();
    return 0;
}
