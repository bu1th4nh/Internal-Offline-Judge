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
#define task "CNTSEQ"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)(1048576)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin()+1, x.end()
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
typedef set<int> si;
int L[maxinp], R[maxinp], a[maxinp], value[maxinp];
int n, nQuery, nValues;
ll res[maxinp];
si pool;

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
    ret *= neg ? -1 : 1;
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


//Enter
void Enter()
{
	scan(n);
	nValues = 0;
    FOR(i, 1, n) scan(a[i]);
    FOR(i, 1, n) res[i] = 0LL;
}

//Check
void Preps()            //Prepare L[i] and R[i].
{
    int st[maxinp], tp = 0;
    a[0] = a[n+1] = 1048000000;

    FOR(i, 1, n)
    {
        if(a[i-1] >= a[i])
        {
            L[i] = i - 1;
            st[++tp] = i;
        }
        else
        {
            while(tp && a[st[tp]] < a[i]) --tp;
            L[i] = st[tp];
            st[++tp] = i;
        }
    }

    tp = 0;
    FORb(i, n, 1)
    {
        if(a[i+1] > a[i])
        {
            R[i] = i;
            st[++tp] = i;
        }
        else
        {
            while(tp && a[st[tp]] <= a[i]) --tp;
            ++tp;
            R[i] = R[st[tp]];
            st[tp] = i;
        }
    }
    FOR(i, 1, n) ++R[i];


//    FOR(i, 1, n) cerr << L[i] << sp; cerr << el;
//    FOR(i, 1, n) cerr << R[i] << sp; cerr << el;

    FOR(i, 1, n) value[i] = a[i];
    sort(value+1, value+n+1);

    nValues = 1;
    FOR(i, 2, n) if(value[i] != value[i-1]) value[++nValues] = value[i];


//    FOR(i, 1, nValues) cerr << res[i] << sp; cerr << el;

    int pos = 0;
    FOR(i, 1, n)
    {
        pos = lower_bound(value+1, value+nValues+1, a[i]) - value;
        res[pos] += 1LL * (R[i] - i) * (i - L[i]);
    }
    FOR(i, 1, nValues)  res[i] += res[i-1];
//    FOR(i, 1, nValues) cerr << res[i] << sp; cerr << el;

}
void Solve()
{
    int l, r, pl, pr;

    scan(nQuery);
    while(nQuery--)
    {
        scan(l); scan(r);
        pl = lower_bound(value+1, value+nValues+1, l) - value - 1;
        pr = upper_bound(value+1, value+nValues+1, r) - value - 1;
        print(ll(res[pr] - res[pl])); putchar('\n');
    }
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Preps();
    Solve();
    return 0;
}
