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
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "SCHOOL"
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

const int inf = 1e9 + 69;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, m, k;
ll res;


//=====================================
//Functions and procedures
//Process
struct Dijkstra
{
    vvii adj;
    vi d;

    Dijkstra()
    {
        d = vi(n+1, inf);
        adj = vvii(n+1);
    }

    void addEdge(int u, int v, ll c)
    {
        adj[u].pb(ii(c, v));
    }
    void calc(int start)
    {
        int u, v, du, uv;

        priority_queue<ii, vii, greater<ii>> pq;
        pq.push(ii(0, start));
        d[start] = 0;

        while(!pq.empty())
        {
            u = pq.top().second;
            du = pq.top().first;
            pq.pop();

            if(d[u] != du) continue;

            for(ii x: adj[u])
            {
                uv = x.first;
                v = x.second;
                if(du + uv < d[v]) pq.push(ii((d[v] = du + uv), v));
            }
        }
    }
};


//Output
void Solve()
{
    scanf("%d%d%d", &n, &m, &k);
    int u, v, c1, c2;

    Dijkstra fr_1, fr_n, fr_k;

    FOR(i, 1, m)
    {
        scanf("%d%d%d%d", &u, &v, &c1, &c2);
        fr_1.addEdge(u, v, c2);
        fr_k.addEdge(v, u, c1);
        fr_n.addEdge(v, u, c2);
    }

    fr_1.calc(1);
    fr_k.calc(k);
    fr_n.calc(n);

    res = inf;

    FOR(i, 1, n)
    {
        if(fr_1.d[i] + fr_k.d[i] < 60)
        {
            res = min(res, fr_1.d[i] + fr_n.d[i]);
        }
    }

    cout << res;
}



//Main Procedure
int main()
{
    FILEOP();
    Solve();
    return 0;
}
