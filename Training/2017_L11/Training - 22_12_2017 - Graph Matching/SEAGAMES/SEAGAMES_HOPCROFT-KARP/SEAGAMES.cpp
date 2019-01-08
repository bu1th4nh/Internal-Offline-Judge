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
#define task "SEAGAMES"
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
vi d, place, matx, maty;
int n, k;
vvi g;

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
	scanf("%d%d", &n, &k);

	g = vvi(n+1, vi(n+1));
	place = vi(k+1);

	FOR(i, 1, k) scanf("%d", &place[i]);

	FOR(i, 1, n)
	{
        FOR(j, 1, n)
        {
            scanf("%d", &g[i][j]);
        }
	}
}

//Hopcroft-Karp Algorithm
const int inf = 1207200100;
bool BFS(int lim)
{
    queue<int> q;
    int u;

    while(!q.empty()) q.pop();

    FOR(u, 1, n)
    {
        if(matx[u] == 0)
        {
            d[u] = 0;
            q.push(u);
        }
        else d[u] = inf;
    }

    d[0] = inf;
    while(!q.empty())
    {
        u = q.front(), q.pop();
        if(d[u] < d[0])
        {
            FOR(v, 1, n) if(d[maty[v]] >= inf && g[u][v] <= lim)
            {
                d[maty[v]] = d[u] + 1;
                q.push(maty[v]);
            }
        }
    }

    return (d[0] < inf);
}
bool DFS(int u, int lim)
{
    if(u == 0) return true;
    FOR(v, 1, n)
    {
        if(d[maty[v]] == d[u] + 1 && g[u][v] <= lim)
        {
            if(DFS(maty[v], lim))
            {
                matx[u] = v;
                maty[v] = u;
                return true;
            }
        }
    }
    d[u] = inf;
    return false;
}
bool IsMatched(int lim)
{
    int r = 0;
    while(BFS(lim))
    {
        FOR(i, 1, n) if(matx[i] == 0) if(DFS(i, lim)) ++r;
    }
    return (r == n);
}


//Process
void Solve()
{
    int l = 0, h = 100000000, db = 0;
    vi ovr;

    while(l <= h)
    {
        matx = maty = d = vi(n+1, 0);
        int mid = (l + h) / 2;

        if(IsMatched(mid)) h = mid - 1, db = mid, ovr = matx;
        else l = mid + 1;
    }

    FOR(i, 1, k) printf("%d ", ovr[place[i]]);
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
