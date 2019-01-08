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
#define task "SORT"
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
//STs
struct SegmentTree
{
    #define lc id*2
    #define rc id*2+1

    struct Node
    {
        int val, lazy;
        Node(): val(0), lazy(-1) {}
        Node(int __v): val(__v), lazy(-1) {}
        Node(int __v, int __l): val(__v), lazy(__l) {}
    };


    vector<Node> ST;

    //Build
    void build(int id, int l, int r, const string &s, char c)
    {
        if(l > r) return;
        if(l == r)
        {
            if(s[l] == c)
            {
                ST[id] = Node(1);
                //cerr << "Increased " << c << " at pos " << l << " by 1" << el;
            }
            return;
        }

        int mid = (l + r) / 2;
        build(lc, l, mid, s, c);
        build(rc, mid+1, r, s, c);

        ST[id].val = ST[lc].val + ST[rc].val;
    }
    //Lazy Propagation
    void push_down(int id)
    {
        int t = ST[id].lazy;

        if(t != -1)
        {
            ST[lc].lazy = t;
            ST[lc].val  = t;

            ST[rc].lazy = t;
            ST[rc].val  = t;

            ST[id].lazy = -1;
        }
    }
    //Update and queries
    void update(int id, int l, int r, int up_l, int up_r, int v)
    {
        if(up_r <  l || r <  up_l) return;
        if(up_l <= l && r <= up_r)
        {
            ST[id].val  = v;
            ST[id].lazy = v;
            return;
        }

        int mid = (l + r) / 2;
        push_down(id);

        update(lc, l    , mid, up_l, up_r, v);
        update(rc, mid+1, r  , up_l, up_r, v);

        ST[id].val = ST[lc].val + ST[rc].val;
    }
    int query(int id, int l, int r, int ql, int qr)
    {
        if(qr <  l || r <  ql) return 0;
        if(ql <= l && r <= qr) return ST[id].val;

        int mid = (l + r) / 2;
        push_down(id);

        return ( query(lc, l, mid, ql, qr)  +  query(rc, mid+1, r, ql, qr) );
    }


    //Constructors and destructor
    SegmentTree() {}
    SegmentTree(int __n) {ST = vector<Node>(4*__n+16);}

    ~SegmentTree() {ST.clear();}

};

//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef vector<SegmentTree> VST;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
string s, res;
int n, nQuery;
VST tree;

//=====================================         lequangtuan6b@gmail.com
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
    char str[131072]; scanf("%s", &str); s = ' ' + string(str);
    scanf("%d", &nQuery);
    n = s.size();
}

//Check
bool cmp(char a, char b) {return a > b;}
void __testprog()
{
    int u, v, t;
    FOR(i, 1, nQuery)
    {
        scanf("%d%d%d", &t, &u, &v);
        if(t == 1) sort(s.begin()+u, s.begin()+v+1);
        else sort(s.begin()+u, s.begin()+v+1, cmp);
    }
    s.erase(0, 1);
    cout << s << el;
}
void __debugst()
{
    res.clear();
    FOR(i, 1, n)
    {
        FOR(j, 0, 25) if(tree[j].query(1, 1, n, i, i) > 0)
        {
            res += char(j + 'a');
            break;
        }
    }
    cerr << res << el;
}


//Process
void Answer(int type, int l, int r, int __query)
{
    int ptr;
    vi cnt(26, 0);

    FOR(i, 0, 25)
    {
        cnt[i] = tree[i].query(1, 1, n, l, r);
        tree[i].update(1, 1, n, l, r, 0);
    }

    ptr = l;
    if(type == 1) FOR(i, 0, 25)
    {
        tree[i].update(1, 1, n, ptr, ptr+cnt[i]-1, 1);
        ptr += cnt[i];
    }
    else FORb(i, 25, 0)
    {
        tree[i].update(1, 1, n, ptr, ptr+cnt[i]-1, 1);
        ptr += cnt[i];
    }
}
void Solve()
{
    int u, v, type;
    tree = VST(26, SegmentTree(n));

    FOR(i, 0, 25) tree[i].build(1, 1, n, s, char(i + 'a'));

    FOR(i, 1, nQuery)
    {
        scanf("%d%d%d", &type, &u, &v);
        Answer(type, u, v, i);
    }

    res.clear();
    FOR(i, 1, n)
    {
        FOR(j, 0, 25) if(tree[j].query(1, 1, n, i, i) > 0)
        {
            res += char(j + 'a');
            break;
        }
    }
    cout << res;
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
