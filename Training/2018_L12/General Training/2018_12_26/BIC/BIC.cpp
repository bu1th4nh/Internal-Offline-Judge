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
#define task "BIC"
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
const long long mod = 1000000000;


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
typedef stack<int> si;
vi topoOrder, idOrder, comp, num, low;
int m, n, topoTime, dfsTime;
vll cntPath, res;
bool ok = 1;
vvi adj;
vb Free;
si st;

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

	adj = vvi(n+1);
	Free = vb(n+1, 1);
	cntPath = res = vll(n+1, 0LL);
	num = low = topoOrder = idOrder = vi(n+1, 0);
	topoTime = dfsTime = 0;

	FOR(i, 1, m)
	{
	    scan(u);
	    scan(v);
	    adj[u].pb(v);
	}
}

//Check
void DFS(int u)
{
    st.push(u);
    num[u] = low[u] = ++dfsTime;

    for(int v: adj[u]) if(Free[v])
    {
        if(num[v]) minimize(low[u], num[v]);
        else
        {
            DFS(v);
            minimize(low[u], low[v]);
        }
    }


    if(num[u] == low[u])
    {
        int cnt = 0, x = 0;
        do
        {
            x = st.top(); st.pop();
            Free[x] = 0;
            ++cnt;
        }
        while(x != u);

        if(cnt > 1) comp.push_back(u);
    }
}
void BFS()
{
    queue<int> q;
    for(int start: comp)  q.push(start), Free[start] = 0;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v: adj[u]) if(Free[v])
        {
            Free[v] = 0;
            q.push(v);
        }
    }
    ok = Free[2];
}
void topoDFS(int u)
{
    Free[u] = 0;
    for(int v: adj[u]) if(Free[v]) topoDFS(v);
    idOrder[topoTime--] = u;
}

//Process
void initBFS()
{
    Free = vb(n+1, 1);
    BFS();
}
void initTopo()
{
    Free = vb(n+1, 1);
    topoTime = dfsTime;
    topoDFS(1);
}
void topoDP()
{
    cntPath[1] = 1LL;
    FOR(i, 1, dfsTime)
    {
        int u = idOrder[i];
        for(int v: adj[u])
        {
            cntPath[v] = (cntPath[v] * 1LL + cntPath[u] * 1LL) % mod;
            maximize(res[v], max(res[u], (ll)(cntPath[u] + cntPath[v] >= mod)));
        }
    }
}

//Output
void Solve()
{
    DFS(1);
    if(!comp.empty())
    {
        initBFS();
        if(!ok) {printf("inf"); return;}
    }

    initTopo();
    topoDP();

    if(res[2] == 0) printf("%lld\n", cntPath[2]);
    else
    {
        string ress = to_string(cntPath[2]);
        while(ress.size() < 9) ress = '0' + ress;
        cout << ress << el;
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
1 3
1 4
3 2
4 2
5 6
6 5
3 4
*/

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
