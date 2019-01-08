/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*
    This is a VERY FUCKING INPORTANT problem.

        -Sort the set of points by x
        -Let d[i] is the closest dist from set{1, i}.
            d[i] = min(d[i-1], DIST[i][j], j<i).
            Use a set to store the point which lies between d[i-1] and d[i].

*/
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
#define task "NEAREST"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin()+1, x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


const long double eps = 1e-7;
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vii pt_set;
ll res;
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

//Utilities
ll sqr(const int a)
{
    return 1LL * a * a;
}
ll sqr_dist(ii &x, ii &y)
{
    return (sqr(x.fi - y.fi) + sqr(x.se - y.se));
}
struct cmp                                  //Brildiant :D
{
    bool operator() (int __i, int __j) const
    {
        return pt_set[__i].se < pt_set[__j].se;
    }
};
typedef set<int, cmp> set_i;


//Enter
void Enter()
{
    scanf("%d", &n);
    pt_set = vii(n+1);
    FOR(i, 1, n) scanf("%lld%lld", &pt_set[i].fi, &pt_set[i].se);

    //FOR(i, 1, n) cerr << pt_set[i].fi << sp << pt_set[i].se << el;
}


//Process
void Solve(vii &a)
{
    sort(whole(a));

    set<int, cmp> S;
    ll res = sqr_dist(a[1], a[2]);

    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        ///first get answer
        while (j <= n && a[i].first - a[j].first > (int)(sqrt(res)) + eps)
        {
            ///pop j
            S.erase(j++);
        }
        a[0].second = a[i].second - (int)sqrt(res) - 2;
        set<int, cmp>::iterator it = S.lower_bound(0);
        while (it != S.end())
        {
            int id = (*it);
            if (a[id].second > a[i].second + sqrt(res)) break;
            res = min(res, sqr_dist(a[id], a[i]));
            ++it;
        }
        ///second insert point
        S.insert(i);
    }
    cout << fixed << setprecision(4) << (double) sqrt(res) << endl;
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve(pt_set);
    return 0;
}


/*Sample I/O
7
6 -6
5 1
-4 -3
-4 5
3 -4
7 -4
3 2

*/
