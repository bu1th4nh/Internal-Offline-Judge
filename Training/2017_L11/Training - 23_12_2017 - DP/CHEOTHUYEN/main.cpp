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
using namespace std;


//=====================================
//Macros
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


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ii a[4096];
int n;
vll d;
ll h;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit() {
    FILEOP()
}
void FileClose() {
    fclose(stdin);
    fclose(stdout);
}
ll dist(ii x, ii y) {
    return 1LL*(1LL*(x.first - y.first)*(x.first - y.first) + 1LL*(x.second - y.second)*(x.second - y.second));
}
ll Ex(ii x) {
    ll u = max(x.se, h - x.se);
    return 1LL*u*u;
}

//Enter
void Enter() {
    scanf("%d%lld", &n, &h);

    d = vll(n+2, 0LL);
    FOR(i, 1, n) scanf("%lld%lld", &a[i].fi, &a[i].se);
    sort(a+1, a+n+1);

    a[n+1] = ii(a[n].fi, 0LL);
}

//Process
void Solve() {
    ll u = 1LL*max(a[1].se, h - a[1].se);

    d[1] = 1LL*u*u;

    FOR(i, 2, n) {
        d[i] = (dist(a[i], a[i-1]) < min(Ex(a[i]), Ex(a[i-1]))) ? min(Ex(a[i]), Ex(a[i-1])) : min(d[i-1], max(d[i], dist(a[i], a[i-1])));
    }

    cout << trunc(sqrt(d[n]));
}


//Main Procedure
int main() {
    Enter();
    Solve();
    return 0;
}
