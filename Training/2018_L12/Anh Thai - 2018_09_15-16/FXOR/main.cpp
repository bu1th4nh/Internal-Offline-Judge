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
#include <cassert>
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
#define task "FXOR"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin()+1, x.end()
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
typedef vector<vvi> vvvi;
typedef vector<vii> vvii;
int nxt[131072][30][2];
int pre[131072][30][2];
int n, nQuery;
vi a;


//=====================================
//Functions and procedures
//Initialization and preparation
void LiveToday()
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

//Utilities
inline int readInt()
{
    char c = 0;
    int ret = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();

    if(c == '-')
    {
        neg = 1;
        c= getchar();
    }
    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + int(c - '0');

    return (neg) ? -ret : ret;
}
void WriteInt(int x)
{
    if(x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int getBit(int x, int i)
{
    return ((x >> i) & 1);
}

//Enter
void LoveTomorrow()
{
    n = readInt();

    a = vi(n+1, 0);

    FOR(i, 1, n) //scanf("%d", &a[i]);
    {
        a[i] = readInt();
    }

    nQuery = readInt();
}

//Check
void S1()
{
    sort(whole(a));
    FOR(i, 1, nQuery)
    {
        int x, res = 0, res2 = 1;
        scanf("%d", &x);
        FOR(i, 1, n) if(res < (x ^ a[i]))
        {
            res = x ^ a[i];
            res2 = a[i];
        }

        cout << res2 << sp;
    }
}

//Process
void Preps()
{
    FOR(j, 0, 29)
    {
        nxt[n+1][j][0] = nxt[n+1][j][1] = n+1;
        pre[ 0 ][j][0] = pre[ 0 ][j][1] = 0;

        FORb(i, n, 1)
        {
            nxt[i][j][0] = nxt[i+1][j][0];
            nxt[i][j][1] = nxt[i+1][j][1];
            nxt[i][j][(a[i] >> j) & 1] = i;
        }

        FOR(i, 1, n)
        {
            pre[i][j][0] = pre[i-1][j][0];
            pre[i][j][1] = pre[i-1][j][1];
            pre[i][j][(a[i] >> j) & 1] = i;
        }
    }
}
void findAnswer(int query)
{
    int L = 1, R = n, res = 0;
    int state, new_l, new_r;
    FORb(i, 29, 0)
    {
        state = 1 - getBit(query, i);
        new_l = nxt[L][i][state];
        new_r = pre[R][i][state];
        if(new_l <= new_r)
        {
            L = new_l;
            R = new_r;
        }
    }

    WriteInt(a[L]);
    putchar(' ');
}
void UniteForever()
{
    int x;
    sort(whole(a));

    Preps();
    FOR(i, 1, nQuery)
    {
        findAnswer(readInt());
    }
}


//Main Procedure
int main()
{
    LiveToday();
    LoveTomorrow();
    UniteForever();
    return 0;
}
