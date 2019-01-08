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

const int base_mod = 1e9 + 7;
const int max_n = 1e6 + 5;
const int max_pow = 21;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ll F[max_n][max_pow];
static ll LP[max_n];
int n, r, tc;

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

//Get factorization table
void GetLP()
{
    FORl(i, 2, max_n)
    {
        if(!LP[i])
        {
            for(int j = i; j < max_n; j += i)
            {
                LP[j] = i;
            }
        }
    }
}

//Dynamic Programming
void PreProcess()
{
    FORl(i, 0, max_n) F[i][0] = 1;
    FORl(i, 1, max_pow) F[0][i] = 2;
    FORl(i, 1, max_n)
    {
        FORl(j, 1, max_pow)
        {
            F[i][j] = (F[i-1][j] + F[i][j-1]) % base_mod;
        }
    }
}

//Query
ll Query(int r, int n)
{
    ll res = 1;
    while(n != 1)
    {
        //
    }
}


//Output





//Main Procedure
int main()
{
    //Your code goes here
    return 0;
}
