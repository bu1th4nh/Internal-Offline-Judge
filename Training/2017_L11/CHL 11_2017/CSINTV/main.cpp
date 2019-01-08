/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "CSINTV"
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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
int n, nres, t[1024576];
vi F, trace, mark;
ii a[131072];
vii res;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Enter
void Enter()
{
    scanf("%d", &n);
    F =  vi(n+1, 1);
    trace = mark = vi(n+1);
    FOR(i, 1, n)
    {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
}

//CMP
bool cmp(ii x, ii y)
{
    return x.se > y.se || (x.se == y.se and x.fi < y.fi);
}

///Longest Increasing Sequence
//Binary Indexed Tree
void updateBIT(int x, int v)
{
    while(x <= 1000007)
    {
        t[x] = max(t[x], v);
        x += x & (-x);
    }
}
int getBIT(int i)
{
    int rs = 0;
    while(i > 0)
    {
        rs = max(rs, t[i]);
        i -= i & (-i);
    }
    return rs;
}

//LIS
void LIS()
{
    int u = 0;
    FOR(i, 1, n)
    {
        F[i] = getBIT(a[i].first) + 1;
        trace[i] = mark[F[i] - 1];
        mark[F[i]] = i;
        updateBIT(a[i].first, F[i]);
        if(nres < F[i]) nres = F[i], u = i;
    }

    cout << nres << "\n";
    while(u)
    {
        res.push_back(a[u]);
        u = trace[u];
    }
}
///Solve
void Solve()
{
    sort(a+1, a+n+1, cmp);
    LIS();
    reverse(whole(res));
    for(ii r: res) cout << r.fi << " " << r.se << "\n";
}

//Main Procedure
int main()
{
    //FileInit();
    Enter();
    Solve();
    FileClose();
    return 0;
}


