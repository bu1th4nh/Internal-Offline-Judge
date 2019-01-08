/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*
            Analysis: Binary Search on Stack
*/
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
#define task "FARRAY"
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, res, sta, fin, top, cnt = 0;
vll ps;
vi st;
ll s;

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
	scanf("%d%lld", &n, &s);

	ps = vll(n+2, 0LL);
	res = n + 101010;
	sta = 0, fin = 0;

	FOR(i, 1, n) ps[i] = ps[i-1] + readInt();
}

//Process
inline void BinarySearch(int i)
{
    int l = 0, mid = 0, j = 0;
    int r = (int)st.size() - 1;

    while(l <= r)
    {
        mid = (l + r) / 2;
        j = st[mid];

        if(ps[i] - ps[j] >= s)
        {
            if(i - j < res)
            {
                ++cnt;
                fin = i;
                sta = st[mid] + 1;
                res = fin - sta + 1;
            }
            l = mid + 1;
        }
        else r = mid - 1;
    }
}
void Tomorrowland_Magic()
{
    FOR(i, 1, n)
    {
        while(!st.empty() && (ps[st.back()] >= ps[i-1])) st.pop_back();
        st.push_back(i-1);
        if(!st.empty()) BinarySearch(i);
    }

    if(!cnt)
    {
        puts("-1");
        return;
    }
    cout << res << el << sta << sp << fin << el;
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Tomorrowland_Magic();
    return 0;
}
