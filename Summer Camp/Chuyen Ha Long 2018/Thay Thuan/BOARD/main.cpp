/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task ""
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}

#define x real()
#define y imag()


const long double eps  = 1e-3;
const long double M_PI = acos(-1.0);
//=====================================
//Typedefs
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex<ld> pt;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<pt> vpt;
typedef vector<vi> vvi;
//=====================================
//Typedefs 2
struct Data
{
    pt center;
    ld w, h, d, area;

    Data() {}

    void scan()
    {
        ld xx, yy;
        cin >> xx >> yy >> w >> h >> d;
        center = {xx, yy};
        area = w * h * 1.0;
    }
    vpt extract_points()
    {
        ld phi = d * M_PI / 180.0;
        ld omega = atan(ld(w / h));
        ld diagonal = sqrt(w * w * 1.0 + h * h * 1.0) / 2.0;

        pt delta1(diagonal * sin(omega + phi), diagonal * cos(omega + phi));
        pt delta2(diagonal * sin(omega - phi), diagonal * cos(omega - phi));

        return vpt({center + delta1, center - delta1, center + delta2, center - delta2});
    }

};
//=====================================
//Typedefs 3
typedef vector<Data> vd;

//=====================================
//Variables
vpt point, hull;
vd rects;
int n;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    FILEOP_DEBUG()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
	scanf("%d", &n);
	rects = vd(n+1);
	FOR(i, 1, n) rects[i].scan();
}

//Process
void getConvexHull()
{
    FOR(i, 1, n)
    {
        vpt tmp = rects[i].extract_points();
        for(pt _x: tmp) point.push_back(_x);
    }


}
void getRate()
{
    //
}

//Output





//Main Procedure
int main()
{
    //Your code goes here
    return 0;
}
