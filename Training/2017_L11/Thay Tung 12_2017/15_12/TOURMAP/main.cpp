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
#define task "TOURMAP"
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
//Main Procedure
int main()
{
    FILEOP();
    int n, m;
    scanf("%d%d", &n, &m);

    if(n == m)
    {
        cout << "Possible\n";

        cerr << "Circular!";

        cout << 1 << " " << n << "\n";
        FORl(i, 1, n) cout << i << " " << i+1 << "\n";
        return 0;
    }

    if(n*(n-1)/2 == m)
    {
        cout << "Possible\n";

        cerr << "Complete!";

        FORl(i, 1, n)
        {
            FOR(j, i+1, n) cout << i << " " << j << "\n";
        }
        return 0;
    }

    if(n % 2 == 0 && (n / 2) * (n / 2) == m)
    {
        cout << "Possible\n";

        cerr << "Bipartite!";

        FOR(i, 1, n/2)
        {
            FOR(j, n/2+1, n) cout << i << " " << j << "\n";
        }
        return 0;
    }

    cout << "Impossible\n";

    return 0;
}
