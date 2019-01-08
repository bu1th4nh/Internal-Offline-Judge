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
// #define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "RPS"
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



//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vii> vvii;
vi dist, root, avail, ok;
vvi adj, g;
int n;

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
    char str[8192];
	scanf("%d", &n);

	adj = vvi(n+1);
    avail = vi(n+1, 1);
    ok = dist = root = vi(n+1, 0);
	g = vvi(n+1, vi(n+1, 0));

	FOR(i, 1, n)
	{
	    scanf("%s", &str);
	    FOR(j, 1, n) if(str[j-1] == '1')
	    {
	        adj[i].pb(j);
	        g[i][j] = 1;
	    }
	}



//	FOR(i, 1, n)
//	{
//	    cerr << i << ": ";
//	    for(int j: adj[i]) cerr << j << sp;
//	    cerr << el;
//	}
}

//Check
void Sub1()
{
    ok = vi(n+1, 0);
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            FOR(k, 1, n)
            {
                if(g[i][j] && g[j][k] && g[k][i])
                {
                    ok[i] = ok[j] = ok[k] = 1;
                }
            }
        }
    }
    cout << accumulate(whole_1(ok), 0) << el;
}

//Process
void DFS(int u, int par, int most_anc)
{
    //cerr << u << sp << par << sp << most_anc << el;

    avail[u] = 0;
    root[u] = most_anc;

    //cerr << dist[u] << sp;

    for(int v: adj[u])
    {
        if(avail[v] == 0)
        {
            if(abs(dist[v] - dist[u]) == 2)
            {
                ok[u] = ok[par] = ok[v] = 1;
                //cerr << "Detected\n";
            }
        }
        else
        {
            dist[v] = dist[u] + 1;
            DFS(v, u, most_anc);
        }
    }
}
void Sub2()
{
    ok = vi(n+1, 0);

    FOR(i, 1, n)
    {
        avail = vi(n+1, 1);
        dist = vi(n+1, 0);
        dist[i] = 1;
        DFS(i, -1, i);
    }

    cout << accumulate(whole_1(ok), 0) << el;
}


//Output
void Solve()
{
    if(n <= 200) Sub1();
    else Sub2();
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
