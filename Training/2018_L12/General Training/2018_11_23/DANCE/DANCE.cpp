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


//#define DEBUG
#define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "DANCE"
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
struct Node
{
    int longest, sz;            //lm = LeftMost
    int lm_sz, rm_sz;           //rm = RightMost
    int lm_char, rm_char;

    Node() {longest = lm_sz = rm_sz = sz = 1; lm_char = rm_char = 0;}

    void flip()
    {
        lm_char = 1 - lm_char;
        rm_char = 1 - rm_char;
    }
    Node operator+ (const Node &oth)
    {
        int center_sz = 0;
        Node cur = *this;
        Node ret;

        ret.sz = cur.sz + oth.sz;
        ret.lm_char = cur.lm_char;
        ret.rm_char = oth.rm_char;

        if(cur.rm_char != oth.lm_char)
        {
            center_sz = cur.rm_sz + oth.lm_sz;
            ret.rm_sz = (oth.rm_sz == oth.sz) ? cur.rm_sz + oth.sz : oth.rm_sz;
            ret.lm_sz = (cur.lm_sz == cur.sz) ? cur.sz + oth.lm_sz : cur.lm_sz;
        }
        else
        {
            ret.rm_sz = oth.rm_sz;
            ret.lm_sz = cur.lm_sz;
        }

        maximize(ret.longest, center_sz);
        maximize(ret.longest, max(cur.lm_sz  , cur.rm_sz));
        maximize(ret.longest, max(oth.lm_sz  , oth.rm_sz));
        maximize(ret.longest, max(ret.lm_sz  , ret.rm_sz));
        maximize(ret.longest, max(cur.longest, oth.longest));

        return ret;
    }
};
struct SegmentTree
{
    #define lc id*2
    #define rc id*2+1

    int n;
    vector<Node> ST;

    void build(int id, int l, int r)
    {
        if(l > r) return;
        if(l == r)
        {
            ST[id] = Node();
            return;
        }

        int mid = (l + r) / 2;
        build(lc, l, mid);
        build(rc, mid+1, r);
        ST[id] = ST[lc] + ST[rc];
    }
    void update(int id, int l, int r, int pos)
    {
        //#define DEBUG
        #ifdef DEBUG
            fprintf(stderr, "Node %d manage from %d to %d\n", id, l, r);
        #endif // DEBUG

        if(pos < l || r < pos) return;
        if(l == r && l == pos)
        {
            ST[id].flip();
            return;
        }

        int mid = (l + r) / 2;
        update(lc, l,   mid, pos);
        update(rc, mid+1, r, pos);
        ST[id] = ST[lc] + ST[rc];

        #ifdef DEBUG

            fprintf(stderr, "Node %d manage from %d to %d ===> ", id, l, r);
            cerr << "LMC, RMC, LMS, RMS, LONGEST, SZ = " << ST[id].lm_char << sp << ST[id].rm_char << sp
            << ST[id].lm_sz << sp << ST[id].rm_sz << sp << ST[id].longest << sp << ST[id].sz << el;

        #endif // DEBUG


    }
    Node queryUtil(int id, int l, int r, int ql, int qr)
    {
        if(qr <  l || r <  ql) return Node();
        if(ql <= l && r <= qr) return ST[id];

        int mid = (l + r) / 2;
        return queryUtil(lc, l, mid, ql, qr) + queryUtil(rc, mid+1, r, ql, qr);
    }

    int query()
    {
        Node ret = queryUtil(1, 1, n, 1, n);
        return ret.longest;
    }

    ~SegmentTree() {}

    SegmentTree() {}
    SegmentTree(int __n)
    {
        n = __n;
        ST = vector<Node>(4*__n+160);
    }
};

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
int n, x, nQuery;

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

//Main Procedure
int main()
{
    FileDebug();
    scanf("%d%d", &n, &nQuery);
    SegmentTree st(n);

    #ifdef DEBUG
    string t(n, '0');
    #endif // DEBUG

    st.build(1, 1, n);
    while(nQuery--)
    {
        scanf("%d", &x);

        #ifdef DEBUG
        t[x-1] = (t[x-1] == '1') ? '0' : '1';
        cerr << "Query: " << t << el;
        #endif // DEBUG


        st.update(1, 1, n, x);

        #ifdef DEBUG
        cerr << "Result: " << st.query() << el;
        #endif // DEBUG

        cout << st.query() << el;
    }
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
