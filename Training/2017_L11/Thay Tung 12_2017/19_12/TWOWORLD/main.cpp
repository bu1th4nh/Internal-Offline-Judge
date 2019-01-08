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
#include <tuple>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "TWOWORLD"
#define x first
#define y second
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


const char MAP_LIMIT = 'X';
const int next_x[4] = {-1, 0, 0, 1};
const int next_y[4] = {0, -1, 1, 0};
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vii> vvii;
typedef queue<ii> qii;
int m, n, nQuery, nCC1, nCC0;
vvi a;
vvc c;

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
	scanf("%d%d", &m, &n);

	c = vvc(m+2, vc(n+2, MAP_LIMIT));
	a = vvi(m+2, vi(n+2, 0));

	FOR(i, 1, m)
	{
	    FOR(j, 1, n) cin >> c[i][j];
	}
}

//Check
void FloodFill(ii start, char type)
{
    qii que;
    que.push(start);
    a[start.x][start.y] = (type == '0') ? nCC0 : -nCC1;

    while(!que.empty())
    {
        ii cur = que.front(); que.pop();

        FOR(i, 0, 3)
        {
            if(a[cur.x + next_x[i]][cur.y + next_y[i]] == 0 && c[cur.x + next_x[i]][cur.y + next_y[i]] == type)
            {
                que.push(ii(cur.x + next_x[i], cur.y + next_y[i]));
                a[cur.x + next_x[i]][cur.y + next_y[i]] = (type == '0') ? nCC0 : -nCC1;
                c[cur.x + next_x[i]][cur.y + next_y[i]] = MAP_LIMIT;
            }
        }
    }
}



//Process
void Solve()
{
    nCC0 = nCC1 = 0;

    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            if(c[i][j] != MAP_LIMIT)
            {
                if(c[i][j] == '0') ++nCC0;
                else ++nCC1;

                char tmp = c[i][j];
                c[i][j] = MAP_LIMIT;
                FloodFill(ii(i, j), tmp);
            }
        }
    }


    scanf("%d", &nQuery);

    while(nQuery--)
    {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

        if(a[r1][c1] == a[r2][c2]) printf("%s\n", (a[r1][c1] < 0) ? "Decimal" : "Binary");
        else printf("Neither\n");
    }

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
