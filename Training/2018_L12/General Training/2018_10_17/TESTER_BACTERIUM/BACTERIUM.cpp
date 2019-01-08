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
#define task "BACTERIUM"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin()+1, x.end()
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
typedef pair<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi dp, ps, sa, minB;
vii a;
int n;


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
bool cmp(ii x, ii y)
{
    return x.se > y.se || (x.se == y.se && x.fi < y.fi);
}

//Enter
void Enter()
{
    scanf("%d", &n);

    a = vii(n+1);
    dp = vi(n+1, 0);
    sa = minB = vi(n+1, 0LL);

    FOR(i, 1, n)
    {
        scanf("%d%d", &a[i].fi, &a[i].se);
    }
    sort(whole(a), cmp);
}

//Check
void Solve()
{
    //FOR(i, 1, n) sa[i] = a[i].fi, minB[i] = a[i].se;
    FOR(i, 1, n)
    {
        dp[i] = 1;
        sa[i] = a[i].fi;
        minB[i] = a[i].se;
        FORl(j, 1, i)
        {
            if(sa[j] + a[i].fi <= (dp[j] + 1) * min(minB[j], a[i].se))
            {
                if(dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    sa[i] = sa[j] + a[i].fi;
                    minB[i] = min(minB[j], a[i].se);
                }
            }
        }

        //FOR(j, 1, n) cerr << dp[j] << sp; cerr << el; getchar();
    }
    cout << *max_element(whole(dp));
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}

/*
6
12 8
5 9
2 4
10 12
6 7
13 9
*/

