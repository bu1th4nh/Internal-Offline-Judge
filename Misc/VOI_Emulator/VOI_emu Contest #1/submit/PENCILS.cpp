//=====================================
//Libraries and namespace
#include <bits/stdc++.h>
using namespace std;


//=====================================
//Macro
#define sp ' '
#define el '\n'
#define fi first
#define se second
#define task "PENCILS"
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++i)
#define FORl(i, a, b) for(int (i) = (a); (i) < (b); ++i)
#define FORb(i, a, b) for(int (i) = (a); (i) >= (b); --i)
#define FORlb(i, a, b) for(int (i) = (a); (i) > (b); --i)
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define FILEOP()                            \
{                                           \
    freopen(task".inp", "r", stdin);        \
    freopen(task".out", "w", stdout);       \
}

template<class T> T _abs(T x)
{
    return (x < 0) ? -x : x;
}
template<class T, class P> void maximize(T &x, P y)
{
    x = (x > y) ? x : y;
}
template<class T, class P> void minimize(T &x, P y)
{
    x = (x < y) ? x : y;
}

//=====================================
//Typedefs
template<class T> struct SegmentTree
{
    #define lc id*2
    #define rc id*2+1

    typedef vector<T> vt;
    vt ST;

    void build(int id, int l, int r, const vt &a)
    {
        if(l > r) return;
        if(l == r)
        {
            ST[id] = a[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(lc, l, mid, a);
        build(rc, mid+1, r, a);

        ST[id] = max(ST[lc], ST[rc]);
    }
    T query(int id, int l, int r, int ql, int qr)
    {
        if(qr <  l || r <  ql || l > r) return T();
        if(ql <= l && r <= qr) return ST[id];

        int mid = (l + r) >> 1;
        return max(query(lc, l, mid, ql, qr), query(rc, mid+1, r, ql, qr));
    }

    SegmentTree() {}
    SegmentTree(int _n)
    {
        ST = vt(_n * 4 + 10, T());
    }
};


//=====================================
//Typedefs
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vii vect;
int n, k;


//=====================================
//Function and procedures
void FileInit()
{
    FILEOP();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    int c;
    scanf("%d%d", &n, &k);
    vect = vii(n+1);

    FOR(i, 1, n)
    {
        scanf("%d", &c); vi smp(c);
        for(int &x: smp) scanf("%d", &x);
        vect[i] = ii(*min_element(whole(smp)), *max_element(whole(smp)));
    }
}

//Solve
void is_that_right()
{
    SegmentTree<int> st(n);
    int res = 1000000007;
    vi xx(n+1, 0);

    sort(whole_1(vect));
    FOR(i, 1, n) xx[i] = vect[i].second;
    st.build(1, 1, n, xx);



    FOR(i, 1, n-k+1)
    {
        res = min(res, _abs(st.query(1, 1, n, i, i+k-1) - vect[i].first));
    }
    cout << res << el;
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    is_that_right();
    return 0;
}

/*
5 3
3 2 1 3
2 4 1
3 4 2 4
3 3 2 3
3 2 5 6
*/
