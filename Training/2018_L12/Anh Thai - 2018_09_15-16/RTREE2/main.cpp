/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*

        UPDATE(x, val): Increase weight of i-th edge by val;

        Let S(x) = sum of a(i).

*/
//Libraries and namespaces
#include <bits/stdc++.h>
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
#define task "RTREE2"
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
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Fundamental Libraries
struct LowestCommonAncestor
{
    typedef vector<int> vi;
    typedef vector<vi> vvi;

    vvi P;                  //P[i][j]: The 2^i-th ancestor of node j
    vi dist;                //dist[i]: the depth of i-th node
    int n, root;

    void addEdge(int u, int v)
    {
        P[0][v] = u;
    }
    int findLevel(int u)
    {
        if(u == root) return dist[u] = 1;
        if(dist[u] == 0) dist[u] = findLevel(P[0][u]) + 1;
        return dist[u];
    }
    void initSparseTable()
    {
        FOR(i, 1, n) if(P[0][i] == 0) root = i;
        FOR(i, 1, n) findLevel(i);
        FOR(k, 1, 19)
        {
            FOR(i, 1, n)
            {
                P[k][i] = P[k-1][P[k-1][i]];
            }
        }
    }
    int LCA(int x, int y)
    {
        FORb(k, 19, 0) if(dist[P[k][x]] >= dist[y]) x = P[k][x];     //Jump!
        FORb(k, 19, 0) if(dist[P[k][y]] >= dist[x]) y = P[k][y];
        FORb(k, 19, 0) if(P[k][x] != P[k][y]) x = P[k][x], y = P[k][y];
        while(x != y) x = P[0][x], y = P[0][y];

        return x;
    }



    LowestCommonAncestor(int __n)
    {
        n = __n;
        dist = vi(n+2, 0);
        P = vvi(20, vi(n+2, 0));
    }
    LowestCommonAncestor() {}


    ~LowestCommonAncestor() {}


};
struct SumFenwickTree
{
    typedef vector<int> vi;

    int n;
    vi Tree;


    void update(int pos, int value)
    {
        while(pos <= n)
        {
            Tree[pos] += value;
            pos += pos & (-pos);
        }
    }
    int query(int pos)
    {
        int ret = 0;
        while(pos > 0)
        {
            ret += Tree[pos];
            pos -= pos & (-pos);
        }
        return ret;
    }

    ~SumFenwickTree() {Tree.clear();}

    SumFenwickTree() {}
    SumFenwickTree(int __n) {n = __n; Tree = vi(__n+4);}
    SumFenwickTree(int __n, int DefaultValue) {n = __n; Tree = vi(__n+4, DefaultValue);}
};



//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;


LowestCommonAncestor    lca_instance;
SumFenwickTree          sfw_instance;


int n, nQuery, timeStamp;
vi first, last, order;
vii edgeList;
vb avail;
vvi adj;

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
inline int readInt()
{
    char c = 0;
    int ret = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    return neg ? -ret : ret;
}
inline void writeInt(int x)
{
    if(x > 9) writeInt(x / 10);
    putchar(x % 10 + '0');
}

//Enter
void Enter()
{
    int u, v;
    n = readInt(), nQuery = readInt();

    timeStamp = 0;
    adj = vvi(n+1);
    avail = vb(n+1, 1);
    first = last = vi(n+1);

    sfw_instance = SumFenwickTree(n);
    lca_instance = LowestCommonAncestor(n);

    edgeList.push_back(ii(-1, -1));

    FOR(i, 1, n-1)
    {
        u = readInt(), v = readInt();
        adj[u].pb(v);
        adj[v].pb(u);

        edgeList.push_back(ii(u, v));
    }
}

//Check
void DFS(int u)
{
    avail[u] = 0;
    first[u] = ++timeStamp;

    for(int v: adj[u]) if(avail[v])
    {
        lca_instance.addEdge(u, v);
        DFS(v);
    }

    last[u] = timeStamp;
}

//Process
void Solve()
{
    int type, res, u, v, l;

    DFS(1);
    lca_instance.initSparseTable();

    while(nQuery--)
    {
        if(readInt() == 1)
        {
            u = readInt(), v = readInt();
            l = lca_instance.LCA(u, v);
            sfw_instance.update(first[u], 1);
            sfw_instance.update(first[v], 1);
            sfw_instance.update(first[l], -2);

            //cerr << "Update: " << u << sp << v << sp << l << el;
        }
        else
        {
            l = readInt();
            u = edgeList[l].fi;
            v = edgeList[l].se;


            if(lca_instance.P[0][v] == u) swap(u, v);
            res = sfw_instance.query(last[u]) - sfw_instance.query(first[u] - 1);

            //cerr << u << sp << v << sp << sfw_instance.query(last[u]) << sp << sfw_instance.query(first[u] - 1) << el;


            writeInt(res);
            putchar('\n');
        }
    }

//    cerr << el;
//    FOR(i, 1, n) cerr << first[i] << sp;
//    cerr << el;
//    FOR(i, 1, n) cerr << last[i] << sp;
//    cerr << el;
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
