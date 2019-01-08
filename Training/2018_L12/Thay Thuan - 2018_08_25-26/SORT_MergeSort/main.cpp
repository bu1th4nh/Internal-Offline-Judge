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
#define task ""
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
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vd a, tmp_a;
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
inline double readDouble()
{
    char c = 0;
    bool neg = 0;
    register double ret = 0.0, after_the_dot = 0.10;
    while((!isdigit(c)) && c != '-' && c != '.') c = getchar();

    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) == 1; c = getchar()) ret = ret * 10 + (c - '0');
    if(c == '.')
    {
        c = getchar();
        for(; isdigit(c) == 1; c = getchar())
        {
            ret += after_the_dot * (c - '0');
            after_the_dot /= 10;
        }
    }

    //cerr << fixed << setprecision(10) << ret << el;
    return (neg) ? -ret : ret;
}

//Enter
void Enter()
{
	scanf("%d", &n);
	a = tmp_a = vd(n+1);
	FOR(i, 1, n) a[i] = readDouble();
}

//Check
void merge(vd &a, int l, int mid, int r)
{
    if(l == r) return;

    int i = l;
    int j = mid + 1;

    FOR(ptr, l, r)
    {
        if(i > mid)
        {
            tmp_a[ptr] = a[j];
            ++j;
        }
        else if(j > r)
        {
            tmp_a[ptr] = a[i];
            ++i;
        }
        else
        {
            if(a[i] < a[j])
            {
                tmp_a[ptr] = a[i];
                ++i;
            }
            else
            {
                tmp_a[ptr] = a[j];
                ++j;
            }
        }
    }

    FOR(ptr, l, r) a[ptr] = tmp_a[ptr];
}
void merge_sort(vd &a, int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}

//Process
void Solve()
{
    merge_sort(a, 1, n);
    FOR(i, 1, n) printf("%.2lf ", a[i]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
