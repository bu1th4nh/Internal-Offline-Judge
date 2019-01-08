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
#define task "BGAME"
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


//=====================================
//Fast I/O
template<class T> inline void scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret *= neg ? -1 : 1;
}
template<class T> void print(T x)
{
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}


//=====================================
//Typedefs
struct edge
{
    int u, v, weight;
    bool inTree;

    edge(): inTree(0) {}
    edge(int u, int v, int c): u(u), v(v), weight(c), inTree(0) {}

    void input()
    {
        scan(u);
        scan(v);
        scan(weight);
    }
    int other(int x) const
    {
        return u ^ v ^ x;
    }
    bool operator < (const edge &oth) const
    {
        return this->weight > oth.weight;
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
    bool unite(int r, int s)
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
template<int MAX_LOG> struct LowestCommonAncestor
{
    typedef long long ll;
    typedef pair<int, ll> ii;
    typedef vector<int> vi;
    typedef vector<ii> vii;
    typedef vector<vi> vvi;
    typedef vector<vii> vvii;

    int n;
    vi depth;
    vvii adj;
    vvi maxEdge, par;


    void add_edge(const edge &e)
    {
        adj[e.u].pb(ii(e.weight, e.v));
        adj[e.v].pb(ii(e.weight, e.u));
    }
    void DFS(int u, int parent)
    {
        int v, w;
        for(auto x: adj[u])
        {
            v = x.se;
            w = x.fi;
            if(v == parent) continue;

            depth[v] = depth[u] + 1;
            maxEdge[v][0] = w;
            par[v][0] = u;

            DFS(v, u);
        }
    }
    void initSparseTable()
    {
        FOR(i, 1, n) if(depth[i] < 0)
        {
            depth[i] = 0;
            DFS(i, -1);
        }
        FOR(j, 1, MAX_LOG) FOR(i, 1, n)
        {
            par[i][j] = par[par[i][j-1]][j-1];
            maxEdge[i][j] = max(maxEdge[i][j-1] , maxEdge[par[i][j-1]][j-1]);
        }
    }

    int get_max_edge(int u, int v)
    {
        if(depth[v] > depth[u]) swap(u, v);

        int ret = -1;
        FORb(i, MAX_LOG, 0) if(depth[par[u][i]] >= depth[v])
        {
            ret = max(ret, maxEdge[u][i]);
            u = par[u][i];
        }

        if(u == v) return ret;
        FORb(i, MAX_LOG, 0) if(par[u][i] != par[v][i])
        {
            ret = max(ret, maxEdge[u][i]);
            ret = max(ret, maxEdge[v][i]);


            u = par[u][i];
            v = par[v][i];
        }

        return max(ret, max(maxEdge[u][0], maxEdge[v][0]));
    }


    LowestCommonAncestor(int __n)
    {
        n = __n;
        adj = vvii(n+1);
        depth = vi(n+1, -1);
        par = maxEdge = vvi(n+1, vi(MAX_LOG+10, 0));
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<edge> ve;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ve edgeList;
int n, m;


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
    scan(n);
    scan(m);

    edgeList = ve(m+1, edge());
    FOR(i, 1, m) edgeList[i].input();
}

//Process
void Solve()
{
    ll res = 0LL;
    sort(whole(edgeList));

    LowestCommonAncestor<20> lca(n);
    DisjointSet dsu(n);

    FOR(i, 1, m)
    {
        if(dsu.unite(edgeList[i].u, edgeList[i].v))
        {
            lca.add_edge(edgeList[i]);
            edgeList[i].inTree = 1;
        }
    }

    lca.initSparseTable();

    FOR(i, 1, m) if(!edgeList[i].inTree)
    {
        res = max(res, 1LL * edgeList[i].weight + 1LL * lca.get_max_edge(edgeList[i].u, edgeList[i].v));
    }

    print(res);
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
