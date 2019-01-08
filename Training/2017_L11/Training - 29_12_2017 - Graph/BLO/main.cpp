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
#define task "BLO"
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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef stack<int> si;
vi num, low, par, nDes, nChild;
int n, m, nTime, nBCC;
vb IsCut;
vvi adj;
vll s;

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

	num = low = par = nDes = nChild = vi(n+1, 0);
	IsCut = vb(n+1, false);
	adj = vvi(n+1);

	nBCC = nTime = 0;

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
    num[u] = low[u] = ++nTime, par[u] = p;
    ++nDes[p], ++nChild[p];

    for(int v: adj[u]) if(v != p)
    if(num[v] != 0)
    {
        low[u] = min(low[u], num[v]);
    }
    else
    {
        DFS(v, u);
        low[u] = min(low[u], low[v]);

        if(p != 0 && low[v] >= num[u]) IsCut[u] = true;
    }


    if(p == 0 && nChild[u] >= 2) IsCut[u] = true;
    nDes[p] += nDes[u];
}

//Process
void Solve()
{
    FOR(i, 1, n) if(num[i] == 0) DFS(i, 0);

    FOR(i, 1, n) ++nDes[i];


    FOR(i, 1, n)
    {
        ll res = 2LL*(n-1);
        if(!IsCut[i])
        {
            printf("%lld\n", res);
            continue;
        }

        ll remain = (n - 1)*1LL;

        for(int v: adj[i])
        {
            if(par[v] == i && low[v] >= num[i]) s.push_back(nDes[v]), remain -= nDes[v];
        }
        s.push_back(remain);
        remain = 0LL;

        for(ll x: s) remain += x;
        res += remain * remain;

        for(ll x: s) res -= x*x;
        s.clear();


        cout << res << '\n';
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
