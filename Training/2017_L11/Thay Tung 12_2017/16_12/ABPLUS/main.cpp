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
#include <tuple>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "ABPLUS"
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

const int N = 50000;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
vi a(51200, 0), b(51200, 0);
int n, zr, na, nb;
vi va, vb;
ll res;

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

//Enter
void Enter()
{
    int u;
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        scanf("%d", &u);
        if(u == 0) ++zr;
        if(u > 0) ++a[u];
        else ++b[-u];
    }

    FOR(i, 1, N)
    {
        if(a[i] > 0) va.push_back(i), ++na;
        if(b[i] > 0) vb.push_back(i), ++nb;
    }
}


//Process
void Solve()
{
    FORl(i, 0, na-1)
    {
        FORl(j, i, na)
        {
            if(i == j && a[i] == 1) continue;
            int t = va[i] + va[j];
            if(t > N) break;
            if(a[t] > 0) res += (i == j) ? (a[va[i]] * (a[va[i]] - 1)) : (a[va[i]] * a[va[j]] * 2);
        }
    }

    FORl(i, 0, nb)
    {
        FORl(j, i, nb)
        {
            if(i == j && b[i] == 1) continue;
            int t = vb[i] + vb[j];
            if(t > N) break;
            if(b[t] > 0) res += (i == j) ? (b[vb[i]] * (b[vb[i]] - 1)) : (b[vb[i]] * b[vb[j]] * 2);
        }
    }

    for(int xa: va)
    {
        for(int xb: vb)
        {
            int t = xa - xb;
            if(t == 0 && zr > 0) {res += 2 * zr * a[xa] * b[xb]; continue;}
            if(t > 0 && a[t] > 0) {res += 2 * a[t] * a[xa] * b[xb]; continue;}
            if(t < 0 && b[-t] > 0) {res += 2 * b[-t] * a[xa] * b[xb]; continue;}
        }
    }

    if(zr > 0)
    {
        if(zr > 2) res = zr * (zr - 1);
        for(int xa: va) if(a[xa] > 1) res += zr * a[xa] * 2;
        for(int xb: vb) if(b[xb] > 1) res += zr * b[xb] * 2;
    }

    cout << res;
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    FileClose();
    return 0;
}
