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
#define task "GBOX"
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


//#define DEBUG



//=====================================
//Typedefs
struct data
{
    typedef vector<bool> vb;        //Boolean part
    typedef vector<vb> vvb;
    typedef vector<vvb> vvvb;
    typedef vector<vvvb> vvvvb;
    typedef vector<int> vi;         //Integers part
    typedef vector<vi> vvi;
    typedef vector<vvi> vvvi;
    typedef vector<vvvi> vvvvi;
    typedef vector<data> vd;        //Data part
    typedef vector<vd> vvd;
    typedef vector<vvd> vvvd;
    typedef vector<vvvd> vvvvd;
    typedef tuple<data, int> tdi;   //Sendback packet part


    int top_left_x;
    int top_left_y;
    int top_left_z;
    int orientation;

//Initialization
    data() {}
    data(int tlx, int tly, int tlz, int ori): top_left_x(tlx), top_left_y(tly), top_left_z(tlz), orientation(ori)
    {
        /** \brief This is the complete constructor of block data.
         *
         * \param tlx, tly, tlz:  The coordinate (x, y, z) of top-left block.
         * \param orientation:    The orientation of the whole 3 blocks:
         *
         * \param 0: The whole 3 blocks lie on the relative z axis coordinate
         * \param 1: The whole 3 blocks lie on the relative x axis w/ y-coordinate (y-1, y, y+1) - Horizontal
         * \param 2: The whole 3 blocks lie on the relative y axis m/ x-coordinate (x-1, x, x+1) - Vertical
         *
         */

        /*          The coordinate system is shown as below
                                (z)---->(y)
                                 |
                                 |
                                 V
                                (x)
        */

    }
    void initialize(int tlx, int tly, int tlz, int ori)
    {
        top_left_x  = tlx;
        top_left_y  = tly;
        top_left_z  = tlz;
        orientation = ori;
    }
    data transform(int state)
    {
        data ret = *this;
        if(orientation == 0)
        {
            ret.top_left_z  = 1;
            switch(state)
            {
                case 0:         //Flip rightward
                {
                    ret.top_left_y += 1;
                    ret.orientation = 1;
                    break;
                }
                case 1:         //Flip downward
                {
                    ret.top_left_x += 1;
                    ret.orientation = 2;
                    break;
                }
                case 2:         //Flip leftward
                {
                    ret.top_left_y -= 3;
                    ret.orientation = 1;
                    break;
                }
                case 3:         //Flip upward
                {
                    ret.top_left_x -= 3;
                    ret.orientation = 2;
                    break;
                }
                default: break;
            }
        }
        if(orientation == 1)
        {
            switch(state)
            {
                case 0:         //Flip rightward
                {
                    ret.top_left_y += 3;
                    ret.top_left_z  = 3;
                    ret.orientation = 0;
                    break;
                }
                case 1:         //Flip downward
                {
                    ret.top_left_x += 1;
                    break;
                }
                case 2:         //Flip leftward
                {
                    ret.top_left_y -= 1;
                    ret.top_left_z  = 3;
                    ret.orientation = 0;
                    break;
                }
                case 3:         //Flip upward
                {
                    ret.top_left_x -= 1;
                    break;
                }
            }
        }
        if(orientation == 2)
        {
            switch(state)
            {
                case 0:         //Flip rightward
                {
                    ret.top_left_y += 1;
                    break;
                }
                case 1:         //Flip downward
                {
                    ret.top_left_x += 3;
                    ret.top_left_z  = 3;
                    ret.orientation = 0;
                    break;
                }
                case 2:         //Flip leftward
                {
                    ret.top_left_y -= 1;
                    break;
                }
                case 3:         //Flip upward
                {
                    ret.top_left_x -= 1;
                    ret.top_left_z  = 3;
                    ret.orientation = 0;
                    break;
                }
            }
        }
        return ret;
    }


//Verification
    bool verify_range(int n, int m)
    {
        int &x = top_left_x;
        int &y = top_left_y;
        if(orientation == 0)
        {
            if(x < 1 || n < x || y < 1 || m < y) return 0;
            return 1;
        }
        if(orientation == 1)
        {
            if(x < 1 || n < x || y < 1 || m < y+2) return 0;
            return 1;
        }
        if(orientation == 2)
        {
            if(x < 1 || n < x+2 || y < 1 || m < y) return 0;
            return 1;
        }
        return 0;
    }
    bool verify(int n, int m, const vvvvb &avail, const vvb &is_not_obstacle)
    {
        if(!verify_range(n, m)) return 0;

        int &x = top_left_x;
        int &y = top_left_y;
        int &o = orientation;


        if(o == 0) return avail[x][y][3][o] && is_not_obstacle[x][y];
        if(o == 1) return avail[x][y][1][o] && is_not_obstacle[x][y] && is_not_obstacle[x][y+1] && is_not_obstacle[x][y+2];
        if(o == 2) return avail[x][y][1][o] && is_not_obstacle[x][y] && is_not_obstacle[x+1][y] && is_not_obstacle[x+2][y];


        return 0;
    }
    bool isNULL()
    {
        return top_left_x == -1 && top_left_y == -1 && top_left_z == -1 && orientation == -1;
    }

//Operations
    int get_distance(const vvvvi &dis)
    {
        return dis[top_left_x][top_left_y][top_left_z][orientation];
    }
    void set_as_visited(vvvvb &avail)                   //Well, with quadruple-v :)))
    {
        avail[top_left_x][top_left_y][top_left_z][orientation] = 0;
    }
    tdi getPrevious(vvvvd &trace, vvvvi &trace_op)
    {
        if(isNULL()) return make_tuple(data(-1, -1, -1, -1), -1);
        int &x = top_left_x;
        int &y = top_left_y;
        int &z = top_left_z;
        int &o = orientation;

        return make_tuple(trace[x][y][z][o], trace_op[x][y][z][o]);
    }
    void update_distance(vvvvi &vtx_dist, vvvvd &trace, vvvvi &trace_op, data &cur_vtx, int current_dist, int state)
    {
        int &x = top_left_x;
        int &y = top_left_y;
        int &z = top_left_z;
        int &o = orientation;

        if(trace[x][y][z][o].isNULL() || vtx_dist[x][y][z][o] > current_dist + 1)
        {
            vtx_dist[x][y][z][o] = current_dist + 1;
            trace_op[x][y][z][o] = state;
            trace[x][y][z][o] = cur_vtx;
        }
    }


//Debugging
    void ___debug()
    {
        #ifdef DEBUG
            cerr << "Top-left: " << top_left_x << sp << top_left_y << sp << top_left_z << " Orientation: ";
            if(orientation == 0) cerr << "Z-Axis\n";
            if(orientation == 1) cerr << "Horizontal\n";
            if(orientation == 2) cerr << "Vertical\n";
        #endif // DEBUG
    }
};


const int inf = 1000000007;
const data NULL_DATA(-1, -1, -1, -1);
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<data> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vd> vvd;
typedef vector<vvb> vvvb;
typedef vector<vvi> vvvi;
typedef vector<vvd> vvvd;
typedef vector<vvd> vvvd;
typedef vector<vvvb> vvvvb;
typedef vector<vvvi> vvvvi;
typedef vector<vvvd> vvvvd;
vvvvi vtx_dist, trace_operations;
vvb is_not_obstacle;
data src, dst;
vvvvb avail;
vvvvd trace;
int m, n;

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
    int x, y;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &x, &y); src.initialize(++x, ++y, 3, 0);
    scanf("%d%d", &x, &y); dst.initialize(++x, ++y, 3, 0);

    trace_operations = vvvvi(n+30, vvvi(m+30, vvi(4, vi(4, -1))));
    trace = vvvvd(n+30, vvvd(m+30, vvd(4, vd(4, NULL_DATA))));
    vtx_dist = vvvvi(n+30, vvvi(m+30, vvi(4, vi(4, inf))));
    avail = vvvvb(n+30, vvvb(m+30, vvb(4, vb(4, 1))));
    is_not_obstacle = vvb(n+30, vb(m+30, 1));

    char str[10101];
    FOR(i, 1, n)
    {
        scanf("%s", &str);
        FORl(j, 0, m) if(str[j] == '1')
        {
            avail[i][j+1][1][0] = avail[i][j+1][2][0] = avail[i][j+1][3][0] = 0;
            avail[i][j+1][1][1] = avail[i][j+1][2][1] = avail[i][j+1][3][1] = 0;
            avail[i][j+1][1][2] = avail[i][j+1][2][2] = avail[i][j+1][3][2] = 0;

            is_not_obstacle[i][j+1] = 0;
        }
    }
}

//Check
void FloodFill(data start_vtx)
{
    data cur_vtx, next_vtx;

    queue<data> que;
    que.push(start_vtx);
    start_vtx.set_as_visited(avail);
    trace[start_vtx.top_left_x][start_vtx.top_left_y][start_vtx.top_left_z][0] = start_vtx;
    vtx_dist[start_vtx.top_left_x][start_vtx.top_left_y][start_vtx.top_left_z][0] = 0;



    #ifdef DEBUG
        cerr << "Start vertex: "; start_vtx.___debug();
    #endif //DEBUG



    while(!que.empty())
    {
        cur_vtx = que.front(); que.pop();



        #ifdef DEBUG
                cerr << "----------------------------------------------------------------------\n";
                cerr << "Current Vertex: \n"; cur_vtx.___debug();
        #endif // DEBUG



        FOR(i, 0, 3)
        {
            next_vtx = cur_vtx.transform(i);



            #ifdef DEBUG
                        cerr << "-------------------------------------\n";
                        cerr << "Current state: " << i; if(i == 0) cerr << " - Right\n"; if(i == 1) cerr << " - Down\n"; if(i == 2) cerr << " - Left\n"; if(i == 3) cerr << " - Up\n";
                        next_vtx.___debug(); //getchar();
            #endif // DEBUG



            if(next_vtx.verify(n, m, avail, is_not_obstacle))
            {
                que.push(next_vtx);
                next_vtx.set_as_visited(avail);



                #ifdef DEBUG
                    cerr << "Next vertex is being pushed into queue\n";
                #endif // DEBUG
            }
            if(next_vtx.verify_range(n, m))
            {
                next_vtx.update_distance(vtx_dist, trace, trace_operations, cur_vtx, cur_vtx.get_distance(vtx_dist), i);



                #ifdef DEBUG
                    cerr << "Distance updated: " << next_vtx.get_distance(vtx_dist) << el;
                #endif // DEBUG
            }

            //getchar();
        }
    }
}

//Process
void Solve()
{
    int x = 1;
    vi res;

    FloodFill(src);
    if(dst.get_distance(vtx_dist) == inf) cout << "inf\n";
    else
    {
        cout << dst.get_distance(vtx_dist) << el;
        while(x != -1)
        {
            auto packet = dst.getPrevious(trace, trace_operations);
            tie(dst, x) = packet;

            if(x == -1) break;
            res.push_back(x);
        }


        reverse(whole(res));
        for(auto y: res) cout << y << sp;
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
