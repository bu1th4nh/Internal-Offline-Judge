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
#define task "DANCE"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}


//=====================================
//Segment Tree
struct SegmentTree
{
    #define lc(x) x*2
    #define rc(x) x*2 + 1
    typedef vector<int> vi;

    struct Node
    {
        int res, len, left, right;
        int first, last;

        ~Node() {}
        Node() {}
        Node(int __res, int __len, int __l, int __r, int __fi, int __la): res(__res), len(__len), left(__l), right(__r), first(__fi), last(__la) {}

        Node operator + (const Node &b) const
        {
            Node ret;

            ret.last  = b.last;
            ret.first = first;
            ret.len   = len + b.len;
            ret.left  = (last != b.first && len == left) ? left + b.left : left;
            ret.right = (last != b.first && b.len == b.right) ? right + b.right : b.right;
            ret.res   = max(max(res, b.res) , max(ret.left, ret.right));

            if(last != b.first) ret.res = max(ret.res, right + b.left);

            return ret;
        }
    };

    vector<Node> ST;


    void build(int id, int l, int r)
    {
        if(l == r)
        {
            ST[id] = Node(1, 1, 1, 1, 1, 1);
            return;
        }

        int mid = (l + r) / 2;

        build(id*2, l, mid);
        build(id*2+1, mid+1, r);

        ST[id] = ST[id*2] + ST[id*2+1];
    }
    void update(int id, int l, int r, int pos)
    {
        if(pos < l || r < pos) return;
        if(l == r)
        {
            ST[id] = (ST[id].first == 1) ? Node(1, 1, 1, 1, 0, 0) : Node(1, 1, 1, 1, 1, 1);
            return;
        }

        int mid = (l + r) / 2;

        update(lc(id), l, mid, pos);
        update(rc(id), mid+1, r, pos);

        ST[id] = ST[lc(id)] + ST[rc(id)];
    }
    int query()
    {
        return ST[1].res;
    }

    SegmentTree(int __n) {ST = vector<Node>(4*__n + 16);}

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
int n, q, x;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    FILEOP();

    scanf("%d%d", &n, &q);

    SegmentTree st(n+1);
    st.build(1, 1, n);

    while(q--)
    {
        scanf("%d", &x);
        st.update(1, 1, n, x);
        printf("%d\n", st.query());
    }

    return 0;
}
