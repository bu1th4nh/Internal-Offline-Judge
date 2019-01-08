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
#define task "GRAPH"
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
typedef stack<int> si;
int m, n, nCC, nTime;
vi res, num, low;
vvi adj;
si s;

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

	num = low = res = vi(n+1, 0);
	adj = vvi(n+1);

	nCC = nTime = 0;

	FOR(i, 1, m)
	{
	    scanf("%d%d", &u, &v);
	    adj[u].pb(v);
	    adj[v].pb(u);
	}

}

//Check
void DFS(int u, int isRoot)
{
    num[u] = low[u] = ++nTime;

    if(adj[u].empty()) return;

    s.push(u);

    for(int v: adj[u]) if(num[v] != 0)
    {
        low[u] = min(low[u], num[v]);
    }
    else
    {
        DFS(v, 0);
        low[u] = min(low[u], low[v]);

        if(isRoot || low[v] >= num[u])  //v is root of BCC.
        {
            int x;
            res[u]++;
            do
            {
                x = s.top();
                s.pop();

                res[x]++;
            }
            while(x != v);
        }
    }
}


//Process
void Solve()
{
    FOR(i, 1, n) if(num[i] == 0) DFS(i, 1), nCC++;

    FOR(u, 1, n)
    {
        if(adj[u].empty()) res[u] = nCC - 1;
        else res[u] += nCC - 1;
    }


    FOR(i, 1, n) printf("%d\n", res[i]);
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
