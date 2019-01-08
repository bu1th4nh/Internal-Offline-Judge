/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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
#include <vector>
#include <utility>
using namespace std;

//=====================================
//Macros
#define task "IS"
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



//=====================================
//Segment Tree
struct Node
{
    int trace;
    long long val;

    Node() {val = 0LL, trace = 0;}
    Node(long long __v, int __t)
    {
        val = __v, trace = __t;
    }

    Node operator + (const Node &other)
    {
        return (this->val > other.val) ? *this : other;
    }
};
struct SegmentTree
{
    vector<Node> ST;

    SegmentTree(int __n) {ST = vector<Node> (__n * 4 + 16, Node(0, 0)); }
    SegmentTree() {}
    ~SegmentTree() {}

    void update(int id, int l_bound, int r_bound, int pos, Node value)
    {
        if(pos < l_bound || pos > r_bound) return;

        ST[id] = ST[id] + value;

        if(l_bound == r_bound) return;

        int mid = (l_bound + r_bound) / 2;

        update(id*2, l_bound, mid, pos, value);
        update(id*2+1, mid+1, r_bound, pos, value);
    }

    Node query(int id, int l_bound, int r_bound, int l_query, int r_query)
    {
        if(r_query < l_bound ||  r_bound < l_query) return Node(0, 0);

        if(l_query <= l_bound && r_bound <= r_query) return ST[id];

        int mid = (l_bound + r_bound) / 2;

        return query(id*2, l_bound, mid, l_query, r_query) + query(id*2+1, mid+1, r_bound, l_query, r_query);
    }

};


//=====================================
//Typedef
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
int a[131072], weigh[131072], comp[131072], sorted[131072], trace[131072];
int n, n_res;
ll F[131072];
vi res;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
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

    FOR(i, 1, n) scanf("%d", &a[i]), sorted[i] = a[i];
    FOR(i, 1, n) scanf("%lld", &weigh[i]);

    sort(sorted+1, sorted+n+1);
    FOR(i, 1, n) comp[i] = lower_bound(sorted+1, sorted+n+1, a[i]) - sorted;
}

//Process
void Solve()
{
    SegmentTree st(n+1);
    FOR(i, 1, n)
    {
        Node t = st.query(1, 1, n, 1, comp[i]-1);
        F[i] = t.val + weigh[i];
        trace[i] = t.trace;
        st.update(1, 1, n, comp[i], Node(F[i], i));
    }

    int dst = max_element(F+1, F+n+1) - F;

    while(dst != 0)
    {
        res.push_back(dst);
        dst = trace[dst];
    }

    cout << res.size() << "\n"; reverse(whole(res));
    for(int i: res) printf("%d ", i);
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    FileClose();
    return 0;
}

/*
10
1 2 3 6 4 5 9 6 7 8
11 22 33 66 44 55 999 66 77 88
*/
