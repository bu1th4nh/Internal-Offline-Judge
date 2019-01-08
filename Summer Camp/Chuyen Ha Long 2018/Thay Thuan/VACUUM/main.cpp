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


const long double M_PI = acos(-1);
const long double eps =  1e-3;
//=====================================
//Object
struct data
{
    typedef long double ld;
    ld x, y, deg, rad;

    data(): x(0.0), y(0.0), deg(0.0), rad(0.0) {}
    data(ld __x, ld __y, ld __dg, ld __rd): x(__x), y(__y), deg(__dg), rad(__rd) {}

    void modify(ld angle, ld dist)
    {

        deg += angle;
        x += ( (dist) * sin( -deg * M_PI / 180.0 ));
        y += ( (dist) * cos( -deg * M_PI / 180.0 ));

    }


    void print()
    {
        printf("%.6lf %.6lf\n", x, y);
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int nTest, nInstr;

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

//Process
void Solve()
{
    ld x, y;

    data a;

    scanf("%d", &nInstr);
    FOR(i, 1, nInstr)
    {
        cin >> x >> y;
        a.modify(x, y);
    }

    a.print();
}


//Output
void Multi()
{
    scanf("%d", &nTest);
    while(nTest--) Solve();
}

//Main Procedure
int main()
{
    Multi();
    return 0;
}
