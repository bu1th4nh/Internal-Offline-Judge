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
// #define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "FARM"
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
#define x real()
#define y imag()


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef complex<int> pt;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pt> vpt;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<vpt> vvpt;
int n, r, x0, y0;
vvpt polygons;
pt X;

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
    int u, v, p;

	scan(n);
	scan(r);
	scan(x0);
	scan(y0);

	X = pt(x0, y0);

	polygons = vvpt(r+1);
	FOR(i, 1, r)
	{
	    scanf("%d", &p);
	    FOR(j, 1, p)
	    {
            scan(u);
            scan(v);
            polygons[i].pb({u, v});
	    }
	    polygons[i].push_back(polygons[i][0]);
	}
}

//Check
bool onSeg(pt A, pt C, pt B)        //Check if C lies on [AB]
{
    return (min(A.x, B.x) <= C.x && C.x <= max(A.x, B.x) && min(A.y, B.y) <= C.y && C.y <= max(A.y, B.y));
}
int orien(pt A, pt B, pt C)
{
    int val = (B.y - A.y) * (C.x - B.x) - (B.x - A.x) * (C.y - B.y);

    if(val == 0) return 0;          //Collinear
    return (val > 0) ? 1 : 2;       //1: CW. 2:CCW
}
bool is_inter(pt p1, pt q1, pt p2, pt q2)
{
    int o1 = orien(p1, q1, p2);
    int o2 = orien(p1, q1, q2);
    int o3 = orien(p2, q2, p1);
    int o4 = orien(p2, q2, q1);

    if(o1 != o2 && o3 != o4) return 1;

    if(!o1 && onSeg(p1, p2, q1)) return 1;
    if(!o2 && onSeg(p1, q2, q1)) return 1;
    if(!o3 && onSeg(p2, p1, q2)) return 1;
    if(!o4 && onSeg(p2, q1, q2)) return 1;

    return 0;
}

//Process
void Sub12()
{
    int res = 0;
    bool ok = 1;
    pt Y;

    FOR(i, 0, n)
    {
        Y = pt(0, i);
        ok = 1;
        FOR(j, 1, r)
        {
            FORl(k, 1, polygons[j].size())
            {
                if(is_inter(polygons[j][k], polygons[j][k-1], X, Y))
                {
                    ok = 0;
                    break;
                }
            }
            if(!ok) break;
        }
        res += ok;
    }

    FOR(i, 0, n)
    {
        Y = pt(n, i);
        ok = 1;
        FOR(j, 1, r)
        {
            FORl(k, 1, polygons[j].size())
            {
                if(is_inter(polygons[j][k], polygons[j][k-1], X, Y))
                {
                    ok = 0;
                    break;
                }
            }
            if(!ok) break;
        }
        res += ok;
    }


    FORl(i, 1, n)
    {
        Y = pt(i, 0);
        ok = 1;
        FOR(j, 1, r)
        {
            FORl(k, 1, polygons[j].size())
            {
                if(is_inter(polygons[j][k], polygons[j][k-1], X, Y))
                {
                    ok = 0;
                    break;
                }
            }
            if(!ok) break;
        }
        res += ok;
    }

    FORl(i, 1, n)
    {
        Y = pt(i, n);
        ok = 1;
        FOR(j, 1, r)
        {
            FORl(k, 1, polygons[j].size())
            {
                if(is_inter(polygons[j][k], polygons[j][k-1], X, Y))
                {
                    ok = 0;
                    break;
                }
            }
            if(!ok) break;
        }
        res += ok;
    }

    cout << res << el;
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Sub12();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
