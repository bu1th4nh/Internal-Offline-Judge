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
#define task "BLGAME"
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
//Typedefs
struct Data
{
    typedef unordered_map<int, int> mii;
    typedef vector<mii> vmii;
    typedef vector<vmii> vvmii;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<vvi> vvvi;

    int top_left_x, sz_x;       //State 1
    int top_left_y, sz_y;       //State 2
    int top_left_z, sz_z;       //State 3

    Data() {}
    Data(int tlx, int tly, int tlz, int szx, int szy, int szz): top_left_x(tlx), top_left_y(tly), top_left_z(tlz), sz_x(szx), sz_y(szy), sz_z(szz) {} 
    
    bool isMovable(const vvi &is_valid, int n, int m, int x1, int y1, int x2, int y2)
    {
        if(x1 <= 0 || x1 > m || x2 <= 0 || x2 > m || y1 <= 0 || y1 > n || y2 <= 0 || y2 > n) return 0;
        return (is_valid[x2][y2] - is_valid[x2][y1-1] - is_valid[x1-1][y2] + is_valid[x1-1][x2-1]) == 0;
    }
    vector<Data> transform(vvi &is_valid, vvmii &avail, vvi &is_green, int n, int m, int &res)
    {
        vector<Data> ret;

        //-------------------------------------------
        //Move upward
        if(isMovable(is_valid, n, m, top_left_x-1, top_left_y, top_left_x-1, top_left_y+sz_y-1) && avail[top_left_x-1][top_left_y][top_left_z] == 0)
        {
            avail[top_left_x-1][top_left_y][top_left_z] = 1;
            FORl(i, 0, sz_y) if(is_green[top_left_x-1][top_left_y+i] == 0)
            {
                is_green[top_left_x-1][top_left_y+i] = 1;
                ++res;
            }
            ret.push_back(Data(top_left_x-1, top_left_y, top_left_z, sz_x, sz_y, sz_z));
        }

        //Move downward
        if(isMovable(is_valid, n, m, top_left_x+sz_x, top_left_y, top_left_x+sz_x, top_left_y+sz_y-1) && avail[top_left_x+1][top_left_y][top_left_z] == 0)
        {
            avail[top_left_x+1][top_left_y][top_left_z] = 1;
            FORl(i, 0, sz_y) if(is_green[top_left_x+sz_x][top_left_y+i] == 0)
            {
                is_green[top_left_x+sz_x][top_left_y+i] = 1;
                ++res;
            }
            ret.push_back(Data(top_left_x+1, top_left_y, top_left_z, sz_x, sz_y, sz_z));
        }

        //Move leftward
        if(isMovable(is_valid, n, m, top_left_x, top_left_y-1, top_left_x+sz_x-1, top_left_y-1) && avail[top_left_x][top_left_y-1][top_left_z] == 0)
        {
            avail[top_left_x][top_left_y-1][top_left_z] = 1;
            FORl(i, 0, sz_x) if(is_green[top_left_x+i][top_left_y-1] == 0)
            {
                is_green[top_left_x+i][top_left_y-1] = 1;
                ++res;
            }
            ret.push_back(Data(top_left_x, top_left_y-1, top_left_z, sz_x, sz_y, sz_z));
        }

        //Move rightward
        if(isMovable(is_valid, n, m, top_left_x, top_left_y+sz_y, top_left_x+sz_x-1, top_left_y+sz_y) && avail[top_left_x][top_left_y+1][top_left_z] == 0)
        {
            avail[top_left_x][top_left_y+1][top_left_z] = 1;
            FORl(i, 0, sz_x) if(is_green[top_left_x+i][top_left_y+sz_y] == 0)
            {
                is_green[top_left_x+i][top_left_y+sz_y] = = 1;
                ++res;
            }
            ret.push_back(Data(top_left_x, top_left_y+1, top_left_z, sz_x, sz_y, sz_z));
        }

        //-------------------------------------------
        //Flip upward
        
    }

};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;

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

//Enter
void Enter()
{
    //
}

//Check
void sub1()
{
    //
}

//Output
void Solve()
{
    //
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
