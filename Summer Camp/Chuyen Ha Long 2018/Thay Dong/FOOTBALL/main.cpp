/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*      ---------------Solution Briefing
    Case 1: n-th vertex won 1st vertex ===> n - v1 - v2 - .... - v(n-1)
    Case 2: n-1-th vertex won n-th vertex ===> v1 - v2 - .... - v(n-1) - v(n)
    Case 3: There was exist a k-th vertex in the set that lose n-th vertex
            ====> v1 - v2 - .. - v(k) - v(n) - v(k+1) - ... - v(n-1)
*/


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
#define task "FOOTBALL"
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
struct data
{
    int l_link, r_link, id;

    void modify(int x, int y)
    {
        l_link = x;
        r_link = x;
    }

    data(int __i, int __l, int __r): id(__i), l_link(__l), r_link(__r) {}
    data(int __i): id(__i), l_link(-1), r_link(-1) {}
    data() {}
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<data> vd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, k;
vvi c;

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

//Enter
void Enter()
{
    n = ReadInt();
    k = ReadInt();

    c = vvi(n+1, vi(n+1, 0));

    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            c[i][j] = ReadInt();
        }
    }
}


//Process
void Query(int l, int r)
{
    int first = l, last = l, ptr = 0;

    vd link_list(n+1);

    FOR(i, 1, n) link_list[i] = data(i, -1, -1);
    FOR(i, l, r)
    {
        if(c[i][first])
        {
            //Connect i-th vertex to the left of the first vertex
            link_list[i].l_link = -1,
            link_list[i].r_link = first,
            link_list[first].l_link = i,
            first = i;
        }
        else if(c[last][i])
        {
            //Connect i-th vertex to the right of the last vertex
            link_list[i].l_link = last,
            link_list[i].r_link = -1,
            link_list[last].r_link = i,
            last = i;
        }
        else
        {
            //Iterate the list.
            ptr = first;
            while(ptr != last)
            {
                int nxt = link_list[ptr].r_link;

                if(nxt != -1 && c[ptr][i] && c[i][nxt])
                {
                    link_list[i].l_link = ptr,
                    link_list[i].r_link = nxt,
                    link_list[ptr].r_link = i,
                    link_list[nxt].l_link = i;
                    break;
                }

                ptr = nxt;
            }
        }


    }

    WriteInt(r - l + 1);
    putchar(' ');


    ptr = first;
    while(ptr > 0)
    {
        WriteInt(ptr);
        putchar(' ');
        ptr = link_list[ptr].r_link;
    }

    putchar('\n');
}


//Output
void Solve()
{
    int l, r;
    FOR(iTest, 1, k)
    {
        l = ReadInt();
        r = ReadInt();
        Query(l, r);
    }
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
