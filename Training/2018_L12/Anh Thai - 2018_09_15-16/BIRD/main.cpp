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
#define task "BIRD"
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
typedef pair<ll, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi a, nxt, pre;
vii vect;
ll res;
int n;

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
inline ll readInt()
{
    char c = 0;
    ll ret = 0LL;
    bool neg = 0;

    while(c != '-' && (!isdigit(c))) c = getchar();

    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10LL + int(c - '0');
    return (neg) ? -ret : ret;
}

//Enter
void Enter()
{
	scanf("%d", &n);

	a = nxt = pre = vi(n+2, 0LL);

	FOR(i, 1, n)
	{
	    a[i] = readInt();
	    vect.push_back(ii(a[i], i));
	    nxt[i] = i+1;
	    pre[i] = i-1;
	}
}

//Process
bool cmp(ii a, ii b)
{
    return (a.fi > b.fi || (a.fi == b.fi && a.se < b.se));
}
void Solve()
{
    stack<int> st;
    res = 0LL;
    FOR(i, 1, n)
    {
        while(!st.empty() && a[i] <= a[st.top()])
        {
            res += a[st.top()] + a[i];
            st.pop();
            res += a[st.top()];
        }
        st.push(i);
    }

    ll p;

    while(!st.empty())
    {
        res += a[st.top()];
        st.pop();
        if(!st.empty()) res += a[st.top()];
    }

    cout << res;
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
