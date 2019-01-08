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
#define task "LOCK"
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
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, x, y;
string cmd;

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

//Main Procedure
int main()
{
    FileInit();
	int l, u, r, d;
	scanf("%d", &n);

	char str[1048576];
	scanf("%s", &str);
	cmd = string(str);

	scanf("%d%d", &x, &y);
	l = r = u = d = n;

	if(x >= 0) l = 0; if(x <= 0) r = 0;
	if(y <= 0) u = 0; if(y >= 0) d = 0;

    FORl(i, 0, n)
    {
        switch (cmd[i])
        {
        case 'L':
            {
                if(x < 0) ++x, l = i + 1;
                break;
            }
        case 'U':
            {
                if(y > 0) --y, u = i + 1;
                break;
            }
        case 'R':
            {
                if(x > 0) --x, r = i + 1;
                break;
            }
        case 'D':
            {
                if(y < 0) ++y, d = i + 1;
                break;
            }

        default:
            break;
        }
        if(x == 0 && y == 0) break;
    }

    if(y == 0 && y == 0)
    {
        printf("%d %d %d %d", l, u, r, d);
        return 0;
    }
    else printf("-1");

    FileClose();

    return 0;
}
