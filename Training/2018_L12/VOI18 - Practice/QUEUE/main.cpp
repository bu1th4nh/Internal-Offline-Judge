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
#define task "QUEUE"
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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int m, n, res, nTest;
vb avail;
vi a, b;


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
	a = b = vi(n+1, 0);
	avail = vb(m+1, 1);
	res = 0;

    FOR(i, 1, n)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
}

//Check
void backtrack(int i)
{
    FOR(j, a[i], b[i])
    {
        if(avail[j])
        {
            avail[j] = 0;
            backtrack(i+1);
            avail[j] = 1;
            res = max(res, i);
        }
    }
}
void sub1()
{
    backtrack(1);
    cout << res << el;
}

//Process
bool check(int res)     //Check if can first (res) car can park into.
{
    vii p(res);
    priority_queue<int, vi, greater<int>> pq;

    //cerr << "Check: " << res << el;

    FOR(i, 1, res)
    {
        p[i-1].fi = a[i];
        p[i-1].se = b[i];
    }
    sort(whole(p));


    auto ptr = p.begin();
    FOR(i, 1, m)
    {
        while(ptr != p.end() && ptr->fi <= i)
        {
            if(ptr->se >= i) pq.push(ptr->se);
            ptr++;
        }
        while(!pq.empty() && pq.top() < i) pq.pop();
        if(!pq.empty())
        {
            if(res <= 1) return 1;
            --res;
            pq.pop();
        }
    }

    return (res <= 0);
}

//Output
void Solve()
{
    int RES = 0;
    int l = 1, r = n, mid = 0;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(check(mid))
        {
            RES = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << RES << el;
}

//Main Procedure
int main()
{
    FileInit();

    scanf("%d", &nTest);
    while(nTest--)
    {
        Enter();

//        if(n <= 15) sub1();
//        else cout << n;

        Solve();
    }
    return 0;
}
