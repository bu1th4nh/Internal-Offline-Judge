/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
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

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#endif // __cplusplus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task "PERFECT"
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
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Typedefs
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ordered_set> vos;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;

//vector<ordered_set> vs;

int n, k, root;
vvi adj;
vos vs;
vi par;
ll res;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    FILEOP_DEBUG()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
template<class T> inline void scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret *= neg ? -1 : 1;
}
template<class T> void print(T x)
{
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}



//Enter
void Enter()
{
    int u, v;

    res = 0LL;
    scan(n); scan(k);
    par = vi(n+1, -1);
    adj = vvi(n+1);

    FORl(i, 1, n)
    {
        scan(u), scan(v);
        adj[u].pb(v);
        par[v] = u;
    }

    FOR(i, 1, n) if(par[i] == -1)
    {
        root = i;
        break;
    }
}

//Check
void DFS_ST12(int u, int start)
{
    for(int v: adj[u])
    {
        res += (int)(abs(v - start) <= k);
        DFS_ST12(v, start);
    }
}
void Sub12()
{
    FOR(i, 1, n) DFS_ST12(i, i);
    print(res);
}


//Process
void DFS_ST3(int u)
{
    for(int v: adj[u])
    {
        DFS_ST3(v);
        for(auto x: vs[v]) vs[u].insert(x);
    }


    if(vs[u].size() > 0)
    {
        res += vs[u].order_of_key(u + k + 1) - vs[u].order_of_key(u - k);
    }

    vs[u].insert(u);
}
void Final()
{
    vs = vos(n+1);
    DFS_ST3(root);
    print(res);
}


//Output
void Solve()
{
    if(n * (n-1) / 2 <= 9000000) Sub12();
    else Final();

//    Final();
}




//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
