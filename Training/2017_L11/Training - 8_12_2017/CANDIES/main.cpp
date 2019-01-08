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
#define task "CANDIES"
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
    vector<int> T;
    int n;

    void update(int k)
    {
        while(k <= n)
        {
            ++T[k];
            k += k & (-k);
        }
    }
    int get(int pos)
    {
        int ret = 0;
        if(pos == 0) return 0;
        while(pos > 0)
        {
            ret += T[pos];
            pos -= pos & (-pos);
        }
        return ret;
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
vi a, b, c, res;
int n, m;

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
    a = c = vi(n + 1); a[0] = INFINITY;
    FOR(i, 1, n) scanf("%d", &a[i]);

    scanf("%d", &m);
    b = res = vi(m + 1);
    FOR(i, 1, m) scanf("%d", &b[i]);
}

//Process
bool cmp(int __a, int __b)
{
    return __a > __b;
}
void Solve()
{
    int k, l, r, t, mid;

    FenwickTree ft(n+1);
    sort(whole(a), cmp);

    FOR(i, 1, m)
    {
        int x = a[1] - i + 1 + c[0];
        if(b[i] > x)
        {
            ++c[0], res[i] = 0;
        }
        else
        {
            l = 1, r = n, k = 0;
            while(l <= r)
            {
                mid = (l + r) / 2;
                t = a[mid] - (i - 1 - c[0] - ft.get(mid - 1));

                if(t >= b[i]) k = mid, l = mid + 1;
                else r = mid - 1;
            }


            ++c[k];
            ft.update(k);
            res[i] = k;
        }
    }

    FOR(i, 1, m) printf("%d\n", res[i]);

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
