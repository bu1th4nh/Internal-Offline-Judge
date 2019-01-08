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
#define task "CHORDS"
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
//BIT
struct FenwickTree
{
    typedef pair<int, int> ii;
    typedef vector<int> vi;

    vi T;
    int n;

    void incr(int k)
    {
        while(k <= n)
        {
            ++T[k];
            k += k & (-k);
        }
    }
    void decr(int k)
    {
        while(k <= n)
        {
            --T[k];
            k += k & (-k);
        }
    }
    int get(int pos)
    {
        int ret = 0;
        while(pos > 0)
        {
            ret += T[pos];
            pos -= pos & (-pos);
        }
        return ret;
    }

    void create(int __n)
    {
        n = __n;
        T = vector<int>(__n + 4, 0);
    }
    void debug()
    {
        puts("");
        for(int x: T) cerr << x << " ";
        puts("");
    }


    FenwickTree(int __n)
    {
        n = __n;
        T = vector<int>(__n + 4, 0);
    }
    FenwickTree() {}

    ~FenwickTree() {}
};


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
FenwickTree B, C;
ll res;
vii a;
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
    int u, v;

    scanf("%d", &n);
    B.create(n*2);
    C.create(n*2);

    FOR(i, 1, n)
    {
        scanf("%d%d", &u, &v);
        if(u > v) swap(u, v);
        a.push_back(ii(u, v));

        B.incr(u);
        C.incr(v);
    }
}

//Process
void Solve()
{
    res = 0LL;
    sort(whole(a));

    for(ii x: a)
    {
        res += 1LL*(B.get(x.second) - C.get(x.second));
        B.decr(x.first);
        C.decr(x.second);
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

/*
3
1 5
4 2
6 3
 */
