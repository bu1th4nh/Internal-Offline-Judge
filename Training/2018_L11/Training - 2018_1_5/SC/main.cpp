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
#define task "SC"
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
//Dijkstra
struct DijkstraMat
{
    typedef long long ll;
    typedef pair<int, int> ii;
    typedef pair<ll, ii> iii;
    typedef vector<iii> viii;
    typedef vector<ll> vi;
    typedef vector<vi> vvi;

    const int nextx[4] = {-1, 0, 0, 1};
    const int nexty[4] = {0, -1, 1, 0};

    vvi C, D;


    void addEdge(int u, int v, ll c)
    {
        C[u][v] = c;
    }
    void initDij(ii start = ii(1, 1))
    {
        ll curd;
        int curx, cury, x, y;
        priority_queue<iii, viii, greater<iii>> pq;

        D[start.fi][start.se] = C[start.fi][start.se];
        pq.push(iii((C[start.fi][start.se]),  start));


        while(!pq.empty())
        {
            curx = pq.top().se.fi;
            cury = pq.top().se.se;
            curd = pq.top().first;

            pq.pop();

            if(D[curx][cury] != curd) continue;

            FOR(i, 0, 3)
            {
                x = curx + nextx[i];
                y = cury + nexty[i];

                if(D[x][y] > curd + C[x][y]) pq.push(iii((D[x][y] = curd + C[x][y]), ii(x, y)));
            }
        }
    }
    ll extract(ii __pos)
    {
        return D[__pos.first][__pos.second];
    }



    DijkstraMat(int m, int n)
    {
        C = D = vvi(m+2, vi(n+2, 1000000000000LL));
    }
    DijkstraMat() {}


    ~DijkstraMat() {}

};




//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef queue<ii> qii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef map<ii, bool> miib;
int n, m;

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

//Factorization
int Fact2(ll _x)
{
    int ret = 0;
    while(_x % 2 == 0) ret++, _x /= 2;
    return ret;
}
int Fact5(ll _x)
{
    int ret = 0;
    while(_x % 5 == 0) ret++, _x /= 5;
    return ret;
}

//Process
void Solve()
{
    ll u;
	scanf("%d%d", &m, &n);

	DijkstraMat d2(m, n);
	DijkstraMat d5(m, n);

    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            scanf("%lld", &u);
            d2.addEdge(i, j, Fact2(u));
            d5.addEdge(i, j, Fact5(u));
        }
    }

    d2.initDij();
    d5.initDij();

    cout << min(d2.extract(ii(m, n)), d5.extract(ii(m, n)));

}

//Main Procedure
int main()
{
    FileInit();
    Solve();
    FileClose();
    return 0;
}
