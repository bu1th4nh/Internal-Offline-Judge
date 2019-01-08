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
#define rwhole(x) x.rbegin(),x.rend()
#define whole(x) x.begin(),x.end()
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
    vect = vii(n);

    for(ii &x: vect)
    {
        scanf("%d", &c); vi smp(c);
        for(int &x: smp) scanf("%d", &x);
        x = ii(*min_element(whole(smp)), *max_element(whole(smp)));
    }
}

//Solve
void Solve()
{
    priority_queue<int, vi> pq;

    sort(rwhole(vect));
    FORl(i, 0, k) pq.push(vect[i].se);
    int res = pq.top() - vect[k-1].fi;

    FORl(i, k, n)
    {
        pq.push(vect[i].se);  pq.pop();
        res = min(res, pq.top() - vect[i].fi);
    }
    cout << res << el;
}


//Main Procedure
int main()
{
    //FileInit();
    Enter();
    Solve();
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
