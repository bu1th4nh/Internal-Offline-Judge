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
    template<class T> T __abs(T x)
    {
        return (x = (x < 0) ? -x : x);
    }
    template<class T> bool inRange(T x, T L, T R)
    {
        return L <= x && x <= R;
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


//=====================================
//Typedefs
struct Playzone
{
/*  O----------->(j)
    |                   bot_l_diag <-- O         O --> bot_r_diag
    |                                   \       /
    |                                    \     /
    |                                     \   /
    |                                      \ /
    |                                       X
    V                                      / \
   (i)                                    /   \
                top_l_diag <-- O         /     \         O --> top_r_diag
                                \       /       \       /
                                 \     /         \     /
                                  \   /           \   /
                                   \ /             \ /
                                    X       O       X
                                   / \             / \
                                  /   \           /   \
                                 /     \         /     \
                                /       \       /       \
                               /         \     /         \
                                          \   /
                                           \ /
                                            X
                                           / \
                                          /   \
                                         /     \
                                        /       \
*/


    int top_l_diag;
    int top_r_diag;
    int bot_l_diag;
    int bot_r_diag;

    Playzone() {}
    Playzone(int tld, int trd, int bld, int brd): top_l_diag(tld), top_r_diag(trd), bot_l_diag(bld), bot_r_diag(brd) {}

    void debug()
    {
        cerr << "Debug Playzone: " << top_l_diag << sp << top_r_diag << sp
             << bot_l_diag   << sp << bot_r_diag << el;
    }
    void restrictPlayerArea(const Playzone &pz)
    {

        #ifdef DEBUG
        fprintf(stderr, "Restrict: %d %d %d %d <-> %d %d %d %d\n",
                top_l_diag, top_r_diag, bot_l_diag, bot_r_diag,
                pz.top_l_diag, pz.top_r_diag, pz.bot_l_diag, pz.bot_r_diag);
        #endif // DEBUG


        minimize(top_l_diag, pz.top_l_diag);
        minimize(top_r_diag, pz.top_r_diag);
        maximize(bot_l_diag, pz.bot_l_diag);
        maximize(bot_r_diag, pz.bot_r_diag);


        #ifdef DEBUG
        fprintf(stderr, "Result: %d %d %d %d\n", top_l_diag, top_r_diag, bot_l_diag, bot_r_diag);
        #endif // DEBUG
    }
    bool isInPlayzone(int x, int y)
    {
        return inRange(x-y, bot_l_diag, top_l_diag) && inRange(x+y, bot_r_diag, top_r_diag);
    }
    bool isValid()
    {
        return top_l_diag >= bot_l_diag &&
               top_l_diag <= top_r_diag &&
               bot_l_diag <= bot_r_diag &&
               top_r_diag >= bot_r_diag;
    }
};


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
vvi dist, a, avail;
int w, h, n;
qii que;
ii res;

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


	res = ii(inf, inf);
	a = vvi(w+2, vi(h+2, 0));
    avail = vvi(w+2, vi(h+2, 1));
	dist = vvi(w+2, vi(h+2, inf));

	FOR(i, 1, n)
	{
	    scan(u);
	    scan(v);
	    dist[u][v] = 0;
	    avail[u][v] = 0;
	    que.push(ii(u, v));
	}

	FOR(i, 0, w+1) avail[i][0] = avail[i][h+1] = -1;
	FOR(i, 0, h+1) avail[0][i] = avail[w+1][i] = -1;
}

//Check
void BFS()
{
    int curx, cury, x, y;
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
}
bool checkDarknessLevel(int level)
{
    Playzone PUBG(inf, inf, -inf, -inf);
    FOR(i, 1, w)
    {
        FOR(j, 1, h) if(dist[i][j] > level)
        {

            #ifdef DEBUG
                cerr << "Diff: " << i << sp << j << el;
                fprintf(stderr, "Will modify: %d %d %d %d\n", i-j+level, i+j+level, i-j-level, i+j-level);
            #endif // DEBUG




            PUBG.restrictPlayerArea(Playzone(i-j+level, i+j+level, i-j-level, i+j-level));
            if(!PUBG.isValid()) return 0;
        }
    }

    #ifdef DEBUG
    PUBG.debug();
    #endif // DEBUG




    FOR(i, 1, w)
    {
        FOR(j, 1, h) if(PUBG.isInPlayzone(i, j))
        {
            res = ii(i, j);
            return 1;
        }
    }
    return 0;
}

//Process
void Solve()
{
    BFS();
    int l = 0, r = 8192, mid = 0, res1 = inf;
    while(l <= r)
    {
        mid = (l + r) / 2;

        #ifdef DEBUG
            fprintf(stderr, "With l = %d, r = %d, mid = %d\n", l, r, mid);
        #endif // DEBUG


        if(checkDarknessLevel(mid))
        {
            res1 = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res1 << el;
    cout << res.fi << sp << res.se;
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
