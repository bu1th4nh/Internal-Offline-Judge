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
#define task "RECT"
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
typedef stack<int> si;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi h, l, r;
int n, m;
ll res;
si st;

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

//Enter
void Enter()
{
	scanf("%d%d", &m, &n);
	h = vi(n+1, 0);
	FOR(i, 1, n) scanf("%d", &h[i]);
}

//Check
ll getArea()
{
    ll ret = 0;
    l = r = vi(n+1, 0);
    FOR(i, 1, n)
    {
        while((!st.empty()) && h[i] <= h[st.top()]) st.pop();
        l[i] = (st.empty()) ? 0 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    FORb(i, n, 1)
    {
        while((!st.empty()) && h[i] <= h[st.top()]) st.pop();
        r[i] = (st.empty()) ? n+1 : st.top();
        st.push(i);
    }

    FOR(i, 1, n) ret = max(ret, 1LL * h[i] * llabs(r[i] - l[i] - 1));
    return ret;
}

//Process
void Solve()
{
    res = getArea();
    FOR(i, 1, n) h[i] = m - h[i];
    res = max(res, getArea());
    cout << res << el;
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
