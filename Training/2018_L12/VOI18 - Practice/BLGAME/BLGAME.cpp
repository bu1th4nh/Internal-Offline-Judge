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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int a, b, c, m, n, k, res;
vvb avail, is_valid, done;

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
    scanf("%d%d%d%d%d%d", &a, &b, &c, &m, &n, &k);
    avail = is_valid = done = vvb(m+2, vb(n+2, 1));

    FOR(i, 0, n+1) avail[0][i] = avail[m+1][i] = done[0][i] = done[m+1][i] = is_valid[0][i] = is_valid[m+1][i] = 0;
    FOR(i, 0, m+1) avail[i][0] = avail[i][n+1] = done[i][0] = done[i][n+1] = is_valid[i][0] = is_valid[i][n+1] = 0;

    int u, v;

    res = 0;
    FOR(i, 1, k)
    {
        scanf("%d%d", &u, &v);
        is_valid[u][v] = 0;
    }
}

//Check
void sub1()
{
    queue<ii> q;
    res = 1;

    int nextx[4] = {-1, 0, 0, 1};
    int nexty[4] = {0, -1, 1, 0};

    q.push(ii(1, 1));
    is_valid[1][1] = 0;

    while(!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;

        q.pop();
        FOR(i, 0, 3)
        {
            int x = curx + nextx[i];
            int y = cury + nexty[i];

            if(is_valid[x][y])
            {
                is_valid[x][y] = avail[x][y] = 0;
                ++res;
                q.push(ii(x, y));
            }
        }
    }

    cout << res << el;
}

//Process
struct data_s2
{
    int top_l_x, top_l_y, sz;

    data_s2(int x, int y, int _sz): top_l_x(x), top_l_y(y), sz(_sz) {}
    data_s2() {}

    vector<data_s2> transform(int &res, vvb &is_valid, vvb &avail)
    {
        int x, y, ok;
        vector<data_s2> ret;

        //------------------------------------------------------------
        //Up: x--
        x = top_l_x - 1; ok = done[x][top_l_y];
        FORl(i, 0, sz) if(!is_valid[x][top_l_y + i])
        {
            ok = 0;
            break;
        }
        if(ok)
        {
            FORl(xx, 0, sz)
            {
                FORl(yy, 0, sz)
                {
                    res += avail[xx+x][yy+top_l_y];
                    avail[xx+x][yy+top_l_y] = 0;
                }
            }
            ret.push_back(data_s2(x, top_l_y, sz));
        }


        //------------------------------------------------------------
        //Down: x++
        x = top_l_x + 1; ok = done[x][top_l_y];
        FORl(i, 0, sz) if(!is_valid[x + sz - 1][top_l_y + i])
        {
            ok = 0;
            break;
        }
        if(ok)
        {
            FORl(xx, 0, sz)
            {
                FORl(yy, 0, sz)
                {
                    res += avail[xx+x][yy+top_l_y];
                    avail[xx+x][yy+top_l_y] = 0;
                }
            }
            ret.push_back(data_s2(x, top_l_y, sz));
        }

        //------------------------------------------------------------        //Left: y--
        y = top_l_y - 1; ok = done[top_l_x][y];
        FORl(i, 0, sz) if(!is_valid[top_l_x + i][y])
        {
            ok = 0;
            break;
        }
        if(ok)
        {
            FORl(xx, 0, sz)
            {
                FORl(yy, 0, sz)
                {
                    res += avail[top_l_x+xx][y+yy];
                    avail[top_l_x+xx][y+yy] = 0;
                }
            }
            ret.push_back(data_s2(top_l_x, y, sz));
        }

        //------------------------------------------------------------
        //Right: y++
        y = top_l_y + 1; ok = done[top_l_x][y];
        FORl(i, 0, sz) if(!is_valid[top_l_x + i][y + sz - 1])
        {
            ok = 0;
            break;
        }
        if(ok)
        {
            FORl(xx, 0, sz)
            {
                FORl(yy, 0, sz)
                {
                    res += avail[top_l_x+xx][y+yy];
                    avail[top_l_x+xx][y+yy] = 0;
                }
            }
            ret.push_back(data_s2(top_l_x, y, sz));
        }
        return ret;
    }
};
void sub2()
{
    queue<data_s2> qd;

    FOR(i, 1, a)
    {
        FOR(j, 1, a) avail[i][j] = 0;
    }
    res += a*a;


    qd.push(data_s2(1, 1, a));
    done[1][1] = 0;
    while(!qd.empty())
    {
        data_s2 cur = qd.front();
        qd.pop();

        vector<data_s2> nxt = cur.transform(res, is_valid, avail);
        for(data_s2 x: nxt)
        {
            done[x.top_l_x][x.top_l_y] = 0;
            qd.push(x);
        }
    }

    cout << res << el;
}


//Output
void Solve()
{
    if(a == b && b == c && a == 1) sub1();
    else if(a == b && b == c) sub2();
    else
    {
        srand(time(NULL));
        if(rand() % 1) sub1();
        else sub2();
    }
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
