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
#define task "HIGHWAY"
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



//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef complex<int> pt;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pt> vpt;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int na, ma, nb, mb, nTest;
vpt a_node, b_node;
vii a_edge, b_edge;


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
    fclose(stdin);-
    fclose(stdout);
}
template<class T> inline void scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret *= neg ? -1 : 1;
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

//Enter
void Enter()
{
    int xx, yy;

    scan(na), scan(ma);
    a_node = vpt(na+1);
    a_edge = vii(ma+1);
    FOR(i, 1, na)
    {
        scan(xx), scan(yy);
        a_node[i] = pt(xx, yy);

        //cerr << a_node[i] << el;
    }
    FOR(i, 1, ma)
    {
        scan(xx), scan(yy);
        a_edge[i] = ii(xx, yy);
    }

    //cerr << el;

    scan(nb), scan(mb);
    b_node = vpt(nb+1);
    b_edge = vii(mb+1);
    FOR(i, 1, nb)
    {
        scan(xx), scan(yy);
        b_node[i] = pt(xx, yy);

        //cerr << b_node[i] << el;
    }
    FOR(i, 1, mb)
    {
        scan(xx), scan(yy);
        b_edge[i] = ii(xx, yy);
    }
}

//Check
#define x real()
#define y imag()
int cross(pt a, pt b)
{
    return (conj(a)*b).y;
}
int orient(pt a, pt b, pt c)
{
    int p = cross(b-a, c-a);

    if(p == 0) return 0;
    return (p > 0) ? 1 : 2;
}
bool isCollinear(pt a, pt i, pt b)
{
    return(i.x <= max(a.x, b.x) && i.x >= min(a.x, b.x) && i.y <= max(a.y, b.y) && i.y >= min(a.y, b.y));
}
bool isIntersect(pt u1, pt v1, pt u2, pt v2)
{
    int o1 = orient(u1, v1, u2);
    int o2 = orient(u1, v1, v2);
    int o3 = orient(u2, v2, u1);
    int o4 = orient(u2, v2, v1);

    if(o1 != o2 && o3 != o4) return 1;

    if(!o1 && isCollinear(u1, u2, v1)) return 1;
    if(!o2 && isCollinear(u1, v2, v1)) return 1;
    if(!o3 && isCollinear(u2, u1, v2)) return 1;
    if(!o4 && isCollinear(u2, v1, v2)) return 1;

    return 0;
}
void sub1()
{
    //FOR(i, 1, na) cerr << a_node[i] << sp; cerr << el;
    //FOR(i, 1, nb) cerr << b_node[i] << sp; cerr << el;

    FOR(i, 1, na)
    {
        FOR(j, 1, nb)
        {
            //cerr << a_node[i] << sp << b_node[j] << el;

            bool ok = 1;
            FOR(k, 1, ma)
            {
                //cerr << "Check " << a_node[a_edge[k].fi] << "-" << a_node[a_edge[k].se] << el;

                if(a_edge[k].fi == i || a_edge[k].se == i) continue;

                ok = ok && (!isIntersect(a_node[i], b_node[j], a_node[a_edge[k].fi], a_node[a_edge[k].se]));
                if(!ok) break;
            }
            FOR(k, 1, mb)
            {
                if(b_edge[k].fi == j || b_edge[k].se == j) continue;

                ok = ok && (!isIntersect(a_node[i], b_node[j], b_node[b_edge[k].fi], b_node[b_edge[k].se]));
                if(!ok) break;
            }

            if(!ok) continue;

            //cerr << i << sp << j << el;

            if(ok)
            {
                print(i); putchar(' '); print(j); putchar('\n');
                return;
            }
        }
    }
}


//Process




//Output
void MultTest()
{
    scan(nTest);
    while(nTest--)
    {
        Enter();
        sub1();
    }
}



//Main Procedure
int main()
{
    FileInit();
    MultTest();

//    pt a(1, 1);
//    pt b(2, 2);
//    pt c(3, 3);
//    pt d(3, 4);
//
//    cerr << isCollinear(a, b, c) << sp << isIntersect(a, b, c, d);

    return 0;
}

