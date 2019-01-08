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
#define task ""
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
int tc, a[64], b[64];



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

//Enter
void Enter()
{
	//Enter value
}

//Check
void Query1(int k, int v)
{
    int tup, tdown;

    int n = 1 << k;
    int row = (v - 1) / n;
    int col = v % n; if(col == 0) col = n; --col;

    int up = 0, down = 1;

    FORb(i, k-1, 0)
    {
        if(row & b[i]) tup = down - 1, down += 2*up + 1, up = tup, row ^= a[i];
        else up = 2*up + down;

        if(col & b[i]) tup = down - 1, down += 2*up + 1, up = tup, col ^= a[i];
        else up = 2*up + down;

        if(row == 0 && col == 0) break;
    }

    printf("%d\n", down);
}
void Query2(int k, int x)
{
    //
}


//Process
void PreProcess()
{
    b[0] = 1;
    FOR(i, 1, 31) b[i] = 1 << i;
    a[0] = 1;
    FOR(i, 1, 31) a[i] = b[i] | a[i-1];
}


//Output





//Main Procedure
int main()
{
    PreProcess();
    Query1(2, 16);
    Query1(2, 2);
    return 0;
}
