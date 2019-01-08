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
#define task "GALASCHE"
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
vi a, res, trace, s1, s2;
int n, t, last1, last2;
vvi F;

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
    scanf("%d%d", &t, &n);

    a = res = trace = vi(n+1);
    F = vvi(n+1, vi(t+1, 0));

    FOR(i, 1, n) scanf("%d", &a[i]);
}

//Check
void KnApSacK()
{
    FOR(i, 1, n)
    {
        FOR(j, 1, t)
        {
            F[i][j] = (j - a[i] >= 0) ? max(F[i - 1][j - a[i]] + a[i], F[i-1][j]) : F[i-1][j];
        }
    }
}

//Process
void Solve()
{
    KnApSacK();

    int r = t;
    while(r)
    {
        int v = n;
        while(F[v][r] == F[v-1][r]) --v;
        trace[v] = 1;
        r -= a[v];
    }

    //puts(""); for(int i: s1) printf("%d ", i); puts()


    last1 = last2 = 0;

    FOR(i, 1, n)
    {
        if(!trace[i]) continue;
        res[i] = last1;
        last1 += a[i];
    }
    FOR(i, 1, n)
    {
        if(trace[i]) continue;
        res[i] = last2;
        last2 += a[i];
    }

    FOR(i, 1, n) printf("%d ", res[i]);

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
