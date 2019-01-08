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
#define task "GUIDE"
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
int n, m, dfs_time;
vi tin, tout, par;
vvi adj;


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
    scanf("%d", &n);

    adj = vvi(n);
    par = tin = tout = vi(n, 0);
    par[0] = -1; dfs_time = 0;

    FORl(i, 0, n-1)
    {
        scanf("%d%d", &u, &v); --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

//DFS
void DFS(int u, int p)
{
    par[u] = p;
    tin[u] = ++dfs_time;

    FORl(i, 0, adj[u].size())
    {
        int v = adj[u][i];
        if(v == p)
        {
            adj[u][i] = adj[u].back();
            adj[u].pop_back(); --i;
            continue;
        }
        DFS(v, u);
    }
    tout[u] = ++dfs_time;
}

//Process
void Query()
{
    int u, v;
    DFS(0, -1);

    scanf("%d", &m);
    while(m--)
    {
        scanf("%d%d", &u, &v); --u, --v;
        if(tin[u] < tin[v] && tout[v] < tout[u])
        {
            int l = 0, r = adj[u].size() - 1;
            while(l < r)
            {
                int mid = (l + r + 1) / 2;
                if(tin[adj[u][mid]] <= tin[v]) l = mid;
                else r = mid - 1;
            }
            printf("%d\n", adj[u][l] + 1);
        }
        else printf("%d\n", par[u] + 1);
    }
}

//Main Procedure
int main()
{
    //freopen("TEST.out", "w", stdout);
    FileInit();

    Enter();
    Query();

    FileClose();
    return 0;
}
