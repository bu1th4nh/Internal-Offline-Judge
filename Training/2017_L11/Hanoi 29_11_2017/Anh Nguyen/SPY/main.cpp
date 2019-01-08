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
typedef set<int> st_int;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<st_int> vsi;


int n, m, root_ioi, root_joi;
vvi ioi, joi;
vsi R, S;
vi  res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d%d", &n, &m);

    ioi = joi = vvi(n+1);
    R = S = vsi(n+1);
    res = vi(n+1);
    int u, v;

    FOR(i, 1, n)
    {
        scanf("%d%d", &u, &v);

        if(u == 0) root_joi = i;
        else joi[u].pb(i);

        if(v == 0) root_ioi = i;
        else ioi[v].pb(i);

    }


}

//DFS


//Process
void Solve()
{
    DFS_JOI(root_joi);
    DFS_IOI(root_ioi);

    Intelligence(root_ioi);

    FOR(i, 1, n) printf("%d\n", res[i]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
