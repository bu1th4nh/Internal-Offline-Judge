/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*
        Find number of S[i] such that: S[i] - L <= S[j] <= S[i] - H.

        And my code is powered with Tomorrowland's Magic :P
*/
//Libraries and namespaces
#include <bits/stdc++.h>
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#endif // __cplusplus

using namespace std;
using namespace __gnu_pbds;


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task "TSEQ"
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
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ord_set;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;


ord_set planaxis;
ll l, h, res;
vi a, ps;
int n;

//=====================================
//Functions and procedures
//Initialization and preparation
void LiveToday()
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
void LoveTomorrow()
{
    scanf("%lld %lld", &l, &h);
    scanf("%d", &n);

    a = ps = vi(n+1, 0LL);
    res = 0LL;

    FOR(i, 1, n)
    {
        scanf("%lld", &a[i]);
        ps[i] = 1LL * (i-1) * a[i] + ps[i-1];
    }
}

//Check
void S1()
{
    FOR(i, 1, n)
    {
        FOR(j, i, n)
        {
            if(ps[j] - ps[i-1] >= l && ps[j] - ps[i-1] <= h) ++res;
        }
    }
    cout << res;
}

//Process
void UniteForever()
{
    ord_set planaxis;

    int x, y;
    FOR(i, 1, n)
    {
        planaxis.insert(ps[i-1]);

        x = planaxis.order_of_key(ps[i] - l + 1);
        y = planaxis.order_of_key(ps[i] - h);

        if(x > y) res += (x-y);
    }
    cout << res << el;
}

//Main Procedure
int main()
{
    LiveToday();
    LoveTomorrow();
    UniteForever();
    return 0;
}
