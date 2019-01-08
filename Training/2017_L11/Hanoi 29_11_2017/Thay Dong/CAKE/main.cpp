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
#define task "CAKE"
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



const int nextx[4] = {-1, 0, 1, 0};
const int nexty[4] = {0, -1, 0, 1};
//=====================================
//Typedef
struct Data
{
    int x1, x2, y1, y2;
    Data(int a, int b, int c, int d)
    {
        x1 = a, x2 = c, y1 = b, y2 = d;
    }
    Data(){}
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<Data> vd;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, m, k, res;
vvi plat, cc;
vvb avail;
vd Final;

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

//Process
//Subtask 1
void BFS(ii start, int m_lim, int n_lim)
{
    queue<ii> q;
    q.push(start);
    avail[start.first][start.second] = false;

    while(!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        FORl(i, 0, 4)
        {
            int x = curx + nextx[i];
            int y = cury + nexty[i];
            if(x >= 1 && y >= 1 && x <= n_lim && y <= m_lim && avail[x][y])
            {
                if(plat[x][y] == plat[curx][cury])
                {
                    avail[x][y] = false;
                    q.push(ii(x, y));
                }
            }
        }
    }
}
void Sub1()
{
    plat = vvi(n+1, vi(m+1, 0LL));
    avail = vvb(n+1, vb(m+1, true));
    int x1, y1, x2, y2;

    res = 0;

    FOR(hfe, 1, k)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        FOR(i, min(x1, x2) + 1, max(x1, x2))
        {
            FOR(j, min(y1, y2) + 1, max(y1, y2))
            {
                plat[i][j] = plat[i][j] | (1LL << hfe);
            }
        }
    }

    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            if(avail[i][j])
            {
                ++res;
                BFS(ii(i, j), m, n);
            }
        }
    }

//    puts("");
//    FOR(i, 1, n)
//    {
//        FOR(j, 1, m)
//        {
//            cout << plat[i][j] << " ";
//        }
//
//        puts("");
//    }
//    puts("");

    cout << res << "\n";
}

//Subtask 2
bool ValueOrdered(ii x, ii y)
{
    return x.first < y.first;
}
bool IDOrdered(ii x, ii y)
{
    return x.second < y.second;
}

void Sub2()
{
    plat = vvi(500, vi(500, 0LL));
    avail = vvb(500, vb(500, 0LL));

    vii compressed_1, compressed_2;
    vii compressed_3, compressed_4;
    int x1, x2, y1, y2;

    FOR(iK, 1, k)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        compressed_1.push_back(ii(x1, iK));
        compressed_2.push_back(ii(x2, iK));
        compressed_3.push_back(ii(y1, iK));
        compressed_4.push_back(ii(y2, iK));
    }

    sort(whole(compressed_1), ValueOrdered);
    sort(whole(compressed_2), ValueOrdered);
    sort(whole(compressed_3), ValueOrdered);
    sort(whole(compressed_4), ValueOrdered);

    FORl(i, 0, k) compressed_1[i].fi = i, compressed_2[i].fi = i, compressed_3[i].fi = i, compressed_4[i].fi = i;

    sort(whole(compressed_1), IDOrdered);
    sort(whole(compressed_2), IDOrdered);
    sort(whole(compressed_3), IDOrdered);
    sort(whole(compressed_4), IDOrdered);

    FORl(i, 0, k)
    {
        Final.push_back(Data(compressed_1[i].fi, compressed_3[i].fi, compressed_2[i].fi, compressed_4[i].fi));
    }

    FORl(z, 0, k)
    {
        FOR(i, min(Final[i].x1, Final[i].x2) + 1, max(Final[i].x1, Final[i].x2))
        {
            FOR(j, min(Final[i].y1, Final[i].y2) + 1, max(Final[i].y1, Final[i].y2))
            {
                plat[i][j] = plat[i][j] | (1LL << z);
            }
        }
    }

    FOR(i, 1, k)
    {
        FOR(j, 1, k)
        {
            if(avail[i][j])
            {
                ++res;
                BFS(ii(i, j), 499, 499);
            }
        }
    }
}



//Output
void Solve()
{
    while(scanf("%d%d", &m, &n) == 2 && m && n)
    {
        scanf("%d", &k);
        if(m <= 100 && n <= 100) Sub1();
        else Sub2();
    }

}

//Main Procedure
int main()
{
    //FileInit();
    Solve();
    return 0;
}
