/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Solution Briefing - Foreword
/*
        Solution: Segment Tree, Prefix Sum
        Replace s --> v[i]: v[i] = 1 if s[i] = 'C', = -1 if(S[i] = 'T')

        For each query:
*/
//=====================================
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#include <chrono>
#endif // __cplusplus

using namespace std;

// #define DEBUG
// #define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "GENETECH"
#define maxinp ()
#define fi first
#define se second
#define pb push_back
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define r_whole(x) x.rbegin(),x.rend()
#define FOR(i, x, y) for(auto i=x; i<=y; ++i)
#define FORl(i, x, y) for(auto i=x; i<y; ++i)
#define FORb(i, x, y) for(auto i=x; i>=y; --i)
#define FORlb(i, x, y) for(auto i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP()                        \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
    freopen(task".err", "w", stderr);   \
}

//Macroes - Optional
#ifdef OPTIONAL_FEATURE
    #define pc(x) putchar(x)
    #define gc() getchar()
#endif



//=====================================
//Auxilary Functions and Fast I/O
#ifdef OPTIONAL_FEATURE
    template<class T, class R> T max(T &x, R &y)
    {
        return x > y ? x : y;
    }
    template<class T, class R> T min(T &x, R &y)
    {
        return x < y ? x : y;
    }
    template<class T, class R> void maximize(T &x, R y)
    {
        x = x > y ? x : y;
    }
    template<class T, class R> void minimize(T &x, R y)
    {
        x = x < y ? x : y;
    }
    template<class T> int getBit(T &x, int i)
    {
        return ((x >> i) & 1) == 1;
    }
    template<class T> T __abs(T &x)
    {
        return (x = (x < 0) ? -x : x);
    }
#endif
//Fast I/O
template<class T> inline void scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret = (neg) ? -ret : ret;

    #ifdef DEBUG
        cerr << "FastScan Diagnostic: " << ret << el;
    #endif
}
template<class T> void print(T x)
{
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

//=====================================
//Constants
const int inf = 1000000007;

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
int nQuery, n, p0;
vi st, res, v;
vvii query;
vii tree;
string t;


//=====================================
//Functions and procedures
//File I/O and utilities
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    #ifdef DEBUG
        FILEOP_DEBUG()
    #else
        FILEOP()
    #endif
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}


//Enter
void Enter()
{
    int u, x;
    char str[1010101];
    scanf("%d", &n);
    scanf("%s", &str);
    scanf("%d", &nQuery);
    t = ' ' + string(str);
    FORb(i, 20, 0) if((n >> i) & 1) {p0 = 1 << (i+1); break;}

    tree = vii(4*n+5, ii(0, n+1));
    res = vi(nQuery+1);
    query = vvii(n+1);
    v = vi(n+1, 0);

    FOR(i, 1, nQuery)
    {
        scanf("%d%d", &u, &x);
        query[u].pb(ii(x, i));
    }

    //FOR(i, 1, n) sort(whole(query[i]));
    FOR(i, 1, n) v[i] = (t[i] == 'C') ? 1 : -1;
}


//Segtree Operation
#define what_is(x) cerr << #x << " is " << x << endl;
#define lc p*2
#define rc p*2+1
void upd_tree(int x, int val)
{
    int p = p0 + x - 1;
    tree[p] = {val, val};
    while(p > 1)
    {
        p /= 2;
        tree[p].fi = tree[lc].fi + tree[rc].fi;
        tree[p].se = min(tree[lc].se + tree[rc].fi, tree[rc].se);
    }
}
int query_min(int x, int y)
{
    ii tx, ty, tm;
    x += p0 - 1;
    y += p0 - 1;
    tx = tree[x];
    ty = tree[y];
    if(x == y) return min(0, tx.se);
    while(y - x > 1)
    {
        tm = tx;
        if((x & 1) == 0)
        {
            tx.fi += tree[x+1].fi,
            tx.se = min(tm.se + tree[x+1].fi, tree[x+1].se);
        }
        tm = ty;
        if(y & 1)
        {
            ty.fi += tree[y-1].fi,
            ty.se = min(tree[y-1].se + tm.fi, tm.se);
        }
        x /= 2;
        y /= 2;
    }
    return min(0, min(tx.se + ty.fi, ty.se));
}

//Process
void Solve()
{
    FORb(i, n, 1)
    {
        if(v[i] == -1)
        {
            st.push_back(i);
            upd_tree(i, 0);
        }
        else
        {
            upd_tree(i, 1);
            if(!st.empty())
            {
                upd_tree(st.back(), -1);
                st.pop_back();
            }
        }

        for(auto x: query[i])
        {
            int l = i, r = x.fi;
            res[x.se] = upper_bound(r_whole(st), r) - st.rbegin() - query_min(l, r);
        }
    }
    FOR(i, 1, nQuery) cout << res[i] << el;
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}

/*
14
CTCTTTCCTTCTTT
5
3 12
1 14
3 8
2 9
3 11

*/
//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
