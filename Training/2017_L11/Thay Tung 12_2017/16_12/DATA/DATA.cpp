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
#define task "DATA"
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
typedef set<ii> sii;
vi tin, fup, deg, getComp, ComponentSize;
int m, n, dfs_time = 0;
sii bridge;
vvi adj;
vb used;

const int MOD = 1000000007;
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

	adj = vvi(n);
	used = vb(n, 0);
	tin = fup = getComp = ComponentSize = vi(n, 0);

	FOR(i, 1, m)
	{
	    scanf("%d%d", &u, &v);--u, --v;
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
}

//Check
void DFS(int v, int p)
{
    used[v] = true;
    tin[v] = fup[v] = ++dfs_time;
    for(int u: adj[v])
    {
        if(u == p) continue;
        if(!used[u])
        {
            DFS(u, v);
            fup[v] = min(fup[v], fup[u]);

            if(fup[u] > tin[v]) bridge.insert({min(u, v), max(u, v)});
        }
        else fup[v] = min(fup[v], tin[u]);
    }
}
void FindComponent(int component, int &vs, int v)
{
    used[v] = true;
    getComp[v] = component;
    vs++;

    for(int u: adj[v])
    {
        ii p(min(u, v), max(u, v));
        if(bridge.find(p) != bridge.end()) continue;
        if(!used[u]) FindComponent(component, vs, u);
    }
}

//Process
void Solve()
{
    int nComponent = 0;
    FORl(i, 0, n)
    {
        if(!used[i]) DFS(i, -1);
    }
	used = vb(n, 0);
    FORl(i, 0, n)
    {
        if(!used[i])
        {
            int vs = 0;
            FindComponent(nComponent, vs, i);
            ComponentSize[nComponent++] = vs;
        }
    }

    deg = vi(nComponent, 0);
    for (const auto &bridges : bridge)
    {
        deg[getComp[bridges.first]]++;
        deg[getComp[bridges.second]]++;
    }

    int res = 0, cnt = 1;
    FORl(i, 0, nComponent)
    {
        if(deg[i] <= 1)
        {
            ++res;
            cnt = (cnt * 1LL * ComponentSize[i]) % MOD;
        }
    }
    cout << res << " " << cnt;
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
