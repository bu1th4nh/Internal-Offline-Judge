//Libraries and namespaces
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;


//=====================================
//Macros
#define task "INTROSPECT"
#define maxvalueinp (int)(2*10e3+100)
#define MODUL (int)(10e9+57)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
int a[maxvalueinp][maxvalueinp];
int m, n;
int res;



//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP(task)
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

//Input
void Input()
{
    cin >> n >> m;
    FORi(1, n)
    {
        FORj(1, m)
        {
            int x;
            cin >> x;
            a[i][j] = a[i+n][j] = a[i][j+m] = a[i+n][j+m] = x;
        }
    }


    //Debug
    FORi(1, 2*n)
    {
        FORj(1, 2*m)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

//Check
bool Check(int srcx,int srcy)
{
    return(a[srcx][srcy]==a[srcx+1][srcy] && a[srcx][srcy]==a[srcx][srcy+1] && a[srcx][srcy]==a[srcx+1][srcy+1]);
}

//Process
void Process()
{
    res = -INFINITY;
    FORi(1, 2)
    {
        FORj(1, 2)
        {
            int x = 0;
            for(int i1 = i; i1<i+n-1; ++i1)
            {
                for(int j1 = j; j1<j+m-1; ++j1)
                {
                    if(Check(i1, j1)) ++x;
                }
            }
            res = max(res, x);
        }
    }
    cout << res;
}



//Output





//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
