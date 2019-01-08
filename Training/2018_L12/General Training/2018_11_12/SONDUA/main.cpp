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
#define task "SONDUA"
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
int n, m, k, res;
vvi concomp;
vb avail;
vvi adj;
vi col;

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
    scanf("%d%d%d", &n, &m, &k);

    avail = vb(n+1, 1);
    col = vi(n+1, 0);
    adj = vvi(n+1);

    FOR(i, 1, n) scanf("%d", &col[i]);
    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

//Check
void DFS(vi &comp, int u)
{
    comp.pb(u);
    avail[u] = 0;
    for(int v: adj[u]) if(avail[v])
    {
        DFS(comp, v);
    }
}

//Process
void is_that_right()
{
    res = 0;
    int tmp = 0;
    FOR(i, 1, n) if(avail[i])
    {
        vi comp;
        DFS(comp, i);
        concomp.push_back(comp);
    }

    for(vi x: concomp)
    {
        map<int, int> mp;
        for(int y: x)
        {
            int color = col[y];
            ++mp[color];
        }

        tmp = 0;
        for(auto x: mp) tmp = max(tmp, x.second);
        res += (x.size() - tmp);
    }
    cout << res << el;
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    is_that_right();
    return 0;
}
