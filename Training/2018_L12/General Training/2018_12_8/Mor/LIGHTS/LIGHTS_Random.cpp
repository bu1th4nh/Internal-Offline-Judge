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
#define task "LIGHTS"
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
const int inf = 1000000000;
const int nextx[4] = {-1, 0, 0, 1};
const int nexty[4] = {0, -1, 1, 0};



mt19937_64 prng(chrono::high_resolution_clock::now().time_since_epoch().count());
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
typedef queue<ii> qii;
vvi dist, a, avail, pck;
qii que, que_2;
int w, h, n;
vii lights;

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
	scan(w);
	scan(h);
	scan(n);

	a = vvi(w+2, vi(h+2, 0));
	dist = vvi(w+2, vi(h+2, inf));
    avail = pck = vvi(w+2, vi(h+2, 1));

	FOR(i, 1, n)
	{
	    scan(u);
	    scan(v);

	    pck[u][v] = 0;
	    dist[u][v] = 0;
	    avail[u][v] = 0;
	    que_2.push(ii(u, v));
	    lights.push_back(ii(u, v));
	}

}

//Check
int BFS(ii add)
{
    int ret = 0;
    int curx, cury, x, y;

    avail = vvi(w+2, vi(h+2, 1));
	dist = vvi(w+2, vi(h+2, inf));
	FOR(i, 0, w+1) avail[i][0] = avail[i][h+1] = -1;
	FOR(i, 0, h+1) avail[0][i] = avail[w+1][i] = -1;


    for(ii x: lights)
    {
        dist[x.first][x.second] = 0;
        avail[x.first][x.second] = 0;
        que.push(x);
    }
    avail[add.first][add.second] = 0;
    dist[add.first][add.second] = 0;
    que.push(add);

    cerr << "Random Candidate: " << add.fi << sp << add.se << sp << dist[add.fi][add.se] << sp << avail[add.fi][add.se] <<el;


    FOR(i, 1, w) FOR(j, 1, h) if(dist[i][j] != 0) dist[i][j] = inf;
    while(!que.empty())
    {
        curx = que.front().first;
        cury = que.front().second;
        que.pop();

        FOR(i, 0, 3)
        {
            x = curx + nextx[i];
            y = cury + nexty[i];

            if(avail[x][y] >= 0)
            {
                if(avail[x][y] == 1)
                {
                    que.push(ii(x, y));
                    avail[x][y] = 0;
                }
                minimize(dist[x][y], dist[curx][cury] + 1);
            }
        }
    }


//    FOR(i, 1, w)
//    {
//        FOR(j, 1, h) cerr << dist[i][j] << sp;
//        cerr << el;
//    }


    FOR(i, 1, w) FOR(j, 1, h) if(dist[i][j] != 0 && dist[i][j] != inf) maximize(ret, dist[i][j]);
    dist[add.first][add.second] = inf;
    while(!que.empty()) que.pop();


    return ret;
}


//Process
int rand_int(int l, int r)
{
    uniform_int_distribution<> die(l, r);
    return die(prng);
}
void Solve()
{
    ii res2, add(0, 0);
    int tmp, res = inf;
    pck[0][0] = 0;

    int nRand = 50;
    while(nRand--)
    {
        do add = ii(rand_int(1, w), rand_int(1, h));
        while(pck[add.first][add.second] == 0);
        tmp = BFS(add);

        if(res > tmp) res = tmp, res2 = add;
    }
    cout << res << el;
    cout << res2.first << sp << res2.second;
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
