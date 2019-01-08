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
#define task "PLANTREE"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define whole1(x) x.begin()+1, x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Typedefs
struct point
{
    typedef long long ll;

    ll x, y;
    int id;

    point() {}
    point(ll x, ll y, int id): x(x), y(y), id(id) {}
};
struct edge
{
    typedef long long ll;

    int u, v;
    ll cost;

    edge() {}
    edge(int u, int v, ll c): u(u), v(v), cost(c) {}

    bool operator < (const edge &oth) const
    {
        return this->cost < oth.cost;
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<point> vp;
typedef vector<edge> ve;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ve edgeList;
ll res;
int n;
vp a;


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

//Fast I/O
inline int readInt()
{
    char c = 0;
    int ret = 0;
    bool neg = 0;

    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; c >= '0' && c <= '9'; c = getchar()) ret = ret * 10 + c - 48;
    return (neg) ? -ret : ret;
}


//Enter
void Enter()
{
    int x, y;
    n = readInt();
    a = vp(n+1);

    FOR(i, 1, n)
    {
        x = readInt(); y = readInt();
        a[i] = point(x, y, i);
    }
}

//Graph Preparation
ll getDist(int i, int j)
{
    return min(llabs(a[i].x - a[j].x), llabs(a[i].y - a[j].y));
}
bool cmp_by_X(const point &p1, const point &p2)
{
    return (p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y));
}
bool cmp_by_Y(const point &p1, const point &p2)
{
    return (p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x));
}
void PrepareGraph()  //Subtask-2
{
    sort(whole1(a), cmp_by_X);
    FOR(i, 1, n-1)
    {
        edgeList.push_back(edge(a[i].id, a[i+1].id, getDist(i, i+1)));
    }

    sort(whole1(a), cmp_by_Y);
    FOR(i, 1, n-1)
    {
        edgeList.push_back(edge(a[i].id, a[i+1].id, getDist(i, i+1)));
    }
}
void PrepareGraph_sub1()
{
    FOR(i, 1, n-1)
    {
        FOR(j, i, n) if(i != j)
        {
            edgeList.push_back(edge(i, j, getDist(i, j)));
        }
    }
}


//Process
void Kruskal()
{
    int m = edgeList.size();
    res = 0LL;

    sort(whole(edgeList));
    DisjointSet dsu(n);

    for(edge e: edgeList)
    {
        if(dsu.unify(e.u, e.v)) res += e.cost;
    }
}


//Output
void Solve()
{
    if(n <= 1)
    {
        puts("0");
        return;
    }

    if(n <= 950) PrepareGraph_sub1();
    else PrepareGraph();

    Kruskal();
    printf("%lld\n", res);
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}


/* Sample I/O
4
5 2
4 3
1 5
2 6
*/
