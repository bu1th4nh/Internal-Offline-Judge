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


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef complex<int> pt;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pt> vpt;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
long double res;
vpt poly;
ll area2;
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
    int _x, _y;
	scanf("%d", &n);
	poly = vpt(n+1);
	FOR(i, 1, n) scanf("%d%d", &_x, &_y), poly[i] = {_x, _y};
}

//Point Operation
int cross(pt a, pt b)
{
    return a.x * b.y - a.y * b.x;
}
bool ccw(pt a, pt b, pt c)
{
    return cross(b - a, c - b) > 0;
}


//Process
void Solve()
{
    area2 = 0LL;
    FORl(i, 2, n)
    {
        area2 += 1LL * cross(poly[i] - poly[1], poly[i+1] - poly[1]);
    }

    if(area2 < 0) printf("CW ");
    else printf("CCW ");

    area2 = abs(area2);
    if(area2 & 1)
    {
        printf("%d.5\n", (area2 >> 1));
    }
    else
    {
        printf("%d.0\n", (area2 >> 1));
    }
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
