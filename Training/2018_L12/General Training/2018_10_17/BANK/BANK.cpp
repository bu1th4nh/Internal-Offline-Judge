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
#define task "BANK"
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
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, q;
vi ps, a;

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
inline ll readInt()
{
    ll ret = 0LL;
    bool neg = 0;
    char c = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    return neg ? -ret : ret;
}
void writeLL(ll x)
{
    if(x < 0)
    {
        putchar('-');
        x = ~x + 1;
    }

    if(x > 9) writeLL(x / 10);
    putchar(x % 10 + '0');
}

//Enter
void Enter()
{
    n = readInt();
    q = readInt();

    a = vi(n+1, 0);
    ps = vi(n+4, 0);

    FOR(i, 1, n) a[i] = readInt();

    sort(whole(a));
    FOR(i, 1, n) ps[i] = ps[i-1] + a[i];

//    FOR(i, 1, n) cerr << a[i] << sp; cerr << el;
//    FOR(i, 1, n) cerr << ps[i] << sp; cerr << el;
}

//Process
#define what_is(x) cerr << #x << " is " << x << endl;
void Solve()
{
    FOR(i, 1, q)
    {
        ll p = readInt();

        int ptr = lower_bound(ps.begin()+1, ps.end(), p) - ps.begin();

        if(ptr > n)
        {
            cout << n << sp << a[1] << el;
            continue;
        }
        if(p == ps[ptr])
        {
            cout << ptr << sp << a[1] << el;
            continue;
        }

        --ptr;
        ll res1 = ptr, res2 = a[1];

        int l = ptr, r = n, mid = 0;
        while(l <= r)
        {
            mid = (l + r) >> 1;

//            what_is(mid);
//            what_is(mid-ptr);
//            what_is(ps[mid]-ps[mid-ptr]);

            if(ps[mid] - ps[mid-ptr] <= p)
            {
                res2 = a[mid-ptr+1];
                l = mid + 1;
            }
            else r = mid - 1;



        }


        cout << res1 << sp << res2 << el;
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
