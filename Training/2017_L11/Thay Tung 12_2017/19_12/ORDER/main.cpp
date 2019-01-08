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
#define task "ORDER"
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


//Check
void Query1(ll p, ll q)
{
    if(p == 1 && q == 1) {printf("1\n"); return;}
    if(p == 1) {printf("%lld\n", 1LL << (q-1)); return;}
    if(q == 1) {printf("%lld\n", (1LL << p) - 1); return;}



    string cmd;
    while(p != q)
    {
        if(p > q)
        {
            cmd.push_back('R');
            p -= q;
        }
        else
        {
            cmd.push_back('L');
            q -= p;
        }
    }

    ll pos = 1LL;
    reverse(whole(cmd));
    for(char k: cmd)
    {
        pos = (k == 'L') ? (pos << 1LL) : ((pos << 1LL) | 1);
    }

    printf("%lld\n", pos);
}
void Query2(ll n)
{
    string cmd;
    while(n != 1LL)
    {
        if(n & 1LL)
        {
            n >>= 1LL;
            cmd.push_back('R');
        }
        else
        {
            n >>= 1LL;
            cmd.push_back('L');
        }
    }

    reverse(whole(cmd));

    ll p = 1LL, q = 1LL;
    for(char t: cmd)
    {
        if(t == 'L') q += p;
        else p += q;
    }


    printf("%lld %lld\n", p, q);
}

//Process
void Solve()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int type;
        scanf("%d", &type);
        if(type == 1)
        {
            ll p, q;
            scanf("%lld%lld", &p, &q);
            Query1(p, q);
        }
        else
        {
            ll n;
            scanf("%lld", &n);
            Query2(n);
        }
    }
}


//Main Procedure
int main()
{
    FileInit();
    Solve();
    FileClose();
    return 0;
}
