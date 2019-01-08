//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
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
#define task "CAOGA"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)(1024)
#define MODUL (int)(1e9+57)
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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef queue<ii> qii;
typedef long long ll;
int nextx[4] = {-1, 0, 0, 1};
int nexty[4] = {0, -1, 1, 0};
bool avail[maxinp][maxinp];
char a[maxinp][maxinp];
int m, n, nFox, nChick;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
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
void Debug()
{
    cout << endl;
    FOR(i, 0, m+1)
    {
        FOR(j, 0, n+1)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//Enter
void Enter()
{
	nFox = nChick = 0;
	MEMS(avail, true);
	scanf("%d%d", &m, &n);
	FOR(i, 0, m+1)
	{
	    a[i][n+1] = '.';
	    a[i][0] = '.';
	}
	FOR(i, 0, n+1)
	{
	    a[m+1][i] = '.';
	    a[0][i] = '.';
	}
	FOR(i, 1, m)
	{
	    FOR(j, 1, n)
	    {
            cin >> a[i][j];
	    }
	}
}
//Check
bool Check(int _x, int _y)
{
    return (_x >= 0 && _y >= 0 && _x <= m+1 && _y <= n+1 && avail[_x][_y] && a[_x][_y] != '#');
}

//Pre-Process
void PreProcess()
{
    qii dir;
    dir.push(ii(0, 0));
    avail[0][0] = false;
    while(!dir.empty())
    {
        int curx = dir.front().first;
        int cury = dir.front().second;
        dir.pop();

        FORl(i, 0, 4)
        {
            int x = curx + nextx[i];
            int y = cury + nexty[i];
            if(x >= 0 && y >= 0 && x <= m+1 && y <= n+1 && a[x][y] != '#')
            {
                a[x][y] = '#';
                dir.push(ii(x, y));
            }
        }
    }
}


//Flood Fill
void FloodFill(int stx, int sty)
{
    qii dir;

    int chick = 0, fox = 0;

    dir.push(ii(stx, sty));
    if(a[stx][sty] == 'o') chick = 1;
    else if(a[stx][sty] == 'v') fox = 1;
    a[stx][sty] = '#';

    while(!dir.empty())
    {
        int curx = dir.front().first;
        int cury = dir.front().second;
        dir.pop();

        FORl(i, 0, 4)
        {
            int x = curx + nextx[i];
            int y = cury + nexty[i];
            if(x >= 0 && y >= 0 && x <= m+1 && y <= n+1 && a[x][y] != '#')
            {
                if(a[x][y] == 'o') ++chick;
                if(a[x][y] == 'v') ++fox;
                dir.push(ii(x, y));
                a[x][y] = '#';
                avail[stx][sty] = false;
            }
        }
    }

    if(chick > fox) nChick += chick;
    else nFox += fox;
}

//Process
void Solve()
{
    PreProcess();

    //Debug();

    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            if(a[i][j] != '#')
            {
                FloodFill(i, j);
            }
        }
    }

    //Debug();


    printf("%d %d", nFox, nChick);
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
