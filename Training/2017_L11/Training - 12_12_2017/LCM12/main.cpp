/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
//=====================================//Solution
/*



*/
//=====================================
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
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "LCM12"
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

const int max_n = 1000000;
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
int changes[max_n+100];
int res[max_n+100];


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


//Process
void Prep()
{
    FOR(i, 1, max_n) changes[i] = i;
    FOR(i, 2, 1000)
    {
        FOR(j, 2, max_n/i) changes[i*j] = 1;
    }
    FOR(i, 2, 1000)
    {
        if(changes[i] == i)
        {
            int j = i;
            while(i*j <= max_n) changes[j*i] = i, j *= i;
        }
    }
    res[1] = 1;
    FOR(i, 2, max_n)
    {
        if(changes[i] != 2 && changes[i] != 5) res[i] = (res[i-1] * (changes[i] % 10)) % 10;
        else res[i] = res[i-1];
    }
    int h = 0;
    FOR(i, 2, max_n)
    {
        if(changes[i] == 2) ++h;
        if(changes[i] == 5) --h;
        switch (h % 4)
        {
        case 0:
            res[i] = (res[i] * 6) % 10;
            break;
        case 1:
            res[i] = (res[i] * 2) % 10;
            break;
        case 2:
            res[i] = (res[i] * 4) % 10;
            break;
        case 3:
            res[i] = (res[i] * 8) % 10;
            break;
        }
    }
}


//Output
void Solve()
{
    int n;
    Prep();
    while(scanf("%d", &n) && n)
    {
        printf("%d\n", res[n]);
    }
}



//Main Procedure
int main()
{
    FileInit();
    Solve();
    return 0;
}
