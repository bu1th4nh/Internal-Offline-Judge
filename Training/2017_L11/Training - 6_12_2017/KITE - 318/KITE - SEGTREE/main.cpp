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
#define task "KITE"
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
class SegmentTree
{
private:

    vector<int> ST;

public:
    SegmentTree(int __n)
    {
        ST = vector<int> (4 * __n + 16, 0);
    }
    SegmentTree() {}
    ~SegmentTree() {}


    void update(int id, int l_bound, int r_bound, int pos)
    {
        if(pos < l_bound || pos > r_bound) return;

        ST[id]++;

        if(l_bound == r_bound) return;


        int mid = (l_bound + r_bound) / 2;

        update(id*2, l_bound, mid, pos);
        update(id*2+1, mid+1, r_bound, pos);

        ST[id] = ST[id*2] + ST[id*2+1];
    }
    int query(int id, int l_bound, int r_bound, int l_query, int r_query)
    {
        if(r_query <  l_bound || l_query >  r_bound) return 0;
        if(l_query <= l_bound && r_query >= r_bound) return ST[id];

        int mid = (l_bound + r_bound) / 2;
        return (query(id * 2, l_bound, mid, l_query, r_query)   +    query(id * 2 + 1, mid + 1, r_bound, l_query, r_query));
    }
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
int a[131072], b[131072], comp[131072], res[131072];
int n;



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

	FOR(i, 1, n) scanf("%d", &a[i]), b[i] = a[i];
}

//Compress
void Compress()
{
    sort(b+1, b+n+1);
    FOR(i, 1, n)
    {
        comp[i] = lower_bound(b+1, b+n+1, a[i]) - b;
    }
}

//Process
void Solve()
{
    Compress();

    SegmentTree st(n+1);

    FOR(i, 1, n)
    {
        res[i] = st.query(1, 1, n, comp[i] + 1, n) + 1;
        st.update(1, 1, n, comp[i]);
    }

    FOR(i, 1, n) cout << res[i] << "\n";
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
6
78
24
68
40
39
89
 */


