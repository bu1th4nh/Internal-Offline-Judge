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
#define task "SNOW_WH"
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
//Typedef
struct Node
{
    int a, b;
    Node operator + (const Node &other)
    {
        Node ret;
        ret.a = max(this->a, other.a);
        ret.b = min(this->b, other.b);
        return ret;
    }


    Node(int __a, int __b): a(__a), b(__b) {}
    Node(int __x): a(__x), b(__x) {}
    Node() {}

    ~Node() {}
};

struct SegmentTree
{
    #define lc id*2
    #define rc id*2+1
    #define lm mid
    #define rm mid+1

    typedef vector<Node> vn;
    typedef vector<int> vi;
    vn ST;

    void build(int id, int l, int r, vi &a)
    {
        if(l > r) return;
        if(l == r)
        {
            ST[id] = Node(a[l]);
            return;
        }

        int mid = (l + r) >> 1;

        build(lc, l, lm, a);
        build(rc, rm, r, a);

        ST[id] = ST[lc] + ST[rc];
    }
    void update(int id, int l, int r, int pos, int val)
    {
        if(l > r) return;

        if(l == r && l == pos)
        {
            ST[id] = Node(val);
            return;
        }

        if(l == r) return;

        int mid = (l + r) >> 1;

        if(pos < mid) update(lc, l, lm, pos, val);
        else update(rc, rm, r, pos, val);

        ST[id] = ST[lc] + ST[rc];
    }
    Node query(int id, int l, int r, int ql, int qr)
    {
        if(qr < l || r < ql) return Node(-1234567890, 1234567890);
        if(ql <= l && r <= qr) return ST[id];

        int mid = (l + r) >> 1;

        return query(lc, l, lm, ql, qr) + query(rc, rm, r, ql, qr);
    }


    SegmentTree(int __n)
    {
        ST = vn((__n + 1)*4 + 16);
    }
    SegmentTree() {}


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
vi Height, PosInIndex;
int n, nQuery;


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
	scanf("%d%d", &n, &nQuery);
	Height = PosInIndex = vi(n+1, 0);

	FOR(i, 1, n)
	{
	    scanf("%d", &Height[i]);
	    PosInIndex[Height[i]] = i;
	}
}

//Process
void Solve()
{
    int type, u, v;
    SegmentTree st(n);
    st.build(1, 1, n, PosInIndex);

    while(nQuery--)
    {
        scanf("%d%d%d", &type, &u, &v);
        if(type == 1)
        {
            int x = Height[u];
            int y = Height[v];
            st.update(1, 1, n, x, PosInIndex[y]);
            st.update(1, 1, n, y, PosInIndex[x]);
            swap(PosInIndex[x], PosInIndex[y]);
            swap(Height[u], Height[v]);
        }
        else
        {
            if(u < v) swap(u, v);
            Node ret = st.query(1, 1, n, v, u);


//            puts("===========================================");
//            FOR(i, 1, n) printf("%d ", Height[i]); puts("");
//            FOR(i, 1, n) printf("%d ", PosInIndex[i]); puts("");
//            cout << ret.a << " " << ret.b << "\n";
//            puts("===========================================");

            if(ret.a - ret.b == u - v) cout << "YES\n";
            else cout << "NO";
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
