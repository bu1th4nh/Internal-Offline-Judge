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
#define task "TRI"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin()+1, x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n;
vii a;

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

//Utilities
ll max(ll __a, ll __b, ll __c)
{
    return max(__a, max(__b, __c));
}
ll sqr(const int &a)
{
    return 1LL * a * a;
}
ll sqr_dist(ii &x, ii &y)
{
    return sqr(x.first - y.first) + sqr(x.second - y.second);
}
struct cmp
{
    bool operator() (int i, int j) const
    {
        return a[i].se < a[j].se;
    }
};



//Enter
void Enter()
{
    scanf("%d", &n);

    a = vii(n+1);
    FOR(i, 1, n) scanf("%lld%lld", &a[i].fi, &a[i].se);
}

//Check
void Solve()
{
    int j = 1, id = 0;
    set<int, cmp> st;

    sort(whole(a));

    ll res = max(sqr_dist(a[1], a[2]), sqr_dist(a[2], a[3]), sqr_dist(a[1], a[3]));
    FOR(i, 1, n)
    {
        vi tmp;

        while((j <= n) && a[i].fi - a[j].fi > (ll)(sqrt(res))) st.erase(j++);
        a[0].se = a[i].se - (ll)sqrt(res) - 2;

        set<int, cmp>::iterator ptr = st.lower_bound(0);
        while(ptr != st.end())
        {
            id = *ptr;
            if(a[id].se > a[i].se + (ll)sqrt(res)) break;

            tmp.push_back(id);
            ++ptr;
        }

        if(tmp.size() > 1)
        {
            FORl(j, 0, tmp.size()-1)
            {
                res = min(res, max
                (
                    sqr_dist(a[i]     , a[tmp[j]]),
                    sqr_dist(a[tmp[j]], a[tmp[j+1]]),
                    sqr_dist(a[i]     , a[tmp[j+1]])
                ));
            }
        }

        st.insert(i);
    }

    cout << fixed << setprecision(4) << (long double)sqrt(res);
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
