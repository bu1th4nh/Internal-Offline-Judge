/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Solution Briefing - Foreword



//=====================================
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#include <chrono>
#endif // __cplusplus

using namespace std;

//#define DEBUG
#define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "QoS"
#define maxinp ()
#define fi first
#define se second
#define pb push_back
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define r_whole(x) x.rbegin(),x.rend()
#define FOR(i, x, y) for(auto i=x; i<=y; ++i)
#define FORl(i, x, y) for(auto i=x; i<y; ++i)
#define FORb(i, x, y) for(auto i=x; i>=y; --i)
#define FORlb(i, x, y) for(auto i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define what_is(x) cerr << #x << " is " << x << endl;
#define FILEOP()                        \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
    freopen(task".err", "w", stderr);   \
}

//Macroes - Optional
#ifdef OPTIONAL_FEATURE
    #define pc(x) putchar(x)
    #define gc() getchar()
#endif



//=====================================
//Auxilary Functions and Fast I/O
#ifdef OPTIONAL_FEATURE
    template<class T, class R> T max(const T &__X, const R &__Y)
    {
        return __X > __Y ? __X : __Y;
    }
    template<class T, class R> T min(const T &__X, const R &__Y)
    {
        return __X < __Y ? __X : __Y;
    }
    template<class T, class R> void maximize(T &__X, R __Y)
    {
        __X = __X > __Y ? __X : __Y;
    }
    template<class T, class R> void minimize(T &__X, R __Y)
    {
        __X = __X < __Y ? __X : __Y;
    }
    template<class T> int getBit(T &__X, int __i)
    {
        return ((__X >> __i) & 1) == 1;
    }
    template<class T> bool inRange(T __L, T __R, T __X)
    {
        return __L <= __X && __X <= __R;
    }
    template<class T> T __abs(T __X)
    {
        return (__X < 0) ? -__X : __X;
    }
#endif
//Fast I/O
template<class T> inline void scan(T &__ret)
{
    __ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) __ret = __ret * 10 + c - '0';
    __ret = (neg) ? -__ret : __ret;
}
template<class T> void print(T __X)
{
    if(__X < 0)
    {
        putchar('-');
        __X *= -1;
    }

    if(__X > 9) print(__X / 10);
    putchar(__X % 10 + '0');
}

//=====================================
//Constants
const int inf = 1000000007;


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
long n, m, kth, dst, Cmin, Tmin, QoS, path_length;
vi dist, layer, curPath;
vvi paths;
vb avail;
vvii adj;

//=====================================
//Functions and procedures
//File I/O and utilities
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    #ifdef DEBUG
        FILEOP_DEBUG()
    #else
        FILEOP()
    #endif
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}


//Enter
void Enter()
{
    Cmin = Tmin = inf;
    int u, v, w;
	scan(n);
	scan(m);
	scan(dst);
	scan(kth);

	dist = vi(n+1, inf);
	layer = vi(n+1, 0);
	adj  = vvii(n+1);

	FOR(i, 1, m)
	{
	    scan(u);
	    scan(v);
	    scan(w);
	    minimize(Cmin, w);
	    adj[u].emplace_back(w, v);
	}

	FOR(i, 1, n) sort(whole(adj[i]), [](const ii &x, const ii &y){return x.se < y.se;});
}

//Check
void Dijkstras()
{
    int u, v, du, uv;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != dist[u]) continue;
        for(ii x: adj[u])
        {
            v = x.second;
            uv = x.first;

            if(du + uv < dist[v]) pq.emplace(dist[v] = du + uv, v);
        }
    }
}
void BFS()
{
    layer[dst] = inf;
    layer[1] = 1;
    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(ii x: adj[u])
        {
            if(!layer[x.se]) q.push(x.se), layer[x.se] = layer[x.fi] + 1;
        }
    }
}
void DFS(int u)
{
    if(u == dst && path_length <= QoS)
    {
        paths.push_back(curPath);
        return;
    }

    for(ii x: adj[u]) if(layer[x.se] >= layer[u])
    {
        if(path_length + x.fi > QoS) continue;

        path_length += x.fi;
        curPath.emplace_back(x.se);
        DFS(x.se);
        curPath.pop_back();
        path_length -= x.fi;
    }
}

//Process
bool cmp(const vi &x, const vi &y)
{
    if(x.size() < y.size()) return 1;
    if(x.size() > y.size()) return 0;
    FORl(i, 0, y.size())
    {
        if(x[i] < y[i]) return 1;
    }
    return 0;
}
void Solve()
{
    curPath.push_back(1);
    Dijkstras();
    if(dist[dst] >= inf || Cmin >= inf)
    {
        puts("-1");
        return;
    }
    QoS = dist[dst] + Cmin;
    BFS();
    DFS(1);
    if(paths.empty())
    {
        puts("-1");
        return;
    }
    sort(whole(paths), cmp);
    print(paths[kth-1].size()); pc(el);
    for(int x: paths[kth-1]) print(x), pc(sp);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
