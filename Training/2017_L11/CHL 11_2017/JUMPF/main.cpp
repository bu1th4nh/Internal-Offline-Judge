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
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
const int inf = 1000000007;
int n, res;
vvi F;
vi a;


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
    int u;
    scanf("%d", &n);
    a = vi(n+1, 0);
    F = vvi(n+1, vi(n+1, inf));
    FOR(i, 1, n)
    {
        scanf("%d", &a[i]);
    }
}

//Process
void Solve()
{
    if(n == 2)
    {
        printf("%d\n", a[2]);
        return;
    }

    F[0][1] = 0;

    int x, y;
    FOR(l, 1, n)
    {
        FORb(p, n, 1)
        {
            x = (p - l >= 1) ? F[l-1][p-l] : inf;
            y = (p + l <= n) ? F[l][p+l] : inf;

            F[l][p] = min(x, y) + a[p];
        }
    }

    ll res = inf;

    FOR(l, 1, n)
    {
        res = min(res, F[l][n]);
    }

    printf("%d", res);



//    FOR(i, 1, n)
//    {
//        FOR(j, 1, n) cout << F[i][j] << " ";
//        puts("");
//    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
