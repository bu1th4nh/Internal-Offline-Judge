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
#define sp ' '
#define el '\n'
#define task "SNOW"
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

const long long inf = 1234567890987527;
//=====================================
//DSUs
struct DisjointSet
{
    typedef vector<int> vi;

    vi lab;
    int n;

    DisjointSet() {}
    DisjointSet(int __n)
    {
        n = __n;
        lab = vi(__n+12, -1);
    }

    int find(int u)
    {
        return (lab[u] < 0) ? u : lab[u] = find(lab[u]);
    }
    void unify(int u, int v)
    {
        if(u == v) return;
        if(lab[v] < lab[u]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
    }
    bool unionSet(int u, int v)
    {
        int r = find(u);
        int s = find(v);
        if(r == s) return false;
        unify(r, s);
        return true;
    }
};


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;

typedef pair<ll, int> lli;          //Adj. List
typedef pair<int, int> ii;
typedef pair<ll, ii> llii;          //Edge

typedef vector<llii> vllii;
typedef vector<lli> vlli;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<vlli> vvlli;

int m, n, k, t;
vllii EdgeList;
vi vertices;
vvlli adj;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
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
    ll c;

	scanf("%d%d%d%d", &n, &k, &m, &t);
	vertices = vi(k+1);
	adj = vvlli(n+1);

	FOR(i, 1, k) scanf("%d", &vertices[i]);
	FOR(i, 1, m)
	{
	    scanf("%d%d%lld", &u, &v, &c);
	    EdgeList.push_back(llii(c, ii(u, v)));
	    adj[u].pb(ii(c, v));
	    adj[v].pb(ii(c, u));
	}
}

//Subtask 1: t = 1, k = n
ll Kruskal()
{
    ll ret = 0LL;
    DisjointSet ds(n);

    sort(whole(EdgeList));
    for(llii x: EdgeList)
    {
        int u = x.se.fi;
        int v = x.se.se;
        ll  c = x.fi;

        if(ds.unionSet(u, v)) ret += c;
    }

    return ret;
}
void Subtask1()
{
    cout << Kruskal() << el;
}



//Subtask 2: t = 1, k = 2
vll Dijkstra(int s)
{
    priority_queue<lli, vlli, greater<lli>> pq;
    ll du, uv;
    int u, v;

    vll d = vll(n+1, inf);
    pq.push(lli(0LL, s));
    d[s] = 0LL;

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != d[u]) continue;

        for(lli x: adj[u])
        {
            v = x.second;
            uv = x.first;

            if(d[v] > du + uv) pq.push(lli((d[v] = du + uv), v));
        }
    }

    return d;
}
void Subtask2()
{
    vll d = Dijkstra(vertices[1]);
    cout << d[vertices[2]];
}

//Subtask 3: t = 1, k = 3
void Subtask3()
{
    ll res = inf;
    vll DIST[4];

    FOR(i, 1, 3) DIST[i] = Dijkstra(vertices[i]);

    FOR(i, 1, n) res = min(res, DIST[1][i] + DIST[2][i] + DIST[3][i]);

    cout << res;
}

//Subtask 3: t = 1, k <= 10
void Subtask4()
{
    EdgeList.clear();
    vvll DIST(k+1);
    FOR(i, 1, k) DIST[i] = Dijkstra(vertices[i]);

    FOR(i, 1, k)
    {
        FOR(j, i, k) if(vertices[j] != vertices[i]) EdgeList.push_back(llii(DIST[i][vertices[j]], ii(vertices[i], vertices[j])));
    }

    cout << Kruskal();
}

//THE LAST SUBTASK: t = 2; k <= 10
void LastSubtask()
{
    vvll DIST(n-k+1);
    vb incl(n+1, 0);

    FOR(i, 1, k) incl[vertices[i]] = 1;


//    puts("");
//    FOR(i, 1, n) cout << incl[i] << el;
//    puts("");



    EdgeList.clear();
    vertices.clear();


    vertices.push_back(-1);
    FOR(i, 1, n) if(incl[i] != 1) vertices.push_back(i);


    FOR(i, 1, n-k)


    FOR(i, 1, n-k) DIST[i] = Dijkstra(vertices[i]);

    FOR(i, 1, n-k)
    {
        FOR(j, i, n-k) if(vertices[j] != vertices[i]) EdgeList.push_back(llii(DIST[i][vertices[j]], ii(vertices[i], vertices[j])));
    }


    //for(auto x: EdgeList) cout << x.se.fi << "-" << x.se.se << " : " << x.fi << el;

    cout << Kruskal();
}


//Output
void Solve()
{
    if(t == 1)
    {
        if(k == n) Subtask1();
        else if(k == 2) Subtask2();
        else if(k == 3) Subtask3();
        else Subtask4();
    }
    else LastSubtask();
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
