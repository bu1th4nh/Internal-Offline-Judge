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
#define task "SCHOOL"
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
typedef pair<ll, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vll d, cnt;
int n, m;
vvii adj;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit() {
    FILEOP()
}
void FileClose() {
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter() {
    int u, v, c, t;
    scanf("%d%d", &n, &m);

    d = vll(n+1, 1000000000);
    cnt = vll(n+1, 0LL);
    adj = vvii(n+1);

    FOR(i, 1, m) {
        scanf("%d%d%d%d", &t, &u, &v, &c);

        if(t == 2) adj[v].pb(ii(c, u));
        adj[u].pb(ii(c, v));
    }
}

//Check
void Dijkstra() {
    priority_queue<ii, vii, greater<ii>> pq;
    ll du, uv;
    int u, v;

    pq.push(ii(0, 1));
    cnt[1] = 1;
    d[1] = 0LL;

    while(!pq.empty()) {
        du = pq.top().first;
        u = pq.top().second;
        pq.pop();

        if(du != d[u]) continue;

        for(ii x: adj[u])
        {
            v = x.second;
            uv = x.first;

            if(du + uv == d[v]) cnt[v] += cnt[u];
            else if(du + uv < d[v])
            {
                pq.push(ii((d[v] = du + uv), v));
                cnt[v] = cnt[u];
            }
        }
    }

    printf("%lld", cnt[n]);
}



//Main Procedure
int main() {
    FileInit();
    Enter();
    Dijkstra();
    FileClose();
    return 0;
}
