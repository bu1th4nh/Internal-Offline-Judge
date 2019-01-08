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
#define task "LEVELS"
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
ii a[1110101];
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
inline int ReadInt()
{
    char b;
    for (b = getchar(); b < '0' || b > '9'; b = getchar());
    int res = b - '0';
    for (b = getchar(); b >= '0' && b <= '9'; b = getchar())
        res = res * 10 + b - '0';
    return res;
}
void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}


//Main Procedure
int main()
{
    FileInit();

//    scanf("%d", &n);
//    ifstream fi(task".inp");
//    ofstream fo(task".out");
//    fi >> n;

    n = ReadInt();


    int u, p;


    m = 1 << n;

    vi res(m+1, 0);

    FOR(i, 1, m) a[i] = ii(ReadInt(), i);



//    FOR(i, 1, m) scanf("%d", &u), a[i] = ii(u, i);
//    FOR(i, 1, m) fi >> (u), a[i] = ii(u, i);


    sort(a+1, a+m+1);
    FORb(i, m, 1)
    {
        if(i < m and a[i].fi == a[i+1].fi) res[a[i].second] = res[a[i+1].second];
        else
        {
            FORb(j, n-1, 0) if((i>>j)&1)
            {
                res[a[i].se] = n - j;
                break;
            }
        }
    }

//    FOR(i, 1, m) fo << res[i] << " ";
//    FOR(i, 1, m) cout << res[i] << " ";

    FOR(i, 1, m) WriteInt(res[i]), putchar(' ');

    FileClose();
    return 0;
}
