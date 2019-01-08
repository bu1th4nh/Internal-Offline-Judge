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
#define task "BSTBUILD"
#define l first
#define r second
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
typedef unsigned long long ull;
typedef pair<int, int> NODE;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef long long ll;
const int inf = 1000000007;
int a[300009], h[300009];
NODE link[300009];
int n;
ll c;

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
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Enter
void Enter()
{
    c = 0;
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        scanf("%d", &a[i]);
    }
}


//Process
void Solve()
{
    int u, v;

    FOR(i, 1, n)
    {
        link[i] = NODE(i-1, i+1);
    }

    FORb(i, n, 1)
    {
        if(link[a[i]].l > 0) link[link[a[i]].l].r = link[a[i]].r;
        if(link[a[i]].r < n+1) link[link[a[i]].r].l = link[a[i]].l;
    }
    c = 0;

    FOR(i, 1, n)
    {
        u = link[a[i]].l, v = link[a[i]].r;

        //cerr << u << " " << v << "\n";

        if( u < 1 and v > n) h[a[i]] = 0;
        else if(u < 1)
        {
            h[a[i]] = h[v] + 1, c += h[a[i]];
        }
        else if(v > n)
        {
            h[a[i]] = h[u] + 1, c += h[a[i]];
        }
        else if(u >= 1 && v <= n)
        {
            h[a[i]] = max(h[u], h[v]) + 1, c += h[a[i]];
        }

        cout << c << "\n";
    }
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
