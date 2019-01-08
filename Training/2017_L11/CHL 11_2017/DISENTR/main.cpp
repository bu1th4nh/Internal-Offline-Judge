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


const int inf = 1000000007;
//=====================================
//Typedef
struct edge
{
    int u, v, l, fl, fr;
    edge(int _l, int _fl = inf, int _fr = -inf)
    {
        fl = _fl;
        fr = _fr;
        l = _l;
    }
    edge()
    {
        fl = inf, fr = -inf;
    }
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef map<ii, edge> lst;
typedef vector<edge> ve;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<ii, int> mpiii;
int m, n, s, t, k, c;
vvii adj;
lst mpe;
vi w, d;

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
    int u, v, l;
    ii x, y;

    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d", &s, &t, &k, &c);

    w = vi(c+6);
    adj = vvii(n+1);
    d = vi(n+1, inf);

    FOR(i, 1, c) scanf("%d", &w[c]);

    FOR(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &l); x = ii(u, v), y = ii(v, u);
        adj[u].pb(ii(l, v));
        adj[v].pb(ii(l, u));

        mpe[x] = mpe[y] = edge(l);
    }

    int Time = 0;
    FOR(i, 1, c-1)
    {
        u = w[i], v = w[i+1];
        x = ii(u, v), y = ii(v, u);
        mpe[x].fl = mpe[y].fl = Time;
        Time += mpe[x].l;
        mpe[x].fr = mpe[y].fr = Time;
    }

}

//Dijkstra's Algorithm
void Dijkstra()
{
    int u, v, du, uv, xx, ndu;
    priority_queue<ii, vii, greater<ii>> q;
    q.push(ii(k, s));
    d[s] = k;

    while(!q.empty())
    {
        u = q.top().second;
        du = q.top().first;
        q.pop();

        if(du != d[u]) continue;

        for(ii x: adj[u])
        {
            v = x.second;
            uv = x.first;
            ii e(u, v);

            ndu = (du < mpe[e].fl || du >= mpe[e].fr) ? du : mpe[e].fr;

            if(ndu + uv < d[v])
            {
                q.push(ii((d[v] = ndu + uv), v));
            }
        }
    }


    printf("%d\n", d[t]);
}


//Main Procedure
int main()
{
    Enter();
    Dijkstra();
    return 0;
}


/*

const int inf = 1000000007;
//=====================================
//Typedef
struct edge
{
    int u, v, l, fl, fr;
    edge(int _l, int _fl = inf, int _fr = -inf)
    {
        fl = _fl;
        fr = _fr;
        l = _l;
    }
    edge()
    {
        fl = inf, fr = -inf;
    }
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef map<ii, edge> lst;
typedef vector<edge> ve;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<ii, int> mpiii;
int m, n, s, t, k, c;
vvii adj;
lst mpe;
vi w, d;

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
    int u, v, l;
    ii x, y;

    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d", &s, &t, &k, &c);

    w = vi(c+6);
    adj = vvii(n+1);
    d = vi(n+1, inf);

    FOR(i, 1, c) scanf("%d", &w[c]);

    FOR(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &l); x = ii(u, v), y = ii(v, u);
        adj[u].pb(ii(l, v));
        adj[v].pb(ii(l, u));

        mpe[x] = mpe[y] = edge(l);
    }

    int Time = 0;
    FOR(i, 1, c-1)
    {
        u = w[i], v = w[i+1];
        x = ii(u, v), y = ii(v, u);
        mpe[x].fl = mpe[y].fl = Time;
        Time += mpe[x].l;
        mpe[x].fr = mpe[y].fr = Time;
    }

}

//Dijkstra's Algorithm
void Dijkstra()
{
    int u, v, du, uv, xx, ndu;
    priority_queue<ii, vii, greater<ii>> q;
    q.push(ii(k, s));
    d[s] = k;

    while(!q.empty())
    {
        u = q.top().second;
        du = q.top().first;
        q.pop();

        if(du != d[u]) continue;

        for(ii x: adj[u])
        {
            v = x.second;
            uv = x.first;
            ii e(u, v);

            ndu = (du < mpe[e].fl || du >= mpe[e].fr) ? du : mpe[e].fr;

            if(ndu + uv < d[v])
            {
                q.push(ii((d[v] = ndu + uv), v));
            }
        }
    }


    printf("%d\n", d[t]);
}


//Main Procedure
int main()
{
    Enter();
    Dijkstra();
    return 0;
}
*/
