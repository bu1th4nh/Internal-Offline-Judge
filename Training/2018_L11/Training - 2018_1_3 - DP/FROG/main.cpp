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
#define task "FROG"
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
struct SegmentTree
{
    typedef long long ll;
    typedef vector<ll> vi;

    #define lc id*2
    #define rc id*2+1

    vi ST;

    void build(int id, int l, int r, const vi &a)
    {
        if(l > r) return;
        if(l == r)
        {
            ST[id] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(lc, l, mid, a);
        build(rc, mid+1, r, a);

        ST[id] = max(ST[lc], ST[rc]);
    }
    void update(int id, int l, int r, int pos, ll value)
    {
        if(pos < l || r < pos) return;
        ST[id] = max(ST[id], value);

        if(l == r) return;

        int mid = (l + r) / 2;

        update(lc, l, mid, pos, value);
        update(rc, mid+1, r, pos, value);

        ST[id] = max(ST[lc], ST[rc]);
    }
    ll query(int id, int l, int r, int ql, int qr)
    {
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return ST[id];

        int mid = (l + r) / 2;
        return max(query(lc, l, mid, ql, qr), query(rc, mid+1, r, ql, qr));
    }



    SegmentTree(int __n)
    {
        ST = vi(4*(__n+1) + 16, 0LL);
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
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int m, n, k;
vvi c, F;
vi res2;
ll res1;

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
	scanf("%d%d%d", &m, &n, &k);
	F = c = vvi(m+2, vi(n+2, 0LL));

	FOR(i, 1, m)
	{
	    FOR(j, 1, n)
	    {
	        scanf("%lld", &c[i][j]);
	    }
	}
}


//Process
void Solve()
{
    FOR(i, 1, n) F[1][i] = c[1][i];

    SegmentTree st(n+1);
    st.build(1, 1, n, F[1]);

    FOR(i, 2, m)
    {
        FOR(j, 1, n)
        {
            F[i][j] = c[i][j] + st.query(1, 1, n, max(1, j - k), min(n, j + k));
        }
        st.build(1, 1, n, F[i]);
    }

    res1 = 0LL;
    int pos = 0;
    FOR(i, 1, n)
    {
        if(F[m][i] > res1) pos = i, res1 = F[m][i];
    }

    printf("%lld\n", res1);

    res1 -= c[m][pos];
    res2.push_back(pos);
    FORb(i, m-1, 1)
    {
        FORb(j, n, 1)
        {
            if(F[i][j] == res1 && (abs(pos - j) <= k))
            {
                pos = j;
                break;
            }
        }
        res2.push_back(pos);
        res1 -= c[i][pos];
    }

    reverse(whole(res2));

    for(auto x: res2) cout << x << '\n';


    cerr << "I'm bu1th4nh\n";
    cerr << "I'm bu1th4nh\n";
    cerr << "I'm bu1th4nh\n";
}


//Main Procedure
int main()
{
    FileDebug();
    Enter();
    Solve();
    FileClose();
    return 0;
}
