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
#define task "BATLE"
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
vi a, c, b, res;
int n, k;


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
    scanf("%d%d", &n, &k);
    a = b = c = res = vi(n+1, 0);
    FOR(i, 1, n) scanf("%d", &a[i]);
}

//Process
void Solve()
{
    FenwickTree ft(n+1);

    FOR(i, 1, n)
    {
        c[i] = i - ft.get(a[i]);
        ft.update(a[i]);
    }

    FOR(i, 1, n)
    {
        if(c[i] > k)
        {
            c[i] -= k;
            res[i - k] = a[i];
            b[a[i]] = -1;
        }
        else
        {
            c[i] = 0;
        }
    }




    int ptr = 1;
    FOR(i, 1, n)
    {
        if(res[i] == 0)
        {
            while(b[ptr] < 0) ++ptr;
            res[i] = ptr++;
        }
    }

    FOR(i, 1, n) printf("%d ", res[i]);


//    puts(" ");
//    puts(" "); cout << "C: "; FOR(i, 1, n) cerr << b[i] << " "; puts(" ");
//    puts(" "); cout << "B: "; FOR(i, 1, n) cerr << c[i] << " "; puts(" ");
//    puts(" "); cout << "R: "; FOR(i, 1, n) cerr << res[i] << " "; puts(" ");

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
