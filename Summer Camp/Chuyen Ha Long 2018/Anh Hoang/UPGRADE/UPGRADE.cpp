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

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#endif // __cplusplus

using namespace std;


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task "UPGRADE"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin()+1, x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


const long long inf = (1LL << 61) - 1LL;
//=====================================
//Class library
struct edge
{
    int u, v, cost;

    edge() {}
    edge(int u, int v, int c): u(u), v(v), cost(c) {}

    bool operator < (const edge &oth) const
    {
        return this->cost > oth.cost;
    }
};
struct DisjointSet
{
    typedef vector<int> vi;

    vi lab;
    int n;

    int find(int u)
    {
        return (lab[u] < 0) ? u : (lab[u] = find(lab[u]));
    }
    bool unify(int r, int s)
    {
        r = find(r);
        s = find(s);
        if(r == s) return 0;

        if(lab[s] < lab[r]) swap(r, s);
        lab[r] += lab[s];
        lab[s] = r;

        return 1;
    }


    ~DisjointSet() {}

    DisjointSet() {}
    DisjointSet(int __n)
    {
        lab = vi(__n+16, -1);
        n = __n;
    }
};
struct LowestCommonAncestor
{
    const int MAX_LOG = 21;

    typedef long long ll;
    typedef pair<int, ll> ii;
    typedef vector<int> vi;
    typedef vector<ii> vii;
    typedef vector<vi> vvi;
    typedef vector<vii> vvii;

    int n;
    vvii par, adj;
    vi depth;


    ll min(ll __a, ll __b, ll __c)
    {
        return std::min(__a, std::min(__b, __c));
    }
    void addEdge(const edge &e)
    {
        adj[e.u].push_back(ii(e.v, e.cost));
        adj[e.v].push_back(ii(e.u, e.cost));
    }
    void DFS(int u, int parent)
    {
        for(ii x: adj[u])
        {
            int v = x.first;
            if(v == parent) continue;
            depth[v] = depth[u] + 1;

            par[v][0] = ii(u, x.second);
            FOR(i, 1, 18)
            {
                par[v][i].fi = par[par[v][i-1].fi][i-1].fi;
                par[v][i].se = std::min(par[par[v][i-1].fi][i-1].se, par[v][i-1].se);
            }

            DFS(v, u);
        }

    }
    ii LCA(int u, int v)
    {
        ii p;

        p.second = inf;
        if(depth[u] > depth[v]) swap(u, v);
        int diff = depth[v] - depth[u];

        FORb(i, 18, 0) if((diff >> i)&1)
        {
            p.se = std::min(p.se, par[v][i].se);
            v = par[v][i].fi;
        }

        if(u == v) return ii(u, p.se);
        FORb(i, 18, 0) if(par[u][i].fi != par[v][i].fi)
        {
            p.se = min(p.se, par[u][i].se, par[v][i].se);
            v = par[v][i].fi;
            u = par[u][i].fi;
        }

        return ii(par[u][0].fi, min(p.second, par[u][0].se, par[v][0].se));
    }
    void extractLCA(int u, int v, int &x, ll &y)
    {
        ii ret = LCA(u, v);
        x = ret.first;
        y = ret.second;
    }


    ~LowestCommonAncestor() {}

    LowestCommonAncestor() {}
    LowestCommonAncestor(int __n)
    {
        n = __n;
        adj = vvii(n+1);
        depth = vi(n+1, 0);
        par = vvii(n+1, vii(MAX_LOG));

        depth[1] = 1;
    }

};

//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, ll> ii;
typedef vector<bool> vb;
typedef vector<edge> ve;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ve edgeList;
vb avail;
int n, m;
ll res;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    FILEOP_DEBUG()
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
    scanf("%d%d", &n, &m);

    edgeList = ve(m+1);
    avail = vb(m+1, 1);

    FOR(i, 1, m) scanf("%d%d%d", &u, &v, &c), edgeList[i] = edge(u, v, c);
}

//Process
void Solve()
{
    res = 0LL;

    LowestCommonAncestor lca(n);
    DisjointSet          dsu(n);

    edge e;
    int u;
    ll w;

    sort(whole(edgeList));
    FOR(i, 1, m)
    {
        e = edgeList[i];
        if(dsu.unify(e.u, e.v))
        {
            avail[i] = 0;
            lca.addEdge(e);
        }
    }

    lca.DFS(1, 0);
    FOR(i, 1, m) if(avail[i])
    {
        e = edgeList[i];

        lca.extractLCA(e.u, e.v, u, w);
        res += max(0LL, w - 1LL*e.cost);
    }

    cout << res;
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
