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
using namespace std;


//=====================================
//Macros
#define task "ORDER"
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
//SegTree
struct SegmentTree
{
    #define lc id*2
    #define rc id*2+1
    #define lm mid
    #define rm mid+1

    struct Node
    {
        int a, b;
        bool ok;

        Node() {}
        Node(int __x): a(__x), b(__x), ok(true) {}
        Node(int __x, int __y): a(__x), b(__x), ok(false) {}

        ~Node() {}
    };

    typedef vector<Node> vn;
    typedef vector<int> vi;

    vn ST;


    void update(int id, int l, int r, int pos, int val)
    {
        if(l > r || pos < l || pos > r) return;
        if(l == r && l == pos)
        {
            ST[id] = Node(val);
            return;
        }

        int mid = (l + r) >> 1;
        update(lc, l, lm, pos, val);
        update(rc, rm, r, pos, val);


        ST[id].a = max(ST[lc].a, ST[rc].a);
        ST[id].b = min(ST[lc].b, ST[rc].b);
        ST[id].ok = false;

        if(ST[lc].a <= ST[rc].b && ST[lc].ok && ST[rc].ok) ST[id].ok = true;


    }
    bool extract()
    {
        return ST[1].ok;
    }



    SegmentTree() {}
    SegmentTree(int __n)
    {
        ST = vn((__n + 1) * 4 + 16);
    }


    ~SegmentTree() {}

};


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
SegmentTree st;
int n, k;
vi a;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
	scanf("%d%d", &n, &k);
	st = SegmentTree(n);
	a = vi(n+1);

	FOR(i, 1, n)
	{
        scanf("%d", &a[i]);
        st.update(1, 1, n, i, a[i]);
	}
}

//Check
void Solve()
{
    int u, v;
    //st.build(1, 1, n, a);

    while(k--)
    {
        char t;
        scanf("\n%s", &t);

        if(t == '!')
        {
            scanf("%d%d\n", &u, &v);
            a[u] = v;
            st.update(1, 1, n, u, a[u]);
        }
        else
        {
            cout << ((st.extract()) ? "YES\n" : "NO\n");
        }
    }
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
