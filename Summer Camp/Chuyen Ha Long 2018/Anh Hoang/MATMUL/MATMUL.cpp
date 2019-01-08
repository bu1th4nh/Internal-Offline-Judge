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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vvi A, B, C;
int n;


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


//Fast IO
inline int ReadInt()
{
    char b;
    for (b = getchar(); b < '0' || b > '9'; b = getchar());
    int res = b - '0';
    for (b = getchar(); b >= '0' && b <= '9'; b = getchar())
        res = res * 10 + b - '0';
    return res;
}
void WriteInt(ll x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}
void testing()
{
    int cnt = 0;
    ll a = 0, a2 = 0;
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            a = 0;
            FOR(k, 1, n)
            {
                a += A[i][k] * B[k][j];

                ++cnt;

                if(cnt >= 10000000)
                {
                    puts("YES");
                    return;
                }
            }
            if(a != C[i][j] && a2 != C[i][j])
            {
                puts("NO");
                return;
            }
        }
    }

    puts("YES");
}

//Main Procedure
int main()
{
    int T = ReadInt();
    while(T--)
    {
        n = ReadInt();
        A = B = C = vvi(n+1, vi(n+1, 0));

        FOR(i, 1, n) FOR(j, 1, n) A[i][j] = ReadInt();
        FOR(i, 1, n) FOR(j, 1, n) B[i][j] = ReadInt();
        FOR(i, 1, n) FOR(j, 1, n) C[i][j] = ReadInt();

        testing();

    }
    return 0;
}
