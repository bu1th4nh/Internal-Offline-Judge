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

//#define bu1th4nh

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
int nQuery, n, l, r;
vvi bitRepr, pos;
vi a;

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

//Fast I/O
inline int readInt()
{
    char c = 0;
    int ret = 0;
    bool neg = 0;

    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; c >= '0' && c <= '9'; c = getchar()) ret = ret * 10 + c - 48;
    return (neg) ? -ret : ret;
}


//Enter
void Enter()
{
    //scanf("%d%d", &n, &nQuery);
    n = readInt();
    nQuery = readInt();

    a = vi(n+1, 0);
    pos = vvi(n+1);
    bitRepr = vvi(n+1, vi(33, 0));

    FOR(i, 1, n)
    {
        a[i] = readInt();
        pos[a[i]].pb(i);
    }
}

//Check
bool getBit(int n, int k)       //Get the k-th bit of n
{
    return ((n >> k) & 1);
}
void Preps()
{
    FOR(i, 1, n)
    {
        FOR(j, 0, 20)
        {
            bitRepr[i][j] += bitRepr[i-1][j] + getBit(a[i], j);
        }
    }

    #ifdef bu1th4nh
    FOR(i, 0, 4)
    {
        cerr << "Bit repr: ";
        FOR(j, 1, n) cerr << bitRepr[j][i] << sp;
        cerr << el;
    }
    #endif // bu1th4nh
}



//Process
void Query()
{
    int res = 0, tmp = 0;
    //scanf("%d%d", &l, &r);

    l = readInt();
    r = readInt();
    FOR(j, 0, 20)
    {
        tmp = bitRepr[r][j] - bitRepr[l-1][j];
        if(2 * tmp > r - l + 1) res |= (1 << j);
        else if(2 * tmp == r - l + 1)
        {
            puts("0");
            return;
        }
    }

    tmp = upper_bound(whole(pos[res]), r) - lower_bound(whole(pos[res]), l);

    if(2 * tmp > r - l + 1) printf("%d\n", res);
    else puts("0");
}


//Output
void Solve()
{
    Preps();
    FOR(i, 1, nQuery) Query();
}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
