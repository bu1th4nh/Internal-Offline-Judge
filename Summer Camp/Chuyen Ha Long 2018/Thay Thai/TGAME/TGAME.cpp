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
#define task "TGAME"
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
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi topoOrder, idOrder, par, F;
int topoTime, rt, n, x, y;
vb avail;
vvi adj;

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
    int u;
    par = topoOrder = idOrder = vi(n+1, 0);
    avail = vb(n+1, 1);
    F = vi(n+1, 0);
    adj = vvi(n+1);
    topoTime  = n;

    FOR(i, 1, n)
    {
        scanf("%d", &u);
        if(u != 0) adj[u].pb(i);
        else rt = i;
        par[i] = u;
    }
}

//Check
void topoDFS(int u)
{
    avail[u] = 0;
    for(int v: adj[u])
    {
        if(avail[v]) topoDFS(v);
    }

    topoOrder[u] = topoTime;
    idOrder[topoTime--] = u;
}



//Process
void Solve()
{
    int u;

    topoDFS(rt);
    F[0] = 0;

    FORb(i, n, 1)
    {
        u = idOrder[i];

        if(adj[u].empty()) F[u] = 0;
        else
        {
            set<int> s;
            for(int v: adj[u]) s.insert(F[v]);

            FOR(i, 0, n+1) if(!binary_search(whole(s), i))
            {
                F[u] = i;
                break;
            }
        }
    }

    puts((F[x]^F[y]) ? "YES" : "NO");
}


//Main Procedure
int main()
{
    FileInit();
    while(scanf("%d%d%d", &n, &x, &y) && n && x && y)
    {
        Enter();
        Solve();
    }
    return 0;
}
