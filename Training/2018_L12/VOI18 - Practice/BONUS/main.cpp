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
#include <cassert>
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
#define task "BONUS"
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
long long ps[1024][1024];
struct rect
{
    typedef long long ll;
    typedef vector<ll> vll;
    typedef vector<vll> vvll;

    int tl_x, tl_y;
    int br_x, br_y;
    int r;

    rect(int x, int y, int edg): tl_x(x), tl_y(y), br_x(x+edg-1), br_y(y+edg-1), r(edg) {}
    rect(int x, int y, int x2, int y2): tl_x(x), tl_y(y), br_x(x2), br_y(y2), r(-1) {}
    rect() {}

    ll get()
    {
        return ps[br_x][br_y] - ps[br_x][tl_y-1] - ps[tl_x-1][br_y] + ps[tl_x-1][tl_y-1];
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<rect> vr;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<vii> vvii;
int n, nOptions, nRect, edge;
vvll a;


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
template<class T> inline void scan(T &ret)
{
    bool neg = 0;
    char c = 0;
    ret = T();

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        c = getchar();
        neg = 1;
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret = neg ? -ret : ret;
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
void _swap(rect &a, rect &b)
{
    rect tmp = a;
    a = b;
    b = tmp;
}

//Enter
void Enter()
{
	scan(n);
	scan(nOptions);
	scan(edge);
	scan(nRect);


	a = vvll(n+1, vll(n+1, 0LL));
	FOR(i, 1, n)
	{
	    FOR(j, 1, n) scan(a[i][j]);
	}
	FOR(i, 1, n)
	{
	    FOR(j, 1, n) ps[i][j] = ps[i-1][j] + ps[i][j-1] + a[i][j] - ps[i-1][j-1];
	}
}

//Utilities
bool inRange(int lower, int upper, int value)
{
    return lower <= value && value <= upper;
}
rect get_intersect(const rect &a, const rect &b)
{
    return rect(max(a.tl_x, b.tl_x), max(a.tl_y, b.tl_y), min(a.br_x, b.br_x), min(a.br_y, b.br_y));
}
bool is_intersect(rect a, rect b)
{
    if(a.tl_x > b.tl_x) _swap(a, b);
    if(b.tl_x > a.br_x) return 0;
    if(b.tl_y > a.br_y || b.br_y < a.tl_y) return 0;
    return 1;
}

//Process
ll Query(const vr &a)
{
    rect tmp;
    bool ok;
    ll ret = 0LL;

    FORl(state, 1, (1 << nRect))
    {
        vr p;
        FORl(i, 0, nRect) if((state >> i) & 1)
        {
            p.push_back(a[i]);
        }

        ok = 1;
        tmp = p[0];
        FORl(i, 1, (int)p.size())
        {
            if(is_intersect(tmp, p[i])) tmp = get_intersect(tmp, p[i]);
            else
            {
                ok = 0;
                break;
            }
        }

        if(ok) ret += tmp.get() * (((int)p.size() & 1) ? 1 : -1);
    }
    return ret;
}
void Solve()
{
    int u, v;
    vr a(nRect);
    ll res = 0LL;
    FOR(i, 1, nOptions)
    {
        for(auto &x: a)
        {
            scan(u), scan(v);
            x = rect(u, v, edge);
        }
        res = max(res, Query(a));
    }
    print(res);
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
