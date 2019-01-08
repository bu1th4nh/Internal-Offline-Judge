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

using namespace std;


//=====================================
//Macroes
#define sp " "
#define el "\n"
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
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Typedefs
struct DisjointSet
{
    typedef vector<int> vi;
    vi lab, maxEdge;
    int n, t;

    int find(int u)
    {
        return (lab[u] < 0) ? u : (lab[u] = find(lab[u]));
    }
    void unify(int r, int s)
    {
        r = find(r);
        s = find(s);

        if(r == s || (-lab[r] >= t && -lab[s] >= t)) return;

        lab[r] += lab[s];
        lab[s] = r;
    }


    ~DisjointSet() {}

    DisjointSet() {}
    DisjointSet(int __n)
    {
        n = __n;
        lab = vi(n+1, -1);
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<iii> viii;
vvi height, id;
viii edgeList;
int n, m, t;
vii starts;
vb avail;


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

//Enter
void Enter()
{
    int u;
    scanf("%d%d%d", &n, &m, &t);
    height = vvi(n+1, vi(m+1, 0));
    id     = vvb(n+1, vi(m+1, 1));

    FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &height[i][j]);
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            scanf("%d", &u);
            if(u) starts.push_back(ii(i, j));
        }
    }
}

//Check





//Process




//Output





//Main Procedure
int main()
{
    //Your code goes here
    return 0;
}
