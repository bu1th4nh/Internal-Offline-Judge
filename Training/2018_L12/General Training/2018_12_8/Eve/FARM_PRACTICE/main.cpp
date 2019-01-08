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
//Geometry
namespace Geometry
{
    #define x real()
    #define y imag()

    #define P_COLLINEAR         0
    #define P_CLOCKWISE         -1
    #define P_COUNTER_CLOCKWISE 1


    typedef long long ll;
    typedef long double ld;
    typedef complex<ld> pt;
    typedef complex<ld> vct;        //Vector <=> Point


    ll sq_dist(vct u)
    {
        return 1LL*u.x*u.x + 1LL*u.y*u.y;
    }
    ll dot(vct A, vct B)
    {
        /** Return dot product between vector A and B **/
        return (conj(A)*B).x;
    }
    ll cross(vct A, vct B)
    {
        /** Return cross product between vector A and B **/
        return (conj(A)*B).y;
    }
    int orientation(pt A, pt B, pt C)
    {
        /** \brief Compute the orientation between triplet (A,B,C)
         * \return Return 0 if A,B,C collinear, 1 if A->B->C is counter-clockwise, -1 otherwise
         */

        int p = cross(B - A, C - A);
        if(p == 0) return P_COLLINEAR;
        else return p > 0 ? P_COUNTER_CLOCKWISE : P_CLOCKWISE;
    }


    bool cmpAngle(pt A, pt B, pt C1, pt C2)
    {
        /** \brief Check if angle BAC1 < BAC2
         * \return Return true if BAC1 < BAC2, false otherwise
         */

        /*
        vct u = B - A;
        vct v1 = C1 - A;
        vct v2 = C2 - A;

        ld x1 = 1.0 * dot(v1, u) * dot(v1, u) * sq_dist(v2);
        ld x2 = 1.0 * dot(v2, u) * dot(v2, u) * sq_dist(v1);

        cerr << el << x1 << sp << x2 << el;
        */

        return orientation(B, A, C1) * orientation(C1, A, C2) >= 0;
    }


    ld calcHorizontal(pt A, pt B, ll y_value)
    {
        /** \brief Compute the approximate intersection point between ray AB and y = y_value
         * \return A double value representing the approx. value of x.
         */

        vct v1 = B - A;
        if(v1.y == 0) return -999.00000000000000000000;

        ll alpha = (1LL * A.x * v1.y - 1LL * A.y * v1.x);
        return ld(alpha + y_value * v1.x) / ld(v1.y);  //->x
    }
    ld calcVertical(pt A, pt B, ll x_value)
    {
        /** \brief Compute the approximate intersection point between ray AB and x = x_value
         * \return A double value representing the approx. value of y.
         */

        vct v1 = B - A;
        if(v1.x == 0) return -999.00000000000000000000;

        ll alpha = (1LL * A.x * v1.y - 1LL * A.y * v1.x);
        return ld(x_value * v1.y - alpha) / ld(v1.x);   //->y
    }

}
using namespace Geometry;
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


typedef vector<pt> vpt;
typedef vector<vpt> vvpt;


vb hor_0, hor_n, ver_0, ver_n;      
/* 
 * hor_0: y = 0, not included (0, 0) and (n, 0)
 * hor_n: y = n, not included (0, n) and (n, n)
 * ver_0: x = 0, incl. (0, 0) and (0, n)
 * ver_n: x = n, incl. (n, 0) and (n, n)
 */
vpt RightmostList;
vpt LeftmostList;
int n, nPolygons;
vvpt PolygonList;
vi sizePolygons;
pt initial;


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
template<class T> bool inRange(T l, T r, T value)
{
    return l <= value && value <= r;
}
bool isInPoly(pt O, pt A, pt B, pt C) //Check if C lies in range OA->OB
{
    return (inRange((ld)0, (ld)n, C.x) && inRange((ld)0, (ld)n, C.y) && orientation(A, O, C) >= 0 && orientation(C, O, B) >= 0);     
}
pt integerize(pt A, pt shift)
{
    pt ret = {trunc(A.x), trunc(A.y)};

    //cerr << ret + shift << el;

    return ret + shift;
}
void findProperPoint(pair<pt, int> &inter_point, int factor, pt O, pt A, pt B)
{
    //Factor = 1: CCW, Factor = -1: CW
    FOR(i, -2, 2)
    {
        pt integerized_point, shifter_point;
        switch(inter_point.second)
        {
            case 0: shifter_point = (ld)factor * pt(-i, 0); break;
            case 1: shifter_point = (ld)factor * pt(0, -i); break;
            case 2: shifter_point = (ld)factor * pt(i,  0); break;
            case 3: shifter_point = (ld)factor * pt(0,  i); break;
        }
        integerized_point = integerize(inter_point.fi, shifter_point);
        if(isInPoly(O, A, B, integerized_point))
        {
            inter_point.fi = integerized_point;
            //cerr << "Picked: " << integerized_point << "!" << el;
            break;
        }
    }
}

//Enter
void Enter()
{
    int u, v, p;
    scanf("%d%d", &n, &nPolygons);
    scanf("%d%d", &u, &v);
    initial = {u, v};


    PolygonList = vvpt(nPolygons+1);
    sizePolygons = vi(nPolygons+1, 0);
    hor_0 = hor_n = ver_0 = ver_n = vb(n+3, 1);
    RightmostList = LeftmostList = vpt(nPolygons+1);

    FOR(i, 1, nPolygons)
    {
        scanf("%d", &p);
        sizePolygons[i] = p;
        PolygonList[i].resize(p+1);

        FOR(j, 1, p)
        {
            scanf("%d%d", &u, &v);
            PolygonList[i][j] = {u, v};
        }
    }
}

//Check
void Filter()
{
    /*  From an arbitrary point A and initial point O, find the
     *  leftmost and rightmost point X such that angle (AOX) is maximum.
     */

    FOR(iPoly, 1, nPolygons)
    {
        vpt &poly = PolygonList[iPoly];
        pt &rm = RightmostList[iPoly];
        pt &lm = LeftmostList[iPoly];
        int sz = sizePolygons[iPoly];

        lm = rm = poly[1];
        pt A = poly[1];
        pt O = initial;

        cerr << "At polygon #" << iPoly << ", pt A = " << A << el;

        FOR(i, 2, sz)
        {
            if(orientation(A, O, poly[i]) == P_COUNTER_CLOCKWISE)
            {
                cerr << poly[i] << " is counter-cw";
                if(cmpAngle(O, A, lm, poly[i])) lm = poly[i], cerr << " - expanded to" << lm;
                cerr << el;
            }
            else if(orientation(A, O, poly[i]) == P_CLOCKWISE)
            {
                cerr << poly[i] << " is clockwise";
                if(cmpAngle(O, A, rm, poly[i])) rm = poly[i], cerr << " - expanded to" << rm;
                cerr << el;
            }
        }


        if(orientation(lm, O, rm) == P_CLOCKWISE) swap(lm, rm);         //Sort the LM and RM pairs counterclockwise
    }

    //cerr << el;
    //FOR(i, 1, nPolygons) cerr << LeftmostList[i] << sp << RightmostList[i] << el;
}
void parseCoord(pt O, pt A, pt B)       //Initialy A->O->B (LM->O->RM) in counter-clockwise order 
{
    //Get the intersection with four axis. The order is: y = 0, x = n, y = n, x = 0, or from y = 0 throught CCW order
    complex<ld> intersect_OA[4] = {
        {      
            calcHorizontal(O, A, 0),
            0.000000000000000000000
        },
        {
            n * 1.00000000000000000,
            calcVertical(O, A, n)
        },
        {
            calcHorizontal(O, A, n),
            n * 1.00000000000000000
        },
        {
            0.000000000000000000000,
            calcVertical(O, A, 0)
        }
    };
    complex<ld> intersect_OB[4] = {
        {      
            calcHorizontal(O, B, 0),
            0.000000000000000000000
        },
        {
            n * 1.00000000000000000,
            calcVertical(O, B, n)
        },
        {
            calcHorizontal(O, B, n),
            n * 1.00000000000000000
        },
        {
            0.000000000000000000000,
            calcVertical(O, B, 0)
        }
    };

    pair<pt, int> inter_A, inter_B;
    //Filter unecessary points
    FOR(i, 0, 3) if(isInPoly(O, A, B, intersect_OA[i]))
    {
        inter_A = {intersect_OA[i], i};
        break;
    }
    FOR(i, 0, 3) if(isInPoly(O, A, B, intersect_OB[i]))
    {
        inter_B = {intersect_OB[i], i};
        break;
    }
    //Local search to find "proper" point inside the polygon.
    findProperPoint(inter_A, P_COUNTER_CLOCKWISE, O, A, B);
    findProperPoint(inter_B, P_CLOCKWISE, O, A, B);

    cerr << el;
    cerr << "Intersection w/ axis - ray OA: " << A << ": ";
    FOR(i, 0, 3) cerr << intersect_OA[i] << sp; cerr << el;
    cerr << "Intersection w/ axis - ray OB: " << B << ": ";
    FOR(i, 0, 3) cerr << intersect_OB[i] << sp; cerr << el;
    cerr << "Final Proper Intersection Point: A-B: " << inter_A.fi << "-" << inter_A.se 
    << sp << inter_B.fi << "-" << inter_B.second << el; 






}


//Process





//Output





//Main Procedure
int main()
{
    cerr << cmpAngle(pt(5, 5), pt(4, 6), pt(2, 3), pt(5, 2)) << el;


    FileInit();
    Enter();
    Filter();
    FOR(i, 1, nPolygons) parseCoord(initial, LeftmostList[i], RightmostList[i]);
    return 0;
}
/*

    pt bot_left  = {0, 0};
    pt bot_right = {n, 0};
    pt top_left  = {0, n};
    pt top_right = {n, n};

    vct OA = A - O;
    vct OB = B - O;

    //Handle some corner cases - Is that done and right??? - Check collinear or CCW
    bool p1 = (orientation(A, O, bot_left)  >= 0 && orientation(bot_left, O, B)  >= 0);     
    bool p2 = (orientation(A, O, bot_right) >= 0 && orientation(bot_right, O, B) >= 0);
    bool p3 = (orientation(A, O, top_left)  >= 0 && orientation(top_left, O, B)  >= 0);
    bool p4 = (orientation(A, O, top_right) >= 0 && orientation(top_right, O, B) >= 0);


*/

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
