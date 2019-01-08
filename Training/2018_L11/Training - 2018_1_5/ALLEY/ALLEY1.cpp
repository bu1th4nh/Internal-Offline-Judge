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
using namespace std;


//=====================================
//Macros
#define task "ALLEY1"
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
//Disjoint Set
struct DisjointSet
{
    typedef vector<int> vi;
    vi lab;

    int find(int u)
    {
        return (lab[u] < 0) ? u : (lab[u] = find(lab[u]));
    }
    void unionSet(int r, int s)
    {
        if(lab[r] > lab[s]) swap(r, s);
        lab[r] += lab[s];
        lab[s] = r;
    }
    bool join(int u, int v)
    {
        int r = find(u);
        int s = find(v);

        if(r != s)
        {
            unionSet(r, s);
            return true;
        }
        else return false;
    }


    DisjointSet(int __n) {lab = vi(__n + 6, -1);}
    DisjointSet() {}


    ~DisjointSet() {}
};
struct Edge
{
    int u, v, d, id;

    bool operator < (const Edge &other) const
    {
        return (this->d < other.d);
    }


    Edge(int __u, int __v, int __d, int __id): u(__u), v(__v), d(__d), id(__id) {}
    Edge(): u(0), v(0), d(0), id(0) {}

    ~Edge() {}
};


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<Edge> ve;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ve EList, SpanTree, External;
int m, n, k, p;
vi res1, res2;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    int u, v, w;
	scanf("%d%d%d%d", &n, &k, &m, &p);
	FOR(i, 1, k)
	{
	    scanf("%d%d%d", &u, &v, &w);
	    EList.push_back(Edge(u, v, w, i));
	}
}

//Process
void Solve()
{
    sort(whole(EList));
    DisjointSet ds(n);
    FORl(i, 0, k)
    {
        if(ds.join(EList[i].u, EList[i].v))
        {
            SpanTree.push_back(EList[i]);
            m -= EList[i].d;
        }
        else External.push_back(EList[i]);
    }

    if(SpanTree.size() < n-1 || m < 0)
    {
        printf("Impossible\n");
        return;
    }

    sort(whole(SpanTree));
    for(Edge x: SpanTree)
    {
        if(x.d*(p-1) <= m)
        {
            res1.push_back(x.id);
            m -= x.d*(p-1);
        }
        else res2.push_back(x.id);
    }

    if(m > 0)
    {
        for(Edge x: External)
        {
            if(x.d*p <= m)
            {
                res1.push_back(x.id);
                m -= x.d*p;
            }
        }
    }

    cout << res2.size() << " " << res1.size() << '\n';
    for(int i: res2) cout << i << " "; puts("");
    for(int i: res1) cout << i << " "; puts("");
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
