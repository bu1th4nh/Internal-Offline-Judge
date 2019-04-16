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

//#define DEBUG
#define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "BLUEHOUSE"
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
    template<class T, class R> T max(const T &__X, const R &__Y)
    {
        return __X > __Y ? __X : __Y;
    }
    template<class T, class R> T min(const T &__X, const R &__Y)
    {
        return __X < __Y ? __X : __Y;
    }
    template<class T, class R> void maximize(T &__X, R __Y)
    {
        __X = __X > __Y ? __X : __Y;
    }
    template<class T, class R> void minimize(T &__X, R __Y)
    {
        __X = __X < __Y ? __X : __Y;
    }
    template<class T> int getBit(T &__X, int __i)
    {
        return ((__X >> __i) & 1) == 1;
    }
    template<class T> bool inRange(T __L, T __R, T __X)
    {
        return __L <= __X && __X <= __R;
    }
    template<class T> T __abs(T __X)
    {
        return (__X < 0) ? -__X : __X;
    }
    template<class T> T __sqr(T __X)
    {
        return __X * __X;
    }
#endif
//Fast I/O
template<class T> inline void scan(T &__ret)
{
    __ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) __ret = __ret * 10 + c - '0';
    __ret = (neg) ? -__ret : __ret;
}
template<class T> void print(T __X)
{
    if(__X < 0)
    {
        putchar('-');
        __X *= -1;
    }

    if(__X > 9) print(__X / 10);
    putchar(__X % 10 + '0');
}

//=====================================
//Constants



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
typedef stack<ii> sii;
vi num, low, deg, idx, leaves, re_index, rev_index;
int n, m, timeStamp, nBiconnected;
vvi adj, BCC;
vb isBCCed;
sii st;

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
    int u, v;
    scan(n);
    scan(m);

    timeStamp = nBiconnected = 0;
    num = low = deg = vi(n+1, 0);
    rev_index = vi(n+1, -1);
    isBCCed = vb(n+1, 0);
    idx = vi(n+1, -1);
    adj = vvi(n+1);

    set<ii> edgeList;

    FOR(i, 1, m)
    {
        scan(u);
        scan(v);
        edgeList.insert(ii(min(u, v), max(u, v)));
    }

    for(ii x: edgeList)
    {
        adj[x.fi].pb(x.se);
        adj[x.se].pb(x.fi);
    }
}

//Check
void DFS(int u, int p)
{
    num[u] = low[u] = ++timeStamp;
    for(int v: adj[u]) if(v != p)
    {
        st.push(ii(u, v));
        if(num[v]) minimize(low[u], num[v]);
        else
        {
            DFS(v, u);
            minimize(low[u], low[v]);

            if(low[v] >= num[u])
            {
                vi bcc;
                while(1)
                {
                    ii e = st.top(); st.pop();
                    if(e == ii(u, v)) break;

                    if(idx[e.fi] == -1) idx[e.fi] = nBiconnected, bcc.push_back(e.fi);
                    if(idx[e.se] == -1) idx[e.se] = nBiconnected, bcc.push_back(e.se);

                    isBCCed[e.fi] = isBCCed[e.se] = 1;
                }
                if(bcc.size() != 0)
                {
                    ++nBiconnected;
                    BCC.push_back(bcc);
                }
            }
        }
    }
}
void getBiconnectedComp()
{
    DFS(1, 0);

//    cerr << "Nr of BCCs: " << nBiconnected << el;
//    int iiii = 0;
//    for(auto x: BCC)
//    {
//        cerr << ++iiii <<": ";
//        for(auto y: x) cerr << y << sp;
//        cerr << el;
//    }

    FOR(i, 1, n) ++idx[i];
    FOR(i, 1, n) if(idx[i] && rev_index[idx[i]] == -1)
    {
        rev_index[idx[i]] = i;
    }

    FOR(i, 1, n) if(!idx[i])
    {
        idx[i] = ++nBiconnected;
        rev_index[nBiconnected] = i;
    }

//    cerr << "Index: "; FOR(i, 1, n) cerr << idx[i] << sp; cerr << el;
//    cerr << "RevIndex: "; FOR(i, 1, n) cerr << rev_index[i] << sp; cerr << el;

}

//Process
void Solve()
{
    getBiconnectedComp();
    set<ii> edgeList;
    FOR(u, 1, n)
    {
        for(int v: adj[u]) if(idx[v] != idx[u])
        {
            edgeList.insert(ii(min(idx[u], idx[v]), max(idx[u], idx[v])));
        }
    }

//    cerr << "Edges:\n";
//    for(ii x: edgeList) cerr << x.fi << sp << x.se << el;


    for(ii x: edgeList) ++deg[x.fi], ++deg[x.se];
    FOR(i, 1, nBiconnected) if(rev_index[i] != -1 && deg[i] == 1)
    {
        leaves.push_back(rev_index[i]);
    }



//    cerr << "Nr. of leaves and leaves ID: " << leaves.size() << sp << "{ ";
//    for(int x: leaves) cerr << x << sp; cerr << " }" << el;

    if(leaves.size()&1)
    {
        print(((int)leaves.size() + 1) >> 1); putchar(el);

        if(leaves.size() != 1) leaves.push_back(leaves[0]);
        if(leaves.size() == 1) FOR(i, 1, n) if(leaves.back() != i) {leaves.push_back(i); break;}
    }
    else print((int)leaves.size() >> 1), putchar(el);

    for(int i = 0; i < (int)leaves.size(); i += 2)
    {
        print(leaves[i]);
        putchar(sp);
        print(leaves[i+1]);
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

/*
6 7
1 2
1 3
3 2
2 4
4 5
4 6
5 6




16 18
1 2
2 3
4 2
3 5
5 4
5 6
6 7
6 8
8 9
9 10
11 10
12 9
12 11
10 13
14 10
8 15
15 16
16 12
*/

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
