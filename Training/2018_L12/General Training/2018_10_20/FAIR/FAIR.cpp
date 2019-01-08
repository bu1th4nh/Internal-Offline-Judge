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
#define task "FAIR"
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



const int inf = 1000000007;
const int nextx[4] = {-1, 0, 0, 1};
const int nexty[4] = {0, -1, 1, 0};
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vvi codex, dist;
vvb avail;
int n, m;


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
inline ll readInt()
{
    ll ret = 0;
    char c = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    return neg ? -ret : ret;
}
void writeInt(ll x)
{
    if(x > 9) writeInt(x / 10);
    putchar(x % 10 + '0');
}


//Enter
void Enter()
{
    m = readInt();
    n = readInt();

    dist  = vvi(m+2, vi(n+2, inf));
    codex = vvi(m+2, vi(n+2, -1));

    FOR(i, 0, m+1) codex[i][0] = codex[i][n+1] = -1;
    FOR(i, 0, n+1) codex[0][i] = codex[m+1][i] = -1;

    FOR(i, 1, m)
    {
        FOR(j, 1, n) codex[i][j] = readInt();
    }
}

//Check
void dijkstra()
{
    ii cur, nxt;
    int d_cur, d_nxt;
    priority_queue<iii, vector<iii>, greater<iii>> pq;

    FOR(i, 1, m) pq.push(iii(1, ii(i, 1))), dist[i][1] = 1;
    while(!pq.empty())
    {
        cur   = pq.top().second;
        d_cur = pq.top().first;
        pq.pop();

        if(dist[cur.first][cur.second] != d_cur) continue;
        FOR(i, 0, 3)
        {
            nxt.first  = cur.first  + nextx[i];
            nxt.second = cur.second + nexty[i];
            if(codex[nxt.first][nxt.second] != -1)
            {
                d_nxt = (codex[nxt.first][nxt.second] != codex[cur.first][cur.second]) ? 1 : 0;

                if(d_cur + d_nxt < dist[nxt.first][nxt.second])
                {
                    pq.push(iii((dist[nxt.first][nxt.second] = d_cur + d_nxt), nxt));
                }
            }
        }
    }
}

//Process
void Solve()
{
    dijkstra();

    int res = inf;
    FOR(i, 1, m) res = min(res, dist[i][n]);
    writeInt(res);
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
