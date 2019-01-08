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
#define task "ROBOT"
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
vvi c, F1, F2;
int m, n;               //F1[i][j]: Number of shortest path from (1, 1) --> (i, j)
vii res;                //F2[i][j]: Number of shortest path from (m, n) --> (i, j)


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    scanf("%d%d", &m, &n);
    c = F1 = F2 = vvi(m+2, vi(n+2, 0LL));

    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            scanf("%lld", &c[i][j]);
        }
    }
}

//Process
ll is_prime(ll __x)
{
    if(__x < 0) __x = -__x;

    if(__x <= 1) return 0LL;
    if(__x == 2 || __x == 3) return 1LL;
    FOR(i, 2, trunc(sqrt(__x)))
    {
        if(__x % i == 0) return 0LL;
    }
    return 1LL;
}
void Solve()
{
    F1[1][1] = 1LL;

    FOR(i, 2, m) F1[i][1] = (is_prime(c[i][1] - c[i-1][1])) ? F1[i-1][1] : 0;
    FOR(i, 2, n) F1[1][i] = (is_prime(c[1][i] - c[1][i-1])) ? F1[1][i-1] : 0;

    FOR(i, 2, m)
    {
        FOR(j, 2, n)
        {
            F1[i][j] = (is_prime(c[i][j] - c[i-1][j]))*F1[i-1][j]  +  (is_prime(c[i][j] - c[i][j-1]))*F1[i][j-1];
        }
    }



    F2[m][n] = 1LL;

    FORb(i, m-1, 1) F2[i][n] = (is_prime(c[i][n] - c[i+1][n])) ? F2[i+1][n] : 0;
    FORb(i, n-1, 1) F2[m][i] = (is_prime(c[m][i] - c[m][i+1])) ? F2[m][i+1] : 0;

    FORb(i, m-1, 1)
    {
        FORb(j, n-1, 1)
        {
            F2[i][j] = (is_prime(c[i][j] - c[i+1][j]))*F2[i+1][j]  +  (is_prime(c[i][j] - c[i][j+1]))*F2[i][j+1];
        }
    }


    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            if(i == 1 && j == 1) continue;
            if(i == m && j == n) continue;
            if(F1[i][j] * F2[i][j] != 0 && 1LL * F1[i][j] * F2[i][j] == 1LL * F1[m][n]) res.push_back(ii(i, j));
        }
    }


//    puts("===================F1===================");
//    FOR(i, 1, m)
//    {
//        FOR(j, 1, n)
//        {
//            cout << F1[i][j] << " ";
//        }
//        puts("");
//    }
//
//    puts("===================F2===================");
//
//    FOR(i, 1, m)
//    {
//        FOR(j, 1, n)
//        {
//            cout << F1[i][j] << " ";
//        }
//        puts("");
//    }

    printf("%d\n", res.size());
    for(ii x: res) printf("%d %d\n", x.first, x.second);

}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
