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

// #define DEBUG
#define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "COLORING"
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
    template<class T> T __abs(T x)
    {
        return (x = (x < 0) ? -x : x);
    }
#endif
//Fast I/O
template<class T> inline void scan(T &ret)
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
const long double eps = 1e-6;


//=====================================
//Typedefs
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef complex<int> pt;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pt> vpt;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vpt> vvpt;
typedef vector<vii> vvii;
vvi graph;
vii vect;
int m, n;
vvi adj;
vi res;

//=====================================
//Functions and procedures
//File I/O and utilities
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    #ifndef DEBUG
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
	scan(n);
	scan(m);

	res = vi(n+1);
	vect = vii(n+1);
	FOR(i, 1, n)
	{
	    scan(u);
	    scan(v);
	    vect[i] = {u, v};
	}
}

//Subtask 1: Brute-force
vi sampler;
bool global_ok;
bool ST1check(vi &smp)
{
    FOR(i, 1, n)
    {
        FOR(j, 1, n) if(i != j && smp[i] == smp[j] && adj[i][j]) return 0;
    }
    return 1;
}
void Attempt(int i)
{
    if(global_ok) return;
    FOR(j, 1, m)
    {
        sampler[i] = j;
        if(i == n)
        {
            global_ok = ST1check(sampler);
        }
        else Attempt(i+1);

        if(global_ok)
        {
            res = sampler;
            return;
        }
    }
}
bool Subtask1()
{
    global_ok = 0;
    sampler = vi(n+1, 0);
    Attempt(1);
    return global_ok;
}



//Subtask 2: Check graph is bipartite
bool ST2BFS(int start, vi &color)
{
    queue<int> que;
    que.push(start);
    color[start] = 1;

    while(!que.empty())
    {
        int u = que.front();
        que.pop();

        for(int v: graph[u])
        {
            if(color[v] == color[u]) return 0;
            else if(color[v] == -1)
            {
                color[v] = 3 - color[u];
                que.push(v);
            }
        }
    }

    return 1;
}
bool Subtask2()
{
    vi color = vi(n+1, -1);
    FOR(i, 1, n) if(color[i] == -1)
    {
        if(!ST2BFS(i, color)) return 0;
    }
    res = color;
    return 1;
}



//Subtask 3: Line
typedef pair<ii, int> iii;
typedef vector<iii> viii;
void Subtask3()
{
    viii pool(n+1);
    FOR(i, 1, n)
    {
        pool[i] = {vect[i], i};
    }
    sort(whole_1(pool));
    FOR(i, 1, n) res[pool[i].se] = (i - 1) % m + 1;
    FOR(i, 1, n) cout << res[i] << sp;
}



//Subtask 4: gReEdY iS GooD
typedef bitset<10> bs;
typedef vector<bs> vbs;
bool ST2_cmp(bs x, bs y)
{
    return x.count() < y.count();
}
bool Subtask4()
{

    vbs candidate(n+1, bs((1 << m) - 1));
    vi color(n+1, 0);
    vb done(n+1, 0);

    int matched = n;

    while(matched > 0)
    {
        FOR(i, 1, n)
        {
            int id = min_element(whole_1(candidate), ST2_cmp) - candidate.begin();
            if(!candidate[id].any()) return 0;

            color[id] = __builtin_ctz(candidate[id].to_ulong()) + 1;
//            cerr << color[id] << el;

            candidate[id].set();
            done[id] = 1;
            --matched;

            if(matched <= 0)
            {
//                cerr << "Done!\n";

                res = color;
                return 1;
            }

            for(int v: graph[id]) if(!done[v]) candidate[v].reset(color[id]-1);


//            FOR(i, 1, n) cerr << i << ": " << candidate[i] << el;
//            cerr << el;
//            getchar();
        }
    }

//    cerr << "Done!\n";
    res = color;
    return 1;
}



//Process
ll sqr_dist(ii A, ii B)
{
    return 1LL * (A.fi - B.fi) * (A.fi - B.fi) + 1LL * (A.se - B.se) * (A.se - B.se);
}
void gen_graph(ll x, vvi &adj_matrix, vvi &adj_list)
{
    adj_matrix = vvi(n+1, vi(n+1, 0));
    adj_list = vvi(n+1);

    FOR(i, 1, n)
    {
        FOR(j, 1, n) if(i != j) if(sqr_dist(vect[i], vect[j]) < x)
        {
            adj_matrix[i][j] = 1;
        }
    }

    FOR(i, 1, n) FOR(j, 1, n) if(adj_matrix[i][j])
    {
        adj_list[i].pb(j);
    }
}



//Output
bool checkCollinear(ii A, ii B, ii C)
{
    ii p1(B.fi - A.fi, B.se - A.se);
    ii p2(C.fi - A.fi, C.se - A.se);

    return p1.fi * p2.se == p2.fi * p1.se;
}
bool SubtaskControl()
{
    if(m == 2) return Subtask2();
    else if(n <= 8) return Subtask1();
    else return Subtask4();

//    return Subtask4();
}
void BinarySearch()
{
    ll L = 0LL, R = 1000000000009, mid = 0LL;
    while(L <= R)
    {
        mid = (L + R) >> 1;
        gen_graph(mid, adj, graph);


        if(SubtaskControl())
        {
            L = mid + 1;
        }
        else R = mid - 1;
    }
}
void Solve()
{
    FOR(i, 3, n) if(!checkCollinear(vect[1], vect[2], vect[i]))
    {
        BinarySearch();
        FOR(i, 1, n)
        {
            print(res[i]);
            putchar(sp);
        }
        return;
    }
    Subtask3();
}



//Main Procedure
int main()
{
    //FileDebug();
    FileInit();
    Enter();
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
