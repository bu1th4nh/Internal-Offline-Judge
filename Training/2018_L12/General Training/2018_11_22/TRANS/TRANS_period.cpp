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
#endif // __cplusplus

using namespace std;

// #define DEBUG
#define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "TRANS"
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
    template<class T, class R> T max(T &x, R &y)
    {
        return x > y ? x : y;
    }
    template<class T, class R> T min(T &x, R &y)
    {
        return x < y ? x : y;
    }
    template<class T, class R> void maximize(T &x, R y)
    {
        x = x > y ? x : y;
    }
    template<class T, class R> void minimize(T &x, R y)
    {
        x = x < y ? x : y;
    }
    template<class T> int getBit(T &x, int i)
    {
        return ((x >> i) & 1) == 1;
    }
    template<class T> T __abs(T &x)
    {
        return (x = (x < 0) ? -x : x);
    }
#endif
//Fast I/O
template<class T> inline void read(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret = (neg) ? -ret : ret;

    #ifdef DEBUG
        cerr << "FastScan Diagnostic: " << ret << el;
    #endif
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
//Constants
const long long inf = 10000000007LL;


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
vi count_dist, period, ps, d;
vb avail;
int n, m;
vvi adj;
ll k;

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
    int u, v;
    read(n);
    read(m);
    read(k);

    count_dist = ps = vi(n+5, 0LL);
    period = vi(3*n+1, 0LL);
    avail = vb(n+1, 1);
    d = vi(n+1, inf);
    adj = vvi(n+1);

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

//Check
void sub1()
{
    assert(m == n-1 && adj[1].size() == n-1);
    ll res = k / (n-1) + int(k % (n-1) != 0);
    cout << res << el;
}
void BFS()
{
    int u;
    queue<int> q;

    q.push(1);
    d[1] = 0LL;
    avail[1] = 0;

    while(!q.empty())
    {
        u = q.front(); q.pop();
        for(int v: adj[u])
        {
            if(avail[v])
            {
                avail[v] = 0;
                q.push(v);
            }
            d[v] = min(d[v], d[u] + 1);
        }
    }

    //FOR(i, 2, n) cerr << d[i] << sp; cerr << el;
    FOR(i, 2, n) if(d[i] < inf) ++count_dist[d[i]];
}

//Subtask A - K, N is less than 1000
void SubA()
{
    int p = 0;
    while(k > 0)
    {
        ++p;
        FOR(i, 1, n) if(p % i == 0) k -= count_dist[i];
    }
    cout << p << el;
}

//Subtask B - Otherwise
void SubB()
{
    int max_dist = *max_element(whole_1(d));
    assert(max_dist < inf);


    FOR(i, 1, max_dist)
    {
        for(int j = i; j <= 2 * n; j += i)
        {
            period[j] += count_dist[i];
        }
    }
    FOR(i, 1, n) ps[i] = ps[i-1] + period[i];

//    FOR(i, 1, 3*n)
//    {
//        cerr << period[i] << sp;
//        if(i % n == 0) cerr << "___ ";
//    }
//    cerr << el;


    ll rem = k % ps[n];
    int pt = lower_bound(whole(ps), rem) - ps.begin();


    ll res = 1LL * n * (k / ps[n]) + pt;
    print(res); putchar(el);
}

//Process
void Solve()
{
    if(k == 0)
    {
        cout << 0;
        return;
    }


    if(m == n-1 && adj[1].size() == n-1) sub1();
    else
    {
        BFS();

        if(k <= 1000 && n <= 1000) SubA();
        else SubB();

//        SubB();
    }
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
