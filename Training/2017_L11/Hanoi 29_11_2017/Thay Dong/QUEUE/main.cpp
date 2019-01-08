/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
//=====================================
//Solution
/*
Tìm trung vị cuả dãy x[1] <= ... <= x[n]
sao cho tổng |X - x[i]| min.
với X là trung vị của x.
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
vi d, x, y;
ll res;
int n;

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
	scanf("%d", &n);

    x = y = vi(n+1);
    x[0] = -1234567890;
    y[0] = -1234567890;

	FOR(i, 1, n)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
    sort(whole(x));
    sort(whole(y));
}

//Check
int GetMedian(int l, int r)
{
    return l + (r - l + 1) / 2;
}

//Process
ll Attempt(int r, int c)
{
    int nTime = 0, i = 1, mid = GetMedian(1, n);
    int r_x = 0, r_y = 0;
    vi X(n+1), Y(n+1);

    X[0] = Y[0] = -1234467890;

    nTime = 0, i = 1;
    while(i <= n)
    {
        FOR(j, i, i+r-1) X[j] = x[j] - nTime;
        i += r, ++nTime;
    }

    nTime = 0, i = 1;
    while(i <= n)
    {
        FOR(j, i, i+c-1) Y[j] = y[j]  - nTime;
        i += c, ++nTime;
    }

    sort(whole(X));
    sort(whole(Y));

    nTime = 0, i = 1;
    while(i <= n)
    {
        FOR(j, i, i+r-1) r_x += abs(X[mid] + nTime - x[j]);
        i += r, ++nTime;
    }

    nTime = 0, i = 1;
    while(i <= n)
    {
        FOR(j, i, i+c-1) r_y += abs(Y[mid] + nTime - y[j]);
        i += c, ++nTime;
    }

    return (r_x + r_y);
}



void Solve()
{
    res = 1e18;

    FOR(i, 1, trunc(sqrt(n)) + 1)
    {
        if(n % i == 0 && i < n)
        {
            res = min(res, Attempt(i, n/i));
            res = min(res, Attempt(n/i, i));
        }
    }

    cout << res;
}



//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    FileClose();
    return 0;
}
