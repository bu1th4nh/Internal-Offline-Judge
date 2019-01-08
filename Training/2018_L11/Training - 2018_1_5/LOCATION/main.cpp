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
#define task "LOCATION"
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
typedef map<int, int> mii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, m, k, res;
vvii adj;
vvi dist;
vi shops;
vb valid;
mii mp;

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
    int u, v, c;
    scanf("%d%d%d", &n, &m, &k);

    dist = vvi(k, vi(n+1, 1234567890));
    valid = vb(n+1, true);
    adj = vvii(n+1);
    shops = vi(k);

    FORl(i, 0, k) scanf("%d", &shops[i]), valid[shops[i]] = false;
    FOR(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &c);
        adj[u].pb(ii(c, v));
        adj[v].pb(ii(c, u));
    }
}

//Check
void Dijkstra(int pos)
{
    int u, v, du, uv, start;
    priority_queue<ii, vii, greater<ii>> pq;


    start = shops[pos];
    pq.push(ii(0, start));
    dist[pos][start] = 0;

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != dist[pos][u]) continue;

        for(ii x: adj[u])
        {
            v = x.second;
            uv = x.first;

            if(dist[pos][v] > du + uv)
            {
                pq.push(ii((dist[pos][v] = du + uv), v));
            }
        }
    }
}



//Process
void Solve()
{
    res = INT_MAX;
    sort(whole(shops));
    FORl(i, 0, k) mp[shops[i]] = i;
    FORl(i, 0, k) Dijkstra(i);
    do
    {
        int tmp = INT_MAX;
        FOR(i, 1, n) if(valid[i])
        {
            int shpth = dist[mp[shops[0]]][i];
            FORl(j, 0, shops.size()-1)
            {
                shpth += dist[mp[shops[j]]][shops[j+1]];
            }
            shpth += dist[mp[shops[shops.size()-1]]][i];
            tmp = min(tmp, shpth);
        }

        res = min(res, tmp);
    }
    while(next_permutation(whole(shops)));

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
