//This is an example of prioritized flood-fill
//#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <deque>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

//=====================================
//Macros
#define task ""
#define max (int)(1e3+1)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORlj(x, y) for(int j=x; j<y; ++j)
#define FORlk(x, y) for(int k=x; k<y; ++k)

//=====================================
//Typedef
typedef pair<int, int> p2i;
typedef deque<p2i> dqp;
dqp loc;
int m, n;
p2i src, dst;
char a[max][max];
int cost[max][max];
bool avail[max][max];
int nextx[4] = {-1, 0, 1, 0};
int nexty[4] = {0, -1, 0, 1};

//=====================================
//Functions and procedures
//Initialization
void FileInit()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void IOSOpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Init()
{
    memset(cost, 0, sizeof(cost));
    memset(avail, true, sizeof(avail));
    avail[src.first][src.second] = false;
    loc.push_back(src);
}

//Input
void Input()
{
    cin >> n >> m;
    FORi(1, n)
    {
        FORj(1, m)
        {
            char x;
            cin >> x;
            if(x == '*') src = make_pair(i, j);
            if(x == '#') dst = make_pair(i, j);
            a[i][j] = x;
        }
    }
}

//Check
bool Check(int p, int q)
{
    return (p<=n && q<=m && avail[p][q]);
}

//Process
void Process()
{
    while (!loc.empty())
    {
        p2i now = loc.front();
        loc.pop_front();
        int x = now.first, y = now.second;
        FORlk(0, 4)
        {
            int u = now.first + nextx[k];
            int v = now.second + nexty[k];
            if(Check(u, v))
            {
                if (a[x][y] == a[u][v])
                {
                    loc.push_front(make_pair(u, v));
                    cost[x][y] = cost[u][v];
                }
                else
                {
                    loc.push_back(make_pair(u, v));
                    cost[x][y] = cost[u][v] + 1;
                }
                avail[x][y] = false;
            }
        }
    }
    cout << cost[dst.first][dst.second];
}

//Main Procedure
int main()
{
    FileInit();
    Input();
    Init();
    Process();
    FileClose();
    return 0;
}
