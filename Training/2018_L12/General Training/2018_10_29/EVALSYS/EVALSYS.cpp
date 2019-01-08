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
#define task "EVALSYS"
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
struct SegmentTree
{
    #define lc id*2
    #define rc id*2+1


    struct Node
    {
        int val, lazy;
        Node(): val(0), lazy(0) {}
        Node(int __v): val(__v), lazy(0) {}
        Node(int __v, int __l): val(__v), lazy(__l) {}
    };


    vector<Node> ST;

    //Lazy Propagation
    void push_down(int id)
    {
        int t = ST[id].lazy;

        ST[lc].lazy += t;
        ST[rc].lazy += t;
    }
    //Update and queries
    void update(int id, int l, int r, int up_l, int up_r, int v)
    {
        //This node needs to be updated
        if(ST[id].lazy)
        {
            ST[id].val += (r - l + 1) * ST[id].lazy;
            if(l != r)
            {
                push_down(id);
            }
            ST[id].lazy = 0;
        }
        //Out of range
        if(up_r <  l || r <  up_l) return;
        //Segment is fully within range
        if(up_l <= l && r <= up_r)
        {
            ST[id].val += (r - l + 1) * v;
            if(l != r)
            {
                ST[lc].lazy += v;
                ST[rc].lazy += v;
            }
            return;
        }


        //Update the child node
        int mid = (l + r) / 2;
        update(lc, l    , mid, up_l, up_r, v);
        update(rc, mid+1, r  , up_l, up_r, v);
        //Merge
        ST[id].val = (ST[lc].val + ST[rc].val);
    }
    int query(int id, int l, int r, int ql, int qr)
    {
        //Out of range
        if(qr <  l || r <  ql) return 0;
        //This node needs to be updated
        if(ST[id].lazy)
        {
            ST[id].val = (r - l + 1) * ST[id].lazy;
            if(l != r)
            {
                push_down(id);
            }
            ST[id].lazy = 0;
        }
        //Segment is fully within range
        if(ql <= l && r <= qr) return ST[id].val;

        int mid = (l + r) / 2;
        return ( query(lc, l, mid, ql, qr)  +  query(rc, mid+1, r, ql, qr) );
    }


    //Constructors and destructor
    SegmentTree() {}
    SegmentTree(int __n) {ST = vector<Node>(4*__n+16);}

    ~SegmentTree() {ST.clear();}

};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<SegmentTree> vst;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int nQuery, n;
vi minPrime;
vst mult;


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
//Utilities
template<class T> inline void scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret *= (neg) ? -1 : 1;
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
ll power(ll A, int B, ll M)         //Bonus
{
    ll ret = 1LL;
    if(B == 0) return 1LL % M;
    if(B == 1) return A % M;
    FORl(i, 0, 32)
    {
        if((B >> i) & 1 == 1) ret = (ret * A) % M;
        A = (A * A) % M;
    }

    return ret % M;
}
vii factorization(int n)
{
    vii ret;
    int lastPrime = 0, cnt = 0, p = 0;
    while(n != 1)
    {
        if(minPrime[n] != lastPrime && lastPrime != 0)
        {
            ret.push_back(ii(lastPrime, cnt));
            cnt = 0;
        }

        lastPrime = minPrime[n];
        n /= minPrime[n];
        ++cnt;
    }

    ret.push_back(ii(lastPrime, cnt));
    //for(auto x: ret) cerr << x.fi << sp << x.se << el;
    return ret;
}


//Enter
void Preps()
{
    minPrime = vi(128, 0);
    for(int i = 2; i*i <= 121; ++i) if(!minPrime[i])
    {
        for(int j = i*i; j <= 121; j += i) if(!minPrime[j]) minPrime[j] = i;
    }

    FOR(i, 2, 121) if(!minPrime[i]) minPrime[i] = i;
}
void Enter()
{
    scan(n);
    scan(nQuery);

    mult = vst(128, SegmentTree(n+5));
}

//Process
void Solve()
{
    int l, r, val, type, mod;
    while(nQuery--)
    {
        scan(type); scan(l); scan(r);

        // << type << sp << l << sp << r << el;

        if(type == 1)
        {
            scan(val); if(val == 1) continue;
            vii fact = factorization(val);
            for(auto x: fact) mult[x.fi].update(1, 1, n, l, r, x.se);//, cerr << "Updated from " << l << " to " << r << " w/ val " << x.fi << " by " << x.se << el;
        }
        if(type == 2)
        {
            scan(val); if(val == 1) continue;
            vii fact = factorization(val);
            for(auto x: fact) mult[x.fi].update(1, 1, n, l, r, -x.se);//, cerr << "Updated from " << l << " to " << r << " w/ val " << x.fi << " by " << -x.se << el;;
        }
        if(type == 0)
        {
            scan(mod);

            ll mul_res = 1LL;
            FOR(i, 1, 100)
            {
                mul_res = (mul_res * power(i*1LL, mult[i].query(1, 1, n, l, r), mod)) % mod;

                //if(mult[i].query(1, 1, n, l, r)) cerr << i << " ^ " << mult[i].query(1, 1, n, l, r) << " = " << power(i*1LL, mult[i].query(1, 1, n, l, r), mod) << " and curr. result: " << mul_res << el;
            }

            ll res = (mul_res) % mod;
            print(res); putchar('\n');
        }
    }
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Preps();
    Solve();
//    SegmentTree st(50);
//    st.update(1, 1, 50, 1, 10, 5);
//    st.update(1, 1, 50, 1, 5, 10);
//    cerr << st.query(1, 1, 50, 1, 10) << el;

    return 0;
}
