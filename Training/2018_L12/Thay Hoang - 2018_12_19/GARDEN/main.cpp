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
#define task "GARDEN"
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

#define x real()
#define y imag()


//=====================================
//Auxiliary Functions and Fast I/O
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
const long double M_PI = acos((long double)-1.0000000000000000000000000000000000000000000000000000);
const long double eps  = 1e-160;

//=====================================
//Typedefs
struct Triangle
{
    typedef pair<int, int> ii;
    int v1, v2, v3, id;

    Triangle() {}
    Triangle(int px, int py, int pz, int id): v1(px), v2(py), v3(pz), id(id) {}

    void extractEdge(ii &e1, ii &e2, ii &e3)
    {
        e1 = {min(v1, v2), max(v1, v2)};
        e2 = {min(v2, v3), max(v2, v3)};
        e3 = {min(v3, v1), max(v3, v1)};
    }
};

//=====================================
//Typedefs
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<Triangle> vtri;
typedef pair<int, int> ii;
typedef map<ii, int> miii;
typedef vector<bool> vb;
typedef complex<ld> pt;
typedef vector<int> vi;
typedef vector<pt> vpt;
typedef vector<ld> vld;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<vld> vvld;
typedef set<ii> sii;
vtri triaList;          //List of triangles
vvi tree, adj;          //Tree: Final graph; Adj: Adjacency matrix of polygon.
ld baseAngle;           //Angle between 2 consecutive points of the polygon w/ root is the center of the polygon
vpt poly;               //Polygon Representation: CCW, from (1, 0).
vld area;               //Area of the triangle
vvld dp;                //DP array
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
    int u, v;

	scan(n);
	dp = vvld(n+1, vld(2, 0.00000000000000000000000000000000000000000000000000000000000000000));
	area = vld(n+1);
	poly = vpt(n+1);
	tree = vvi(n-1);
	adj = vvi(n+1);

	FOR(i, 1, n-3)
	{
	    scan(u);
	    scan(v);

	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	FORl(i, 0, n)
	{
	    adj[i].push_back((i+1) % n);
	    adj[(i+1) % n].push_back(i);
	}
	FORl(i, 0, n) sort(whole(adj[i]));
}

//Helper Functions
ld getArea(pt A, pt B, pt C)
{
    pt U = B - A;
    pt V = C - A;

    //cerr << __abs((conj(U) * V).y) << el;
    return __abs((conj(U) * V).y);
}
void addEdge(int u, ii edge, miii &mp, sii &edgeList)
{
    if(mp.count(edge))
    {
        int v = mp[edge];
        edgeList.insert(ii(min(u, v), max(u, v)));
    }
    else mp[edge] = u;
}

//Check
void genPoints()
{
    baseAngle = 2.000 * M_PI / n;

    FORl(i, 0, n)
    {
        ld _x = cos(baseAngle * i);
        ld _y = sin(baseAngle * i);
        poly[i] = pt(abs(_x) < eps ? 0.0 : _x, abs(_y) < eps ? 0.0 : _y);
    }
}
void genTriangle()
{
    int cnt = 0;
    FORl(i, 0, n)
    {
        FORl(j, 0, adj[i].size()-1) if(adj[i][j] > i)
        {
            triaList.push_back(Triangle(i, adj[i][j], adj[i][j+1], cnt++));
        }
    }


    FORl(i, 0, (int)triaList.size())
    {
        Triangle & tp = triaList[i];
        area[i] = getArea(poly[tp.v1], poly[tp.v2], poly[tp.v3]);
    }



//    cerr << "Area: \n";
//    FORl(i, 0, (int)triaList.size())
//    {
//        Triangle & tp = triaList[i];
//        cerr << tp.v1 << sp << tp.v2 << sp << tp.v3 << sp << fixed << setprecision(6) << area[i] << el;
//    }
}
void genTree()
{
    map<ii, int> edgePool;
    set<ii> edgeList;
    ii e1, e2, e3;
    int id;

    for(Triangle &p: triaList)
    {
        p.extractEdge(e1, e2, e3);

        addEdge(p.id, e1, edgePool, edgeList);
        addEdge(p.id, e2, edgePool, edgeList);
        addEdge(p.id, e3, edgePool, edgeList);
    }

    for(ii p: edgeList)
    {
        tree[p.first].push_back(p.second);
        tree[p.second].push_back(p.first);
    }
}

//Process
void DFS(int u, int p)
{
    dp[u][0] = 0.000000000000000000000000;
    dp[u][1] = area[u];


    for(int v: tree[u]) if(v != p)
    {
        DFS(v, u);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
}
void genResult()
{
    DFS(0, -1);
    ld max_sum_area = max(dp[0][0], dp[0][1]);
    ld result = (ld)max_sum_area / (sin(baseAngle) * (ld)n);
    cout << fixed << setprecision(10) << result;
}

//Output
void Solve()
{
    genPoints();
    genTriangle();
    genTree();
    genResult();
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
