/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*  -----Problem Analysis   #dp #topo-sort


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
#define task "DAG"
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

//#define bu1th4nh


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef bitset<65536> bs_16;
typedef pair<int, int> ii;
typedef vector<bs_16> vbs;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi topoOrder, idOrder, nReach;
int m, n, topoTime;
vb avail;
vvi adj;
vbs F;


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

//Enter
void Enter()
{
    int u, v;
    scanf("%d%d", &n, &m);

    topoTime = n;

    F = vbs(n+1);
    adj = vvi(n+1);
    avail = vb(n+1, 1);
    topoOrder = idOrder = nReach = vi(n+1, 0);

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
    }
}

//DFS-related operations
void topoDFS(int u)
{
    avail[u] = 0;
    for(int v: adj[u]) if(avail[v]) topoDFS(v);

    topoOrder[u] = topoTime;
    idOrder[topoTime--] = u;
}


//Process
void Solve()
{
    FOR(i, 1, n) if(avail[i]) topoDFS(i);

    FORb(i, n, 1)
    {
        int u = idOrder[i];
        for(int v: adj[u])
        {
            F[u].set(v, 1);
            F[u] |= F[v];
        }
    }

    #ifdef bu1th4nh
    {
        cerr << "Topological Order: ";
        FOR(i, 1, n) cerr << topoOrder[i] << sp;
        cerr << el;
    }
    #endif // bu1th4nh


    FOR(i, 1, n) printf("%d\n", F[i].count());

}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}

/* Sample Test:
3 3
1 2
1 3
2 3
-------------
8 9
1 7
1 8
7 3
7 5
8 2
2 7
8 6
5 4
4 6
-------------
8 9
2 1
3 1
1 5
1 4
5 6
4 7
7 6
7 8
4 8
*/
