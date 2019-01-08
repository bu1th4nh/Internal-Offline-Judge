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
#define task "COLLIDER"
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
typedef map<int, int> mii;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef stack<int> si;
int n, m, remain = 0;
vi vdt, fdt;
mii mp;
//si s;

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

//Main Procedure
int main()
{
    FileInit();
    int max_time = 0,  jv = 0;

    scanf("%d", &n);
    vdt = fdt = vi(n, 0);

    int s[262144], top = 0;


    FOR(i, 1, n)
    {
        int x, e;
        scanf("%d%d", &x, &e);
        if(e == 1) s[++top] = x;
        else if(top)
        {
            int des = (x - s[top] + 1) / 2;
            max_time = max(des, max_time);
            --top;  mp[des] += 2;
        }
    }


//    FOR(i, 1, n)
//    {
//        int x, e;
//        scanf("%d%d", &x, &e);
//        if(e == 1) s.push(x);
//        else if(!s.empty())
//        {
//            int des = (x - s.top() + 1) / 2;
//            if(max_time < des) max_time = des;
//            s.pop();  mp[des] += 2;
//        }
//    }


    for(auto &x: mp)
    {
        int y = x.second;
        vdt[jv] = x.first;
        if(jv == 0) fdt[0] += y;        //First Explosion
        else fdt[jv] = fdt[jv - 1] + y;
        jv++;
    }

    remain = n - fdt[jv - 1];

//    cerr << ("==================================\n");
//    for(int i: fdt) cerr << i << " "; puts("");
//    cerr << ("==================================\n");
//    for(int i: vdt) cerr << i << " "; puts("");
//    cerr << ("==================================\n");

    int ptr = 0;
    scanf("%d", &m);
    FOR(i, 1, m)
    {
        int x;
        scanf("%d", &x);
        if(x < vdt[0])
        {
            printf("%d\n", n);
        }
        else if(x >= vdt[jv - 1])
        {
            printf("%d\n", remain);
        }
        else
        {
            while(x > vdt[ptr]) ++ptr;

            int res = (x < vdt[ptr]) ? n - fdt[ptr - 1] : n - fdt[ptr];

            printf("%d\n", res);
        }
    }
    FileClose();

    return 0;
}
