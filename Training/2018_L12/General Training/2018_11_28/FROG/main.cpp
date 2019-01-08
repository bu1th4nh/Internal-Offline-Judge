/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Solution Briefing - Foreword



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
#endif // __cplusplus

using namespace std;

// #define DEBUG
// #define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "FROG"
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
template<class T> inline void read(T &ret)
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
const long long inf = 12345678987654LL;


//=====================================
//Typedefs
struct Node
{
    int trace;
    long long val;

    Node(): val(0LL), trace(0) {}
    Node(long long __v, int __i): val(__v), trace(__i) {}

    Node operator+ (const Node &oth)
    {
        return (this->val > oth.val) ? *this : oth;
    }
};
struct SegmentTree
{
    #define lc id*2
    #define rc id*2+1

    typedef vector<long long> vll;
    typedef vector<Node> vn;
    vn ST;

    void build(int id, int l, int r, const vll &a)
    {
        if(l > r) return;
        if(l == r)
        {
            ST[id] = Node(a[l], l);
            return;
        }

        int mid = (l + r) / 2;
        build(lc, l, mid, a);
        build(rc, mid+1, r, a);
        ST[id] = ST[lc] + ST[rc];
    }
    Node query(int id, int l, int r, int ql, int qr)
    {
        if(qr <  l || r <  ql) return Node(-inf, -inf);
        if(ql <= l && r <= qr) return ST[id];

        int mid = (l + r) / 2;
        return query(lc, l, mid, ql, qr) + query(rc, mid+1, r, ql, qr);
    }

    SegmentTree(int __n)
    {
        ST = vn(__n * 4 + 64, Node());
    }
};



//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
vvi trace, a;
int m, n, k;
vvll dp;
vi res;

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
    read(m);
    read(n);
    read(k);

    a = trace = vvi(m+1, vi(n+1, 0));
    dp = vvll(m+1, vll(n+1, 0LL));

    FOR(i, 1, m) FOR(j, 1, n) read(a[i][j]);
}

//Process
void Solve()
{
    FOR(i, 1, n) dp[1][i] = a[1][i] * 1LL;
    FOR(i, 2, m)
    {
        deque<int> q;

        FOR(j, 1, n)
        {
            while(!q.empty() && dp[i-1][j] >= dp[i-1][q.back()]) q.pop_back();
            q.push_back(j);
            if(j - q.front() > k) q.pop_front();

            if(dp[i][j] < dp[i-1][q.front()])
            {
                dp[i][j] = dp[i-1][q.front()];
                trace[i][j] = q.front();
            }
        }

        q.clear();
        FORb(j, n, 1)
        {
            while(!q.empty() && dp[i-1][j] >= dp[i-1][q.back()]) q.pop_back();
            q.push_back(j);
            if(q.front() - j > k) q.pop_front();

            if(dp[i][j] < dp[i-1][q.front()])
            {
                dp[i][j] = dp[i-1][q.front()];
                trace[i][j] = q.front();
            }
        }

        FOR(j, 1, n) dp[i][j] += a[i][j];


//        cerr << el;
//        FOR(j, 1, n) cerr << dp[i][j] << sp;
//        getchar();
    }

//    FOR(i, 1, m)
//    {
//        FOR(j, 1, n) cerr << dp[i][j] << sp;
//        cerr << el;
//    }



    int idx = max_element(whole_1(dp[m])) - dp[m].begin();
    print(dp[m][idx]); putchar(el);

    while(idx != 0)
    {
        res.push_back(idx);
        idx = trace[m--][idx];
    }
    reverse(whole(res));

    for(int x: res)
    {
        print(x);
        putchar(el);
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

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
