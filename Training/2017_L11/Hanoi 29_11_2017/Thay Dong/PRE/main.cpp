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
#define task "PRE"
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

const int nextx[4] = {-1, 0, 1, 0};  // L - D - R - U
const int nexty[4] = {0, -1, 0, 1};
const double pi = acos(-1.0);
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int max_x, max_y, n, nChip, SOutside;
vvi plat, cc;
double res;
vvb avail;
vii coor;

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

//Enter
void Enter()
{
    int u, v;
	cin >> n;
	FOR(i, 1, n)
	{
	    scanf("%d%d", &u, &v);
	    coor.push_back(ii(u, v));
	    max_x = max(u, max_x);
	    max_y = max(v, max_y);
	}
}

//Subtask 1
void BFS(ii start, int n_lim, int m_lim)
{
    queue<ii> q; q.push(start);
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
            if(x >= 0 && y >= 0 && x <= n_lim && y <= m_lim && avail[x][y])
            {
                if(plat[x][y] != -1)
                {
                    avail[x][y] = false;
                    q.push(ii(x, y));
                    ++SOutside;
                }
            }
        }
    }
}

void Sub1()
{
    plat = vvi(max_x + 10, vi(max_y + 10, 0));
    avail = vvb(max_x + 10, vb(max_y + 10, true));
    for(ii x: coor)
    {
        plat[x.first][x.second] = -1;
    }
    BFS(ii(0, 0), max_x, max_y);
    ++SOutside;

    res = double((max_x+1)*(max_y+1) - SOutside - ((n*2+4)*(1-0.5*0.5*pi)/4) - (0.5*0.5*pi*n));

//    FOR(i, 1, max_x)
//    {
//        FOR(j, 1, max_y)
//        {
//            cout << plat[i][j] << " ";
//        }
//        puts("");
//    }

    printf("%.5lf", res);

}



//Process




//Output





//Main Procedure
int main()
{
    FileInit();
    Enter();
    Sub1();
    FileClose();
    return 0;
}
