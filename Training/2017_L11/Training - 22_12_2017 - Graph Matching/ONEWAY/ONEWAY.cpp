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
using namespace std;


//=====================================
//Macros
#define task "ONEWAY"
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


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, m, nTime, nBridge;
vi num, low, par, d;
vvi adj, res;
vii EList;
vb used;

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

//Enter
void Enter()
{
    int u, v;
    scanf("%d%d", &n, &m);

    nTime = nBridge = 0;

    adj = res = vvi(n+1);
    num = low = par = d = vi(n+1);

    used = vb(n+1, false);

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        EList.push_back(ii(u, v));
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

//Check
void DFS(int u, int p)
{
    num[u] = low[u] = ++nTime;
    for(int v: adj[u])
    {
        if(v == p) continue;
        if(num[v] > 0)
        {
            low[u] = min(low[u], num[v]);
        }
        else
        {
            d[v] = d[u] + 1, par[v] = u;
            DFS(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] >= num[v]) ++nBridge;
        }
    }
}

void Redirect()
{
    for(ii e: EList)
    {
        int u = e.first, v = e.second;
        if(par[v] == u) res[u].pb(v);
        else if(par[u] == v) res[v].pb(u);
        else if(d[u] < d[v]) res[v].pb(u);
        else res[u].pb(v);
    }
}

//Process
void Solve()
{
    int nCC = 0;
    FOR(i, 1, n) if(num[i] == 0)
    {
        par[i] = -1, ++nCC;
        DFS(i, -1);
    }

    if(nBridge > 0 || nCC > 1)
    {
        printf("0\n");
        return;
    }

    printf("1\n");
    Redirect();
    FOR(i, 1, n)
    {
        for(int v: res[i]) printf("%d %d\n", i, v);
    }

}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    FileClose();
    return 0;
}


/* --Test data 1--
4 5
1 2
2 3
2 4
3 4
1 4
*/

/* --Test data 2--
4 4
1 2
2 3
3 4
3 1
*/
