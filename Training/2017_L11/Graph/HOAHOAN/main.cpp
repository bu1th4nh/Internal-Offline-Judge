
/// ============================================== Accepted ============================================== ///


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
#define task "HOAHOAN"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)(1024)
#define MODUL (int)(1234567890)
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
typedef vector<ii> vii;
typedef queue<ii> qii;
typedef long long ll;
int nextx[4] = {-1, 0, 0, 1};
int nexty[4] = {0, -1, 1, 0};
int FireTime[maxinp][maxinp];
int JoeTime[maxinp][maxinp];
char a[maxinp][maxinp];
qii qJoe, qFire;
int m, n, res;

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
    cout << "==================DEBUG==================" << endl;
    cout << "Joe's Time: " << endl;
    FOR(i, 1, m)
    {
        FOR(j, 1, n) cout << JoeTime[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << "Fire's Time: " << endl;
    FOR(i, 1, m)
    {
        FOR(j, 1, n) cout << FireTime[i][j] << " ";
        cout << endl;
    }
    cout << "================END-DEBUG================" << endl;
    cout << endl;
}

//Enter
void Enter()
{
	scanf("%d%d", &m, &n);
	FOR(i, 1, m)
	{
	    FOR(j, 1, n)
	    {
	        cin >> a[i][j];
	        if(a[i][j] == '#')
	        {
                JoeTime[i][j] = FireTime[i][j] = -1;
	        }
	        else if(a[i][j] == 'J')
            {
                JoeTime[i][j] = 1;
                FireTime[i][j] = MODUL;
                qJoe.push(ii(i, j));
            }
            else if(a[i][j] == 'F')
            {
                FireTime[i][j] = 1;
                JoeTime[i][j] = MODUL;
                qFire.push(ii(i, j));
            }
            else
            {
                JoeTime[i][j] = FireTime[i][j] = MODUL;
            }
	    }
	}
}

//Check
bool IsUnderBound(int __x, int __y)
{
    return (__x >= 1 && __x <= m && __y >= 1 && __y <= n);
}


void FloodFill()
{
    while(!qJoe.empty())
    {
        int curx = qJoe.front().first;
        int cury = qJoe.front().second;
        qJoe.pop();

        FORl(i, 0, 4)
        {
            int x = curx + nextx[i];
            int y = cury + nexty[i];

            if(a[x][y] != '#' && IsUnderBound(x, y))
            {
                if(JoeTime[x][y] == MODUL)
                {
                    qJoe.push(ii(x, y));
                }
                JoeTime[x][y] = min(JoeTime[x][y], JoeTime[curx][cury] + 1);
            }
        }
    }

    while(!qFire.empty())
    {
        int curx = qFire.front().first;
        int cury = qFire.front().second;
        qFire.pop();

        FORl(i, 0, 4)
        {
            int x = curx + nextx[i];
            int y = cury + nexty[i];

            if(a[x][y] != '#' && IsUnderBound(x, y))
            {
                if(FireTime[x][y] == MODUL)
                {
                    qFire.push(ii(x, y));
                }
                FireTime[x][y] = min(FireTime[x][y], FireTime[curx][cury] + 1);
            }
        }
    }



}


//Process
void Solve()
{
    //Debug();

    FloodFill();

    //Debug();

    res = MODUL;
    FOR(i, 1, n)
    {
        if(JoeTime[1][i] != -1 && JoeTime[1][i] != MODUL && JoeTime[1][i] < FireTime[1][i])
        {
            res = min(res, JoeTime[1][i]);
        }
        if(JoeTime[m][i] != -1 && JoeTime[m][i] != MODUL && JoeTime[m][i] < FireTime[m][i])
        {
            res = min(res, JoeTime[m][i]);
        }
    }


    FOR(i, 1, m)
    {
        if(JoeTime[i][1] != -1 && JoeTime[i][1] != MODUL && JoeTime[i][1] < FireTime[i][1])
        {
            res = min(res, JoeTime[i][1]);
        }
        if(JoeTime[i][n] != -1 && JoeTime[i][n] != MODUL && JoeTime[i][n] < FireTime[i][n])
        {
            res = min(res, JoeTime[i][n]);
        }
    }

    if( res != MODUL && res != -1 ) printf("%d", res);
    else printf("-1");

}


//Main Procedure
int main()
{
    //FileInit();
    Enter();
    Solve();
    //FileClose();
    return 0;
}
