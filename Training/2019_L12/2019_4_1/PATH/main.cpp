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
#define task "PATHS"
#define maxinp ()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
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
    template<class T> T __sqr(T __X)
    {
        return __X * __X;
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
const long long mod = 1000000007;


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef tuple<ll, int, int> iii;
typedef pair<ll, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<iii> viii;
vll dist, from, to, res;
viii edgeList;
vi orders;
vvii adj;
int n, m;


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
template<class T> void add(T &__X, T __Y)
{
    __X = (__X + __Y) % mod;
}


//Enter
void Enter()
{
    int u, v, w;
    scan(n);
    scan(m);

    adj = vvii(n+1);
    res = vll(m, 0LL);

    FOR(i, 1, m)
    {
        scan(u);
        scan(v);
        scan(w);

        adj[u].emplace_back(w, v);
        edgeList.emplace_back(w, u, v);
    }
    FOR(i, 1, n) sort(whole(adj[i]), [](ii x, ii y){return x.se < y.se;});
}

//Check
void Dijkstras(int start)
{
    int u, v;
    ll du, uv;
    priority_queue<ii, vii, greater<ii>> pq;

    orders = vi(1, 0);
    dist = vll(n+1, mod);
    from = to = vll(n+1, 0LL);
    pq.emplace(dist[start] = 0LL, start);
    to[start] = 1;

    while(!pq.empty())
    {
        du = pq.top().first;
        u = pq.top().second;
        pq.pop();

        if(du != dist[u]) continue;
        orders.emplace_back(u);

        for(ii p: adj[u])
        {
            v = p.second;
            uv = p.first;
            if(du + uv < dist[v])
            {
                to[v] = to[u];
                pq.emplace(dist[v] = du + uv, v);
            }
            else if(du + uv == dist[v]) add(to[v], to[u]);
        }
    }

    FORb(i, int(orders.size())-1, 1)
    {
        u = orders[i];
        from[u] = 1LL;
        for(ii x: adj[u]) if(dist[u] + x.fi == dist[x.se])
        {
            add(from[u], from[x.se]);
        }
    }


    FORl(i, 0, m)
    {
        tie(uv, u, v) = edgeList[i];
        if(dist[u] + uv == dist[v]) add(res[i], (1LL * to[u] * from[v]) % mod);
    }

    cout << el;
    FORl(i, 1, orders.size()) cout << orders[i] << sp; cout << el;
    cout << "From: "; FOR(i, 1, n) cout << from[i] << sp; cout << el;
    cout << "To:   "; FOR(i, 1, n) cout << to[i] << sp; cout << el;
    cout << "res:  "; for(ll x: res) print(x), pc(sp);
    cout << el;
}

//Process
void Solve()
{
    FOR(i, 1, n)
    {
        Dijkstras(i);
    }
    for(ll x: res) print(x), pc(el);
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
