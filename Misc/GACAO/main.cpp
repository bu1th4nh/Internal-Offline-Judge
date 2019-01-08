//#include <bits/stdc++.h>
//#include "stdafx.h"
#include <utility>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

//=====================================
//Macros
#define task ""
#define maxmn (int)(1e3+1)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORlj(x, y) for(int j=x; j<y; ++j)
#define FORlk(x, y) for(int k=x; k<y; ++k)

//=====================================
//Typedef
typedef vector<string> vstr;
typedef pair<int, int> p2i;
typedef queue<p2i> qp;
vstr a;
qp loc;
int res;
int m, n;
int val[maxmn][maxmn];
bool avail[maxmn][maxmn];
int nextx[4] = {1, 0, -1, 0};
int nexty[4] = {0, 1, 0, -1};

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
    memset(avail, true, sizeof(avail));
}

//Input
void Input()
{
    cin >> n >> m;
    cin.ignore(1);
    FORi(1, n)
    {
        string x;
        getline(cin, x);
        for(unsigned int j=0; j<x.length(); ++j)
        {
            if(x[j]=='*') val[i-1][j] = -1;
            if((x[j]=='o')||(x[j]=='O')) val[i-1][j] = 1;
            if(x[j]==' ') val[i-1][j] = 0;
        }
        a.push_back(x);
    }

    /*
    FORlk(0, n) cout << a[k] << endl;   //Debug
    FORli(0, n)
    {
        FORlj(0, m)
        {
            cout << val[i][j] << " ";
        }
        cout << endl;
    }
    */

}

//Check
bool Check(int u11, int v11)
{
    return (val[u11][v11]!=-1)&&(avail[u11][v11])&&(u11<n)&&(v11<m);
}
bool IsUnderLim(int u11, int v11)
{
    return (u11>=0)&&(v11>=0)&&(u11<n)&&(v11<m);
}
bool IsExceedLim(int u11, int v11)
{
    return (u11==0)||(v11==0)||(u11==n-1)||(v11==m-1);
}

//Flood Fill
void FloodFill()
{
    int localres = 0;
    bool IsOpen = false;
    while(!loc.empty())
    {
        p2i cur = loc.front();
        loc.pop();
        int x = cur.first, y = cur.second;
        avail[x][y] = false;
        if(val[x][y]!=-1)
        {
            IsOpen = IsOpen || IsExceedLim(x, y);
            localres += (val[x][y]==1) ? 1 : 0;
        }
        FORk(0, 3)
        {
            int u = x + nextx[k];
            int v = y + nexty[k];
            if ((val[u][v]!=-1)&&IsUnderLim(u, v)&&avail[u][v])
            {
                loc.push(make_pair(u, v));
            }
        }
    }
    res += (IsOpen) ? 0 : localres;
}


//Process
void Process()
{
    Init();
    FORli(0, n)
    {
        FORlj(0, m)
        {
            if (Check(i, j))
            {
                //cout << i << ' ' << j << endl; //Debug
                loc.push(make_pair(i, j));
                FloodFill();
            }
        }
    }
    cout << res;
}


int main()
{
    Input();
    Process();
    return 0;
}
