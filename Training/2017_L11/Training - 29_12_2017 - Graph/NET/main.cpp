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
#define task "NET"
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
int m, n, k, l, res, nTime;
vi num, low, sv1, sv2;
vii bridges;
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
	scanf("%d%d%d%d", &n, &m, &k, &l);

	bridges.clear();
	sv1 = sv2 = num = low = vi(n+1, 0);
	adj = vvi(n+1);

	FOR(i, 1, k) scanf("%d", &u), sv1[u] = 1;
	FOR(i, 1, l) scanf("%d", &u), sv2[u] = 1;

	FOR(i, 1, m)
	{
	    scanf("%d%d", &u, &v);
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
        if(num[v] != 0) low[u] = min(low[u], num[v]);
        else
        {
            DFS(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] >= num[v]) bridges.push_back(ii(u, v));
        }
    }

    sv1[p] += sv1[u];
    sv2[p] += sv2[u];
}
bool CheckBridge(ii x)
{
    int u = x.first, v = x.second;
    if(sv1[u] == 0 || sv1[v] == 0 || sv2[u] == 0 || sv2[v] == 0) return true;
    if((sv1[1] == sv1[u] && sv1[u] == sv1[v]) || (sv2[1] == sv2[u] && sv2[u] == sv2[v])) return true;
    return false;
}


//Process
void Solve()
{
    DFS(1, 0);

    FOR(i, 1, n) cerr << sv1[i] << " "; cerr << "\n";
    FOR(i, 1, n) cerr << sv2[i] << " "; cerr << "\n";

    res = 0;
    for(ii x: bridges) res += (int)CheckBridge(x);
    printf("%d", res);
}

//Main Procedure
int main()
{
    //FileInit();
    Enter();
    Solve();
    FileClose();
    return 0;
}
