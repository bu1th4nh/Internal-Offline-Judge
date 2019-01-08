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
#define task "DAG"
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


const int INF = 1234567890;
const long long MOD_BASE = 1000000007;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int m, n, s, t, topoTime;
vi F, topoOrder, idOrder;
bool isPathFound;
vll nPath;
vb avail;
vvii adj;


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
    int u, v, c;
	scanf("%d%d%d%d", &n, &m, &s, &t);

	adj = vvii(n+1);
	nPath = vll(n+1, 0LL);
	avail = vb(n+1, true);

	F = vi(n+1, -INF);
	topoOrder = idOrder = vi(n+1, 0);

	isPathFound = true;
	topoTime = n;

	FOR(i, 1, m)
	{
	    scanf("%d%d%d", &u, &v, &c);
        adj[u].pb(ii(c, v));
	}
}

//Check
void topological_DFS(int u)
{
    avail[u] = false;
    for(ii x: adj[u]) if(avail[x.second]) topological_DFS(x.second);

    topoOrder[u] = topoTime;
    idOrder[topoTime--] = u;
}

//Process
void MaximumPath()
{

    int w, u, v;
    FOR(i, 1, n) if(avail[i]) topological_DFS(i);


    F[s] = 0;

    FOR(i, 1, n)
    {
        u = idOrder[i];
        for(ii x: adj[u])
        {
            v = x.second;
            w = x.first;

            F[v] = max(F[v], F[u] + w);
        }
    }

    isPathFound = (F[t] != -INF);
}
void CountPath()
{
    int u, v;
    nPath[t] = 1LL;

    FORb(i, n, 1) if(idOrder[i] != t)
    {
        u = idOrder[i];
        for(ii x: adj[u])
        {
            v = x.second;
            nPath[u] = ((nPath[u]*1LL + nPath[v]*1LL) % MOD_BASE) * 1LL;
        }
    }
}

//Output
void Solve()
{
    MaximumPath();
    if(isPathFound)
    {
        CountPath();
        printf("%d\n%lld\n", F[t], nPath[s] % MOD_BASE);
    }
    else
    {
        printf("NO PATH\n0");
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
