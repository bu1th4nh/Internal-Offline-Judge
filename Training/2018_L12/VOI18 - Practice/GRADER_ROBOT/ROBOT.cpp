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
#define task "robot"
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


const int nextx[4] = {0, -1, 0, 1};
const int nexty[4] = {-1, 0, 1, 0};
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vvi freq, last_ori, last_step;
int sx, sy, ori, n, steps;
vvc maze;


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
template<class T> T abs(T x)
{
    return x < 0 ? -x : x;
}

//Enter
void Enter()
{
    char str[1010];
	scanf("%d%d%d%d\n", &n, &sx, &sy, &steps);
	maze = vvc(n+24, vc(n+24, '.'));

	FOR(j, 1, n)
	{
	    scanf("%s", &str);
	    FORl(i, 0, n) maze[i+1][j] = str[i];
	}
}


//Check
bool is_in_X(int x, int y)
{
    return x >= 1 && x <= n;
}
bool is_in_Y(int x, int y)
{
    return y >= 1 && y <= n;
}
bool checkCornerCase(int x, int y, int o)
{
    bool u = y < 0;
    bool d = y > n+1;
    bool l = x < 0;
    bool r = x > n+1;


    if((u && l) || (u && r) || (d && l) || (d && r)) return 1;
    if((u && o != 2) || (l && o != 3) || (d && o != 0) || (r && o != 1)) return 1;
}
void warpCoord(int &x, int &y, int &s, int o)
{
    if(checkCornerCase(x, y, o))
    {
        x += nextx[o] * s;
        y += nexty[o] * s;

        s = 0;
    }
    else if(x > n+1 || y > n+1 || x < 0 || y < 0)
    {
        if(is_in_X(x, y))
        {
            if(y > n+1)
            {
                if(y - n - 1 >= s)
                {
                    s  = 0;
                    y -= s;
                }
                else
                {
                    s -= y - n - 1;
                    y  = n + 1;
                }
            }
            else
            {
                if(abs(y) > s)
                {
                    s  = 0;
                    y += s;
                }
                else
                {
                    s -= abs(y);
                    y  = 0;
                }
            }
        }
        if(is_in_Y(x, y))
        {
            if(x > n+1)
            {
                if(x - n - 1 >= s)
                {
                    s  = 0;
                    x -= s;
                }
                else
                {
                    s -= x - n - 1;
                    x  = n + 1;
                }
            }
            else
            {
                if(abs(x) > s)
                {
                    s  = 0;
                    x += s;
                }
                else
                {
                    s -= abs(x);
                    x  = 0;
                }
            }
        }
    }
}
bool isObstacle(int x, int y, int o)
{
    if(x + nextx[o] > n+1 || x + nextx[o] < 0 || y + nexty[o] > n+1 || y + nexty[o] < 0) return 0;
    return maze[x + nextx[o]][y + nexty[o]] == '#';
}
void debug()
{
    while(1)
    {
        int x, y, s, o;
        cin >> x >> y >> s >> o;
        warpCoord(x, y, s, o);
        cerr << x << sp << y << sp << s << el;
    }
}

//Process
void Sub1()
{
    while(steps)
    {
        warpCoord(sx, sy, steps, ori);

        if(sx >= 0 && sx <= n+1 && sy >= 0 && sy <= n+1)
        {
            while(isObstacle(sx, sy, ori)) ori = (ori + 1) % 4;
            sx += nextx[ori];
            sy += nexty[ori];
            --steps;
        }
    }

    cout << sx << sp << sy << sp;
}
void Sub2()
{
	freq = vvi(n+24, vi(n+24, 0));
	last_ori = vvi(n+24, vi(n+24, -1));
	last_step = vvi(n+24, vi(n+24, 0));

    while(steps)
    {
        warpCoord(sx, sy, steps, ori);

        if(sx >= 0 && sx <= n+1 && sy >= 0 && sy <= n+1)
        {
            while(isObstacle(sx, sy, ori)) ori = (ori + 1) % 4;


            if(last_ori[sx][sy] != ori) last_ori[sx][sy] = ori;
            else
            {
                if(freq[sx][sy] >= 2)
                {
                    int path_dist = last_step[sx][sy] - steps;
                    steps %= path_dist;
                    Sub1();
                    return;
                }
            }

            ++freq[sx][sy];
            last_step[sx][sy] = steps;

            sx += nextx[ori];
            sy += nexty[ori];
            --steps;

        }
    }

    cout << sx << sp << sy << sp;
}


//Output
void Solve()
{
    ori = 0;        //Initial
    warpCoord(sx, sy, steps, ori);
    //cerr << sx << sp << sy << el;

    if(steps <= 1000000) Sub1();
    else Sub2();

    //Sub2();
}



//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
