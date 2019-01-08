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
#define task "ROBOT"
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
int sx, sy, n, steps;
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
	scanf("%d%d%d%d\n", &n, &sx, &sy, &steps);
	maze = vvc(n+24, vc(n+24));

	FOR(j, 1, n)
	{
	    FOR(i, 1, n) maze[i][j] = getchar();
        getchar();
	}
}

//Check
void sub1()
{
    if(sy < 1 || sx < 1 || sx > n)
    {
        cout << sx << sp << sy - steps << el;
        return;
    }

    int orien = 0;
    while(steps)
    {
        if(sx < 1 || sx > n || sy < 1 || sy > n)
        {
            sx += nextx[orien];
            sy += nexty[orien];
            --steps;
        }
        else
        {
            while(maze[sx + nextx[orien]][sy + nexty[orien]] == '#') orien = (orien + 1) % 4;
            sx += nextx[orien];
            sy += nexty[orien];
            --steps;
        }
    }

    cout << sx << sp << sy << el;
}

//Process
void Sub2()
{
	freq = vvi(n+24, vi(n+24));
	last_ori = vvi(n+24, vi(n+24, -1));
	last_step = vvi(n+24, vi(n+24, 0));

    if(sy < 1 || sx < 1 || sx > n)
    {
        cout << sx << sp << sy - steps << el;
        return;
    }

    int orien = 0;
    while(steps)
    {
        if(sx < 1 || sx > n || sy < 1 || sy > n)
        {
            sx += nextx[orien];
            sy += nexty[orien];
            --steps;


            if(sy < 1 || sx < 1 || sx > n)
            {
                cout << sx + steps * nextx[orien] << sp << sy + steps * nexty[orien] << el;
                return;
            }
        }
        else
        {
            while(maze[sx + nextx[orien]][sy + nexty[orien]] == '#') orien = (orien + 1) % 4;
            sx += nextx[orien];
            sy += nexty[orien];
            ++freq[sx][sy];
            --steps;


            if(last_ori[sx][sy] == -1)
            {
                last_ori[sx][sy] = orien;
            }
            else
            {
                if(last_ori[sx][sy] != orien)
                {
                    last_ori[sx][sy] = orien;
                    last_step[sx][sy] = steps;
                }
                else
                {
                    if(freq[sx][sy] >= 3)
                    {
                        int dist = last_step[sx][sy] - steps;
                        steps %= dist;

                        sub1();
                        return;
                    }
                }
            }
        }
    }

    cout << sx << sp << sy << el;
}


//Output
void Solve()
{
    if(steps <= 1000000) sub1();
    else Sub2();
}



//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
