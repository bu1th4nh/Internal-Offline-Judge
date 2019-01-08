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
#include <cassert>
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
#define task "BTREE"
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
//Fundamental DSes
struct LowestCommonAncestor
{
    typedef vector<int> vi;
    typedef vector<vi> vvi;

    vvi P;                  //P[i][j]: The 2^i-th ancestor of j-th node
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
    typedef long long ll;
    typedef vector<ll> vi;

    int n;
    vi Tree;


    void update(int pos, ll value)
    {
        if(!pos) return;
        while(pos <= n)
        {
            Tree[pos] += value;
            pos += pos & (-pos);
        }
    }
    ll query(int pos)
    {
        ll ret = 0;
        while(pos > 0)
        {
            ret += Tree[pos];
            pos -= pos & (-pos);
        }
        return ret;
    }

    ~SumFenwickTree() {Tree.clear();}

    SumFenwickTree() {}
    SumFenwickTree(int __n) {n = __n; Tree = vi(__n+4, 0LL);}
    SumFenwickTree(int __n, ll DefaultValue) {n = __n; Tree = vi(__n+4, DefaultValue);}
};



//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;

SumFenwickTree         sfw_1, sfw_2, sfw_3;
LowestCommonAncestor   lca_insta;

int nQuery, timeStamp, n;
ll refr_1, refr_2;
vi first, last;
vi avail;
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
inline ll readInt()
{
    ll ret = 0LL;
    bool neg = 0;
    char c = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    return neg ? -ret : ret;
}
void writeLL(ll x)
{
    if(x < 0)
    {
        putchar('-');
        x = ~x + 1;
    }

    if(x > 9) writeLL(x / 10);
    putchar(x % 10 + '0');
}

//Enter
void Enter()
{
    int u, v;

	n = readInt();
	nQuery = readInt();

	timeStamp = 0;
	refr_1 = 0LL, refr_2 = 0LL;

	adj = vvi(n+1);
	avail = vi(n+100, 1);
	first = last = vi(n+55, 0);

	sfw_1 = sfw_2 = sfw_3 = SumFenwickTree(n);
	lca_insta  = LowestCommonAncestor(n);

	FOR(i, 1, n-1)
	{
	    u = readInt(), v = readInt();
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
}

//Check
void DFS(int u)
{
#ifdef DEBUG
    cerr << u << sp;
#endif // DEBUG


    avail[u] = 0;
    first[u] = ++timeStamp;

    for(int v: adj[u]) if(avail[v] == 1)
    {
        lca_insta.addEdge(u, v);
        DFS(v);
    }

    last[u] = timeStamp;
}
#define what_is(x) cerr << #x << " is " << x << endl;
//Process
void Query_12(int u, ll val, int type)
{
    if(type == 1)
    {
        sfw_1.update(first[u], val);
        sfw_1.update(last[u]+1, -val);

#ifdef DEBUG
        cerr << "==============At query #1:==============\n";
        FOR(i, 1, n) cerr << sfw_1.query(first[i]) << sp; cerr << el;
        cerr << "Query #1 updated " << u << " by " << val << el;
        cerr << "After-result: " << sfw_1.query(first[u]) << el;
        cerr << "============End of query #1=============\n";
#endif // DEBUG

    }
    else
    {
        sfw_1.update(1, val);
        sfw_1.update(first[u], -val);
        sfw_1.update(last[u]+1, val);
        sfw_1.update(n+1, -val);



#ifdef DEBUG
        cerr << "==============At query #2:==============\n";
        FOR(i, 1, n) cerr << sfw_1.query(first[i]) << sp; cerr << el;
        cerr << "Query #2 updated " << u << " by " << val << el;
        cerr << "After-result: " << sfw_1.query(first[u]) << el;
        cerr << "============End of query #2=============\n";
#endif // DEBUG



    }
}
void Query_34(int u, int v, ll val, int type)
{
    int l        = lca_insta.LCA(u, v);
    int parent_l = lca_insta.P[0][l];

    if(type == 3)
    {
        sfw_2.update(first[u], val);
        sfw_2.update(first[v], val);
        sfw_2.update(first[l], -val);
        sfw_2.update(first[parent_l], -val);


#ifdef DEBUG
        cerr << "==============At query #3:==============\n";
        FOR(i, 1, n) cerr << sfw_2.query(first[i]) << sp; cerr << el;
        FOR(i, 1, n) cerr << sfw_2.query(last[i]) - sfw_2.query(first[i] - 1) << sp; cerr << el;
        what_is(first[u]); what_is(first[v]); what_is(first[l]); what_is(val);
        cerr << "Query #3 updated from " << u << " to " << v << " by " << val << el;
        cerr << "After-result: " << sfw_2.query(first[u]) - sfw_2.query(first[u]-1) << el;
        cerr << "After-result: " << sfw_2.query(first[v]) - sfw_2.query(first[v]-1) << el;
        cerr << "============End of query #3=============\n";
#endif // DEBUG


    }
    else
    {
        sfw_2.update(first[u], -val);
        sfw_2.update(first[v], -val);
        sfw_2.update(first[l], val);
        sfw_2.update(first[parent_l], val);

        refr_1 += val;
    }
}
void Query_56(int u, int v, ll val, int type)
{
    if(v < u) swap(u, v);
    if(type == 5)
    {
        sfw_3.update(v+1, -val);
        sfw_3.update(u  ,  val);
    }
    else
    {
        sfw_3.update(1, val);
        sfw_3.update(u, -val);
        sfw_3.update(v+1, val);
        sfw_3.update(n+1, val);
    }
}
void LastQuery(int u)
{
    ll res = refr_1 + refr_2;

    res += sfw_1.query(first[u]);                              //For 1st and 2nd query
    res += sfw_2.query(last[u]) - sfw_2.query(first[u]-1);     //For 3rd and 4th query
    res += sfw_3.query(u);

    writeLL(res);
    putchar('\n');
}

//Output
void Solve()
{
    int u, v, type;
    ll val;

    #ifdef DEBUG
        cerr << "IDX Order: ";
        FOR(i, 1, n) cerr << i << sp; cerr << el;
        cerr << "DFS Order: ";
        DFS(1);
        cerr << el;
    #else
        DFS(1);
    #endif // DEBUG

    lca_insta.initSparseTable();
    while(nQuery--)
    {
        type = readInt();

        if(type == 1 || type == 2) {u = readInt(), val = readInt();                 Query_12(u, val, type);   }
        else if(type == 3 || type == 4) {u = readInt(), v = readInt(), val = readInt();  Query_34(u, v, val, type);}
        else if(type == 5 || type == 6) {u = readInt(), v = readInt(), val = readInt();  Query_56(u, v, val, type);}
        else {u = readInt(); LastQuery(u);}
    }
}



//Main Procedure
int main()
{
    FileInit();
    Enter();


    //FOR(i, 1, n) cerr << adj[i].size() << el;


    Solve();





    return 0;
}
