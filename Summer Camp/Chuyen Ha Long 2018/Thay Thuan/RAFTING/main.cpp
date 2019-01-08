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


const long long inf = 1LL << 60;
//=====================================
//Typedefs
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef complex<ll> pt;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pt> vpt;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, n0, nTest;
vpt in, out;


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
    int u, v;

	scanf("%d", &n);
    in = vpt(n+1);
	FOR(i, 1, n)
	{
	    scanf("%d%d", &u, &v);
	    in[i] = (pt(u, v));
	}
	in.push_back(in[1]);

	scanf("%d", &n0);
    out = vpt(n0+1);
	FOR(i, 1, n0)
	{
	    scanf("%d%d", &u, &v);
	    out[i] = (pt(u, v));
	}
	out.push_back(out[1]);
}

//Utilities
ll sqr(ll a)
{
    return 1LL * a * a;
}
ll cross(pt a, pt b)
{
    ll ret = 1LL * a.x * b.y - 1LL * a.y * b.x;

    if(ret == 0LL) return inf;
    return ret;
}
ll sq_dist(pt a, pt b)
{
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}
ll double_area(pt a, pt b, pt c)
{
    return llabs(cross(b - a, c - b));
}
ld getHeight(pt a, pt b, pt c)
{
    ld ret, d_area, oth;

    d_area = ld(double_area(a, b, c));
    oth    = sqrt(ld(sq_dist(b, c)));
    ret    = d_area / oth;

    cerr << "(A - B - C) = " << a << " - " << b << " - " << c << el;
    cerr << "(Area - SQ_Base - Height) = " << d_area << " - " << sq_dist(b, c) << " - " << ret << el;
    return ret;
}


//Process
void Solve()
{
    ld res = inf;
    // 1-In, 2-Out
    FOR(i, 1, n0)
    {
        FOR(j, 1, n)
        {
            res = min(res, getHeight(in[j], out[i], out[i+1]));
        }
    }

    cerr << el;

    // 1-Out, 2-In
    FOR(i, 1, n)
    {
        FOR(j, 1, n0)
        {
            res = min(res, getHeight(out[j], in[i], in[i+1]));
        }
    }

    cout << setprecision(10) << res / 2.0 << el;
    cerr << el;
}

//Output
void bu1th4nh()
{
    cin >> nTest;
    while(nTest--)
    {
        Enter();
        Solve();
    }
}


//Main Procedure
int main()
{
    bu1th4nh();
    return 0;
}
