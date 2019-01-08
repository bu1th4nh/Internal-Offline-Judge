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
#define task "METRO"
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


const long long inf = (1LL << 60);
//=====================================
//Typedefs
struct edge
{
    typedef long long ll;

    int v;
    ll cost;

    edge(ll __c, int __v): cost(__c), v(__v){}
    edge() {}

    bool operator> (const edge &other) const
    {
        return (this->cost) > other.cost;
    }
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<edge> ve;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<ve> vve;
typedef vector<vii> vvii;
int src, dst, n, m;
ll delta;
vll dist;
vve adj;

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

//Enter
void Enter()
{
    int u, v;
    ll c;

    scan(n);
    scan(m);
    scan(src);
    scan(dst);
    scan(delta);

    dist = vll(n+1, inf);
    adj  = vve(n+1);

    FOR(i, 1, m)
    {
        scan(u);
        scan(v);
        scan(c);

        c += 1LL * i * (delta + 1LL);
        if(u == src) c -= 1LL * i;
        if(v == dst) c -= 1LL * i * delta;

        //cerr << c << el;

        adj[u].push_back(edge(c, v));
    }
}

//Check
void Dijkstra()
{
    int u, v;
    ll du, uv;

    priority_queue<edge, ve, greater<edge>> pq;
    pq.push(edge(0LL, src));
    dist[src] = 0LL;

    while(!pq.empty())
    {
        u = pq.top().v;
        du = pq.top().cost;
        pq.pop();

        if(dist[u] != du) continue;

        for(edge e: adj[u])
        {
            v = e.v;
            uv = e.cost;


            if(dist[v] > du + uv)
            {
                pq.push(edge((dist[v] = du + uv), v));
            }


            //FOR(i, 1, n) {if(dist[i] >= inf) cerr << '-' << sp; else cerr << dist[i] << sp;}
            //cerr << el;
        }
    }

    if(dist[dst] >= inf) puts("-1");
    else print(dist[dst]);
}


//Output
void Solve()
{
    Dijkstra();
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
