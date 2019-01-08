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
#define task "LANDS"
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


const int inf = 1234567890;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, x, y, z, na, nb;
vi a, b;

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

//Fast I/O
inline int ReadInt()
{
    char t;
    for(t = getchar(); t < '0' || t > '9'; t = getchar());
    int ret = t - '0';
    for(t = getchar(); t >= '0' || t <= '9'; t = getchar()) ret = ret*10 + t - '0';
    return ret;
}
void WriteInt(ll x)
{
    if(x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

//Enter
void Enter()
{
    scanf("%d%d%d%d", &n, &x, &y, &z);

    int u, v;
    a = b = vi(1, 0);
    FOR(i, 1, n)
    {
        scanf("%d%d", &u, &v);
        FOR(j, 1, u) a.push_back(i);
        FOR(j, 1, v) b.push_back(i);
    }

    na = a.size() - 1;
    nb = b.size() - 1;
}


//Process
void Solve()
{
    vvi F = vvi(na+1, vi(nb+1, inf));

    FOR(i, 1, na) F[i][0] = 1LL*i*y;
    FOR(i, 1, nb) F[0][i] = 1LL*i*x;
    F[0][0] = 0;

    FOR(i, 1, na)
    {
        FOR(j, 1, nb)
        {
            F[i][j] = min(min(F[i][j], F[i-1][j-1] + z*abs(a[i] - b[j])), min(F[i-1][j] + y, F[i][j-1] + x));
        }
    }

    cout << F[na][nb];

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
