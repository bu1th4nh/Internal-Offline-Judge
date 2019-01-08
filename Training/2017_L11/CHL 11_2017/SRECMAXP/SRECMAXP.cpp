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
#define task "SRECMAXP"
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

const int inf = 1000000007;
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
int a[512][512], h[512], l[512], r[512];
int m, n, res;
string t;


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
    scanf("%d%d", &m, &n);
    cin.ignore(1);
    FOR(i, 1, m)
    {
        getline(cin, t);
        FOR(j, 0, n-1) a[i][j+1] = (t[j] == 'X') ? 0 : 1;
    }
}

//Process
void Solve()
{
    res = -inf;
    h[0] = h[n+1] = -1;

    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            h[j] = a[i][j] * (h[j] + 1);
        }
        FOR(j, 1, n)
        {
            l[j] = j;
            while(h[l[j] - 1] >= h[j]) l[j] = l[l[j] - 1];
        }
        FORb(j, n, 1)
        {
            r[j] = j;
            while(h[r[j] + 1] >= h[j]) r[j] = r[r[j] + 1];
        }
        FOR(j, 1, n)
        {
            if(h[j] != 0) res = max(res, h[j] * 2 + 2 * (r[j] - l[j] + 1));
        }

    }

    printf("%d\n", res);
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
