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
#define task "SECURITY"
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


const int MOD_BASE = 1000000007;
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
int m, n, nTime, res2;
vi cost, num, low;
vvi adj, SCC;
ll res1;
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
	scanf("%d", &n);

	num = low = cost = vi(n+1);
	adj = vvi(n+1);
	nTime = 0;

	FOR(i, 1, n) scanf("%d", &cost[i]);

	scanf("%d", &m);
	FOR(i, 1, m)
	{
	    scanf("%d%d", &u, &v);
	    adj[u].pb(v);
	}
}

//Check
void DFS(int u)
{
    low[u] = num[u] = ++nTime;
    s.push(u);
    for(int v: adj[u])
    {
        //if(v == p) continue;
        if(num[v] > 0) low[u] = min(low[u], num[v]);
        else
        {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(low[u] == num[u])
    {
        vi mSCC;
        int v;
        do
        {
            v = s.top(); s.pop();
            num[v] = low[v] = MOD_BASE;
            mSCC.push_back(v);
        }
        while(v != u);
        SCC.push_back(mSCC);
    }
}


//Process
void Solve()
{
    res1 = 0LL;
    res2 = 1;

    FOR(i, 1, n) if(num[i] == 0) DFS(i);

//    for(auto x: SCC)
//    {
//        for(auto i: x) cerr << i << " ";
//        cerr << endl;
//    }


    for(auto mSCC: SCC)
    {
        int min_cost = MOD_BASE, cnt_cost = 0;
        for(auto i: mSCC)
        {
            if(cost[i] == min_cost)
            {
                ++cnt_cost;
                continue;
            }
            if(cost[i] < min_cost)
            {
                cnt_cost = 1;
                min_cost = cost[i];
            }
        }

//        cerr << min_cost << " " << cnt_cost << '\n';

        res1 += 1LL*min_cost;
        res2 = ((res2 % MOD_BASE) * (cnt_cost % MOD_BASE)) % MOD_BASE;
    }

    printf("%lld %d", res1, res2);

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
