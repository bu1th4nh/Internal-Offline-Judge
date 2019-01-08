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
#define task "LIQUORS"
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
template<class T> inline void read(T &ret)
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
const int inf = 1000000007;


//=====================================
//Typedefs
struct data
{
    int pr_id, se_id;
    int primary, secondary;

    data() {}
    data(int pid, int sid, const vector<int> &a)
    {
        pr_id = pid;
        se_id = sid;
        primary   = a[pid];
        secondary = a[sid];
    }

    bool operator< (const data &other) const
    {
        int d1 = (this->secondary - this->primary);
        int d2 = (other.secondary - other.primary);

        int s1 = (this->primary + this->secondary);
        int s2 = (other.primary + other.secondary);

        bool equalz = make_tuple(this->primary, this->secondary, this->pr_id, this->se_id) < make_tuple(other.primary, other.secondary, other.pr_id, other.se_id);

        return (d1 > d2) || (d1 == d2 && s1 < s2) || (d1 == d2 && s1 == s2 && equalz);
    }
};
struct Node
{
    int l_link, r_link, id;

    ~Node() {}

    Node():id(0), l_link(0), r_link(0) {}
    Node(int __id, int l, int r): id(__id), l_link(l), r_link(r) {}
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<Node> vn;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef multiset<data> sd;
vi jerry, tom, a;
vector<Node> pool;
sd st;
int n;


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
    scanf("%d", &n);

    a = vi(2*n+1, 0);
    pool = vn(2*n+2, Node());

    FOR(i, 1, 2*n) read(a[i]);
}

//Check
void Preps()
{
    sort(whole_1(a));

    pool[0]     = Node(0, 0, 1);
    pool[2*n+1] = Node(n+1, 2*n, 2*n+1);

    FORl(i, 1, 2*n)
    {
        st.insert(data(i, i+1, a));
    }
    FOR(i, 1, 2*n) pool[i] = Node(i, i-1, i+1);
}


//Process
void Solve()
{
    FOR(i, 1, n)
    {
        data d = *st.rbegin();
        tom.push_back(d.primary);
        jerry.push_back(d.secondary);

        //Delete from the set
        st.erase(d);
        if(pool[d.pr_id].l_link != 0)
        {
            st.erase(data(pool[d.pr_id].l_link, d.pr_id, a));
        }
        if(pool[d.se_id].r_link != 2*n+1)
        {
            st.erase(data(d.se_id, pool[d.se_id].r_link, a));
        }

        //Delete from the master list
        pool[pool[d.pr_id].l_link].r_link = pool[d.se_id].r_link;
        pool[pool[d.se_id].r_link].l_link = pool[d.pr_id].l_link;

        //Insert new element
        if(pool[d.pr_id].l_link != 0 && pool[d.se_id].r_link != 2*n+1) st.insert(data(pool[d.pr_id].l_link, pool[d.se_id].r_link, a));
    }


    for(auto x: jerry)  {print(x); putchar(sp);}
    putchar(el);
    for(auto x: tom)  {print(x); putchar(sp);}
    putchar(el);
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

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
