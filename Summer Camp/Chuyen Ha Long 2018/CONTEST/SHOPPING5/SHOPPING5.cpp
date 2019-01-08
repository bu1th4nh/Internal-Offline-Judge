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
#define task "SHOPPING5"
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
//Sparse Table
struct SparseTable
{
    typedef vector<int> vi;
    typedef vector<vi> vvi;

    const int LOG_MAX = 20;
    bool type;  //0: min, 1: max
    int n;

    vi num_log;
    vvi ST;

    void buildTable(const vi &a)
    {
        num_log[1] = 0;
        FOR(i, 2, n) num_log[i] = num_log[i / 2] + 1;

        FOR(i, 0, num_log[n])
        {
            int cur = 1 << i;
            FOR(j, 1, n)
            {
                if(i == 0)
                {
                    ST[i][j] = a[j];
                    continue;
                }

                ST[i][j] = (type) ? max(ST[i-1][j], ST[i-1][j + cur / 2]) : min(ST[i-1][j], ST[i-1][j + cur / 2]);
            }
        }
    }
    int getMax(int l, int r)
    {
        int cur = num_log[r - l + 1];
        return max(ST[cur][l], ST[cur][r - (1 << cur) + 1]);
    }
    int getMin(int l, int r)
    {
        int cur = num_log[r - l + 1];
        return min(ST[cur][l], ST[cur][r - (1 << cur) + 1]);
    }


    ~SparseTable() {}

    SparseTable() {}
    SparseTable(int __n, bool __type, const vi &inpp)
    {
        n = __n;
        type = __type;

        int initialValue = 0;

        //initialValue = (type) ? -2000000000 : 2000000000;

        num_log = vi(LOG_MAX+3, 0);
        ST = vvi(LOG_MAX+3, vi(n+3, initialValue));

        buildTable(inpp);
    }




    void debug()
    {
        FOR(i, 0, LOG_MAX)
        {
            FOR(j, 1, n) cerr << ST[i][j] << sp;
            cerr << el;
        }
    }

};


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
bool check12;
int n, m;
vi a;


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

//Fast I/O
inline int readInt()
{
    char c = 0;
    int ret = 0;
    bool neg = 0;

    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; c >= '0' && c <= '9'; c = getchar()) ret = ret * 10 + c - 48;
    return (neg) ? -ret : ret;
}


//Enter
void Enter()
{
    n = readInt();
    m = readInt();

    a = vi(n+1, 0);


    check12 = 1;
    FOR(i, 1, n) a[i] = readInt();
    FOR(i, 1, n)
    {
        if(a[i] != 1 && a[i] != 2)
        {
            check12 = 0;
            break;
        }
    }
}

//Check
void Subtask1()         //N <= 5k
{
    ll res = 0LL, tmp = 0LL;



    SparseTable max_st(n, 1, a);
    SparseTable min_st(n, 0, a);

    FOR(i, 1, n)
    {
        FOR(j, i, n)
        {
            tmp = 1LL * (max_st.getMax(i, j) + min_st.getMin(i, j));
            if(tmp <= 1LL * m) ++res;

            //cerr << i << sp << j << sp << (max_st.getMax(i, j)) << sp << (min_st.getMin(i, j)) << sp << tmp << el;

        }
    }


    printf("%lld\n", res);
}
void Subtask2()         //a[i] = 1 or 2.
{
    ll res = 0LL;

    if(m >= 4)
    {
        res = 1LL * n * (n + 1) / 2;
        printf("%lld\n", res);
        return;
    }

    if(m == 2)
    {
        a.push_back(0);

        ll n1 = 0LL;
        int n1_l = 0;
        FOR(i, 1, n)
        {
            if(a[i] == 1 && a[i] != a[i-1]) n1_l = i;
            if(a[i] == 1 && a[i] != a[i+1])
            {
                n1   = i - n1_l + 1;
                res += 1LL * n1 * (n1 + 1) / 2;
            }
        }

        printf("%lld\n", res);
        return;
    }

    if(m == 3)
    {
        a.push_back(0);

        int n2_l = 0;
        ll n2 = 0LL, excl = 0LL;

        FOR(i, 1, n)
        {
            if(a[i] == 2 && a[i] != a[i-1]) n2_l = i;
            if(a[i] == 2 && a[i] != a[i+1])
            {
                n2    = i - n2_l + 1;
                excl += 1LL * n2 * (n2 + 1) / 2;
            }
        }

        res = 1LL * n * (n + 1) / 2 - excl;

        printf("%lld\n", res);
        return;
    }
}

//Process
void Solve()
{
    if(m <= 1)
    {
        puts("0");
        return;
    }


    if(n <= 5000) Subtask1();
    else if(check12) Subtask2();
    else cout << 1LL * (n + 1) * n / 2;
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
