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
#endif // __cplusplus

using namespace std;

// #define DEBUG
// #define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "STRCMP"
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
typedef long long ll;
typedef unsigned long long ull;
typedef map<char, int> mci;
typedef pair<char, int> ci;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ci> vci;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<mci> vmci;
int m, k, n;
string src;

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
    scan(m);
    scan(k);

    char str[65536];
    scanf("%s", &str);
    src = string(str);
    n = src.size();
}

//Subtask 1
void sub1(string pat)
{
    int sz = pat.size();
    int diff = 0;
    FORl(i, 0, n)
    {
        diff += int(src[i] != pat[i % sz]);
    }
    cout << diff;
}

//Subtask 2
void sub2(string pat)
{
    int sz = pat.size(), diff = n, res = n;
    vmci pochinki(sz);
    vci optimal(sz);

    FORl(i, 0, sz)
    {
        for(int j = i; j < n; j += sz)
        {
            ++pochinki[i][src[j]];
        }

        for(auto x: pochinki[i]) if(optimal[i].se < x.se) optimal[i] = x;
    }

    //#define DEBUG
    //-------------------------------------------------------------------
    #ifdef DEBUG
    FORl(i, 0, sz)
    {
        for(auto x: pochinki[i]) cerr << x.fi << "-" << x.se << sp;
        cerr << el;
    }
    cerr << el;

    cerr << "Optimal value:\n";
    FORl(i, 0, sz) cerr << optimal[i].fi << sp << optimal[i].se << el;
    #endif // DEBUG
    //-------------------------------------------------------------------


    FORl(i, 0, sz) diff -= pochinki[i][pat[i]];     //We don't change pat[i]
    res = diff;

    FORl(i, 0, sz)
    {
        int tmp = diff - optimal[i].se + pochinki[i][pat[i]]; //We try changing pat[i]
        res = min(res, tmp);
    }

    print(res); putchar(el);
}

//Subtask 3
bool cmp(ii x, ii y)
{
    return x.second > y.second;
}
void sub3(string pat)
{
    int sz = pat.size(), diff = n, kp = k, res = n;
    vmci pochinki(sz);
    vci optimal(sz);
    vci pool;
    vi id;

    FORl(i, 0, sz)
    {
        for(int j = i; j < n; j += sz)
        {
            ++pochinki[i][src[j]];
        }

        for(auto x: pochinki[i]) if(optimal[i].se < x.se) optimal[i] = x;

        if(optimal[i].first != pat[i])
        {
            pool.push_back(optimal[i]);
            id.push_back(i);
        }
        else diff -= optimal[i].se;
    }

    sort(whole(pool));

    FORl(i, 0, pool.size())
    {
        if(kp)
        {
            --kp;
            diff -= pool[i].se;
        }
        else diff -= pochinki[id[i]][pat[id[i]]];
    }


    print(diff); putchar(el);
}

//Output
void Solve()
{
    char str[256];
    FOR(i, 1, m)
    {
        scanf("%s", &str);
        if(k == 0) sub1(string(str));
        else if(k == 1) sub2(string(str));
        else sub3(string(str));
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

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
