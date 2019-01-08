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
#include <chrono>
#endif // __cplusplus

using namespace std;

// #define DEBUG
// #define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "TICKETS"
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
    freopen(task".out3", "w", stdout);   \
    freopen(task".err3", "w", stderr);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
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



//=====================================
//Typedefs

//--------------------
template<class T> struct SegmentTree
{
    #define lc id*2
    #define rc id*2+1


    struct Node
    {
        T val, lazy;
        Node(): val(T()), lazy(T()) {}
        Node(T __v): val(__v), lazy(0) {}
        Node(T __v, T __l): val(__v), lazy(__l) {}
    };


    vector<Node> ST;

    //Lazy Propagation
    void push_down(int id)
    {
        T t = ST[id].lazy;

        ST[lc].lazy += t;
        ST[lc].val += t;

        ST[rc].lazy += t;
        ST[rc].val += t;

        ST[id].lazy = 0;
    }
    //Update and queries
    void update(int id, int l, int r, int up_l, int up_r, T v)
    {
        if(up_r <  l || r <  up_l) return;
        if(up_l <= l && r <= up_r)
        {
            ST[id].val += v;
            ST[id].lazy += v;
            return;
        }

        int mid = (l + r) / 2;
        push_down(id);

        update(lc, l    , mid, up_l, up_r, v);
        update(rc, mid+1, r  , up_l, up_r, v);

        ST[id].val = min(ST[lc].val, ST[rc].val);
    }
    T query(int id, int l, int r, int ql, int qr)
    {
        if(qr <  l || r <  ql) return 1000000007;
        if(ql <= l && r <= qr) return ST[id].val;

        int mid = (l + r) / 2;
        push_down(id);

        return min( query(lc, l, mid, ql, qr)  ,  query(rc, mid+1, r, ql, qr) );
    }


    //Constructors and destructor
    SegmentTree() {}
    SegmentTree(int __n) {ST = vector<Node>(4*__n+16);}
    SegmentTree(int __n, T __START_VAL) {ST = vector<Node>(4*__n+16, __START_VAL);}

    ~SegmentTree
    () {ST.clear();}

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
int n, s, q;


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
    FileInit();
    long long x, y, k, val, dmy;
    scan(n);
    scan(s);
    scan(q);

    SegmentTree<long long>  st(n+1, s);


    while(q--)
    {
        scan(x);    ++x;
        scan(y);    ++y;
        scan(k);

        
        val = st.query(1, 1, n+1, x, y);


        cerr << val << el;
   
        if(val < k) puts("0");
        else
        {
            st.update(1, 1, n+1, x, y-1, -k); 
            puts("1");
        }
    }
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
