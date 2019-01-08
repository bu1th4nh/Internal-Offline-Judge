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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<vii> vvii;
int n, nOptions, nRect, edge;
vvll a, ps;



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
template<class P, class Q> P max(P x, Q y)
{
    return (x > y) ? x : y;
}

//Enter
void Enter()
{
	scan(n);
	scan(nOptions);
	scan(edge);
	scan(nRect);


	a = ps = vvll(n+1, vll(n+1, 0LL));
	FOR(i, 1, n)
	{
	    FOR(j, 1, n) scan(a[i][j]);
	}
	FOR(i, 1, n)
	{
	    FOR(j, 1, n) ps[i][j] = ps[i-1][j] + ps[i][j-1] + a[i][j] - ps[i-1][j-1];
	}
}

//Check
ll getSum(int x1, int y1, int x2, int y2)
{
    return ps[x2][y2] - ps[x2][y1-1] - ps[x1-1][y2] + ps[x1-1][y1-1];
}
bool checkIntersect(int x1, int y1, int x2, int y2, int r)
{
    if(y2 > y1+r-1 || y2+r-1 < y1 || x2 > x1+r-1) return 0;
    return 1;
}

//"Bite" it!
void RectEqual1()
{
    int x, y;
    ll res = 0LL;
    FOR(i, 1, nOptions)
    {
        scan(x); scan(y);
        res = max(res, getSum(x, y, x+edge-1, y+edge-1));
    }
    print(res);
}

//Subtask 1
ll Sub1Utils()
{
    int x, y;
    ll ret = 0LL;
    vvll query = a;
    FOR(i, 1, nRect)
    {
        scan(x), scan(y);

        //For each square:
        FORl(j, 0, edge)
        {
            FORl(k, 0, edge)
            {
                ret += query[x+j][y+k];
                query[x+j][y+k] = 0;
            }
        }
    }
    return ret;
}
void Sub1()
{
    ll res = 0LL;
    FOR(i, 1, nOptions)
    {
        res = max(Sub1Utils(), res);
    }
    print(res);
}

//Subtask 2
ll Sub2Util()
{
    vii smp(2);
    FOR(i, 0, 1)
    {
        scan(smp[i].fi);
        scan(smp[i].se);
    }
    sort(whole(smp));

    int x = smp[0].fi, y = smp[0].se;
    int z = smp[1].fi, t = smp[1].se;

    if(checkIntersect(x, y, z, t, edge))
    {
        return  getSum(x, y, x+edge-1, y+edge-1) +
                getSum(z, t, z+edge-1, t+edge-1) -
                getSum(max(x, z), max(y, t), min(x+edge-1, z+edge-1), min(y+edge-1, t+edge-1));
    }
    else
    {
        return  getSum(x, y, x+edge-1, y+edge-1) +
                getSum(z, t, z+edge-1, t+edge-1);
    }
}
void Sub2()
{
    ll res = 0LL;
    FOR(i, 1, nOptions)
    {
        res = max(Sub2Util(), res);
    }
    print(res);
}

//Subtask 3
ll getSumTopLeft(int x, int y, int r)
{
    return getSum(x, y, x+r-1, y+r-1);
}
ll getIntersect(int x, int y, int z, int t, int r)
{
    return getSum(max(x, z), max(y, t), min(x+r-1, z+r-1), min(y+r-1, t+r-1));
}
ll Sub3Util()
{
    ll ret = 0LL;
    vii smp(3);

    FOR(i, 0, 2)
    {
        scan(smp[i].fi);
        scan(smp[i].se);
    }
    sort(whole(smp));

    int x = smp[0].fi;
    int y = smp[0].se;

    int z = smp[1].fi;
    int t = smp[1].se;

    int u = smp[2].fi;
    int v = smp[2].se;

    int ok = 0;

    ret = getSumTopLeft(x, y, edge) + getSumTopLeft(z, t, edge) + getSumTopLeft(u, v, edge);
    if(checkIntersect(x, y, z, t, edge))
    {
        ret -= getIntersect(x, y, z, t, edge);
        ++ok;
    }

    if(checkIntersect(x, y, u, v, edge))
    {
        ret -= getIntersect(x, y, z, t, edge);
        ++ok;
    }

    if(checkIntersect(z, t, u, v, edge))
    {
        ret -= getIntersect(x, y, z, t, edge);
        ++ok;
    }

    if(ok == 3)
    {
        ret += getSum(max(x, max(z, u)), max(y, max(t, v)), min(x+edge-1, min(z+edge-1, u+edge-1)), min(y+edge-1, min(t+edge-1, v+edge-1)));
    }
    return ret;
}
void Sub3()
{
    ll res = 0LL;
    FOR(i, 1, nOptions)
    {
        res = max(Sub3Util(), res);
    }
    print(res);
}

//Output
void Solve()
{
    if(n <= 50) Sub1();
    else if(nRect == 2) Sub2();
    else if(nRect == 3) Sub3();
    else if(nRect == 1) RectEqual1();
    else cout << ps[n][n];
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
