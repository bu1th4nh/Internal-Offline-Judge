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
#define task "KITE"
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
//Fenwick Tree
struct FenwickTree
{
    typedef vector<int> vi;

    int n;
    vi T;

    void update(int x)
    {
        while(x <= n)
        {
            T[x]++;
            x += x & (-x);
        }
    }
    int query(int x)
    {
        int ret = 0;
        if(x == 0) return 0;
        while(x > 0)
        {
            ret += T[x];
            x -= x & (-x);
        }
        return ret;
    }

    ~FenwickTree() {}
    FenwickTree(int __n) {n = __n; T = vi(n + 15);}
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
vi a, sorted, comp, res;
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

    a = comp = sorted = vi(n+1);
	FOR(i, 1, n) scanf("%d", &a[i]), sorted[i] = -a[i];
}

//Compress
void Compress()
{
    sorted[0] = -1234567890;
    sort(sorted.begin(), sorted.end());

    FOR(i, 1, n)
    {
        comp[i] = lower_bound(whole(sorted), -a[i]) - sorted.begin();
    }
}

//Process
void Solve()
{
    Compress();
    FenwickTree t(n);

    FOR(i, 1, n)
    {
        res.push_back(t.query(comp[i]-1));
        t.update(comp[i]);
    }

    for(int i: res) printf("%d\n", i+1);

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
