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
#define task "SUBSEQ"
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vvi lx, F;
int n, k;
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

//Enter
void Enter()
{
	scanf("%d", &n);

	lx = F = vvi(n + 1, (a = vi(n + 1, 0)));

	FOR(i, 1, n) scanf("%d", &a[i]);
}

//Process
void Solve()
{
    FOR(i, 1, n)
    {
        FOR(j, i, n)
        {
            lx[i][j] = 1;
            FORl(u, i, j)
            {
                if(a[u] < a[j]) lx[i][j] = max(lx[i][j], lx[i][u] + 1);
            }
        }
    }

//    FORl(i, 0, n)
//    {
//        FORl(j, 0, n)
//        {
//            cerr << lx[i][j] << " ";
//        }
//        cerr << "\n";
//    }

    FOR(k, 1, n)
    {
        FOR(r, 1, n)
        {
            F[k][r] = F[k][r-1];
            FOR(i, 1, r) if(lx[i][r] >= k) F[k][r] = max(F[k][r], F[k][i-1] + lx[i][r]);
        }
    }

    FOR(k, 1, n) printf("%d ", F[k][n]);

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
