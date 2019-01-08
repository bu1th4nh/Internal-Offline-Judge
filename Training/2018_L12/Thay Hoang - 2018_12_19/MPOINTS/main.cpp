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

 #define DEBUG
 #define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "MPOINTS"
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
const long long inf = 1LL << 62;


//=====================================
//Typedefs
namespace Geometry
{
    typedef long long ll;
    typedef complex<ll> pt;
    typedef vector<pt> vpt;

    #define x real()
    #define y imag()


    long long operator| (const pt &u, const pt &v) //Dot
    {
        return (conj(u)*v).x;
    }
    long long operator^ (const pt &u, const pt &v) //Cross
    {
        return (conj(u)*v).y;
    }
    long long sqr_len (const pt &u)
    {
        //assert(u.x <= 2e9 && u.y <= 2e9);
        return u.x * u.x + u.y * u.y;
    }
    int orient(pt A, pt B, pt C)
    {
        ll tmp = (B - A) ^ (C - B);

        if(tmp < 0) return -1;
        return (tmp != 0) ? 1 : 0;
    }
}
using namespace Geometry;

//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ii;
typedef vector<bool> vb;
typedef complex<ll> pt;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
pt top_l, roots, bot_r;
vi from_1, from_n;
vpt hull, pts;
int n, m, k;
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
    int u, v;
    ll w;

    scan(n);
    scan(m);
    scan(k);

    pts.clear();
    adj = vvii(n+1);
    from_1 = from_n = vi(n+1, inf);

    FOR(i, 1, m)
    {
        scan(u);
        scan(v);
        scan(w);

        adj[u].pb(ii(w, v));
    }
}

//Check
void Dijkstras(int start, vi &d)
{
    int u;
    ll du;

    priority_queue<ii, vii, greater<ii>> pq;
    pq.push(ii(0LL, start));
    d[start] = 0;

    while(!pq.empty())
    {
        du = pq.top().first;
        u = pq.top().second;
        pq.pop();

        if(du != d[u]) continue;

        for(ii p: adj[u])
        {
            if(d[p.se] > du + p.fi) pq.push(ii(d[p.se] = du + p.fi, p.se));
        }
    }
}


//Process
void Preps()
{
    Dijkstras(1, from_1);
    Dijkstras(n, from_n);
    FOR(i, 1, n) if(from_1[i] < inf && from_n[i] < inf)
    {
        pts.push_back(pt(from_1[i], from_n[i]));
    }



    roots = pts[0];
    for(pt p: pts)
    {
        if(p.y < roots.y || (p.y == roots.y && p.x < roots.x)) roots = p;
    }
}
void getConvexHull()
{
    int nHull = 0;
    //Graham Scan
    sort(whole(pts), [](const pt &B, const pt &C)
    {
        pt u = B - roots;
        pt v = C - roots;
        ll t = u ^ v;

        return t > 0 || (t == 0 && sqr_len(u) < sqr_len(v));
    });

                            #ifdef DEBUG
                                //cerr << "GrahamScan data:  \n";
                                //for(pt p: pts) cerr << p << el;
                            #endif // DEBUG


    //Find convex hull
    hull = vpt(n+1, pt(0, 0));
    for(pt p: pts)
    {
        while(nHull >= 2 && orient(hull[nHull-2], hull[nHull-1], p) < 0) --nHull;
        hull[nHull++] = p;
    }
    while((int)hull.size() > nHull) hull.pop_back();


                            #ifdef DEBUG
                                //cerr << "Stage 0 data:  \n";
                                //for(pt p: hull) cerr << p << el;
                            #endif // DEBUG


    //Find endpoints
    bot_r = top_l = hull[0];
    for(pt p: hull)
    {
        /*
            top_l: min x, max y
            top_r: min y, max x
        */


        if(p.x < top_l.x) top_l = p;
        if(p.y < bot_r.y) bot_r = p;
    }
}
#define what_is(x) cerr << #x << " is " << x << endl;
void getConvexLine()
{
    //assert(hull[0] == roots);
    int pos1, pos2;

    FORb(i, (int)hull.size()-1, 0) if(hull[i] == bot_r) {pos1 = i; break;}
    FORl(i, 0,   (int)hull.size()) if(hull[i] == top_l) {pos2 = i; break;}


//    what_is(hull.size());
//    what_is(top_l); cerr << "Pos TL = " << pos2 << el;
//    what_is(bot_r); cerr << "Pos BR = " << pos1 << el;
//
//
//
//    cerr << el;
//    FOR(i, 0, 10) cerr << hull[i] << el;
//    cerr << el;
//    FORb(i, hull.size()-1, hull.size()-10) cerr << hull[i] << el;
//    cerr << el;


    pts.clear();
    pts.push_back(pt(0LL, inf));
    FOR(i, 0, pos1)            pts.push_back(hull[i]);
    FORl(i, pos2, hull.size()) pts.push_back(hull[i]);
    pts.push_back(pt(inf, 0));


    n = pts.size()-2;


                            #ifdef DEBUG
                                //cerr << "Final data:  \n";
                                //for(pt p: pts) cerr << p << el;
                            #endif // DEBUG


//    assert(is_sorted(whole(pts), [](const pt &B, const pt &C)
//    {
//        return B.x < C.x;
//    }));


}

//Output
void Query(pt A)
{
    int l, r, mid, pos;
    ll tmp, res = inf;


    FOR(i, 1, n) minimize(res, (pts[i] | A));


//    l = 1, r = n;
//    while(l <= r)
//    {
//        mid = (l + r) / 2;
//        if((pts[mid] | A) >= (pts[mid+1] | A))
//        {
//            pos = mid + 1;
//            l = mid + 1;
//        }
//        else r = mid - 1;
//    }
//
//    res = pts[pos] | A;
    print(res); putchar(el);
}
void Solve()
{
    ll u, v;
    getConvexHull();
    getConvexLine();

    while(k--)
    {
        scan(u);
        scan(v);
        Query(pt(u, v));
    }
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Preps();
    Solve();

    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//


/*
void testConvexLine()
{
    pts.push_back(pt(1 , 11));
    pts.push_back(pt(1 , 10));
    pts.push_back(pt(1 , 9));
    pts.push_back(pt(1 , 8));
    pts.push_back(pt(2 , 6));
    pts.push_back(pt(4 , 4));
    pts.push_back(pt(5 , 3));
    pts.push_back(pt(7 , 2));
    pts.push_back(pt(9 , 1));
    pts.push_back(pt(10 , 3));
    pts.push_back(pt(11 , 2));
    pts.push_back(pt(6 , 5));
    pts.push_back(pt(13 , 6));
    pts.push_back(pt(13 , 1));
    pts.push_back(pt(15 , 0));
    pts.push_back(pt(16 , 0));
    pts.push_back(pt(17 , 0));
    pts.push_back(pt(18 , 0));
    pts.push_back(pt(19 , 0));
    pts.push_back(pt(20 , 8));
    pts.push_back(pt(13 , 11));
    pts.push_back(pt(8 , 12));
    pts.push_back(pt(8 , 7));
    pts.push_back(pt(5 , 12));
    pts.push_back(pt(3 , 11));


    n = pts.size() + 1;

    roots = *min_element(whole(pts), [](const pt &B, const pt &C)
    {
        //Has y as small as possible. If the same y, minimize x
        return ii(B.y, B.x) < ii(C.y, C.x);
    });
    bot_r = *min_element(whole(pts), [](const pt &B, const pt &C)
    {
        //Has y as small as possible. If the same y, maximize x
        return ii(B.y, -B.x) < ii(C.y, -C.x);
    });
    top_l = *min_element(whole(pts), [](const pt &B, const pt &C)
    {
        //Has x as small as possible. If the same x, maximize y
        return ii(B.x, -B.y) < ii(C.x, -C.y);
    });


    getConvexHull();
    getConvexLine();

}

*/
