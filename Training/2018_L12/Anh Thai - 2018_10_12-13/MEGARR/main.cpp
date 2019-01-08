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
#define task "MEGARR"
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

const long long inf = (long long)(1e18+7);
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi a, b, neg_a, pos_a, neg_b, pos_b;
ll k_th, res, sz[5];
int n, m;


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
inline ll readInt()
{
    ll ret = 0LL;
    bool neg = 0;
    char c = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    return neg ? -ret : ret;
}
void writeLL(ll x)
{
    if(x < 0)
    {
        putchar('-');
        x = ~x + 1;
    }

    if(x > 9) writeLL(x / 10);
    putchar(x % 10 + '0');
}



//Enter
void Enter()            //Check n, m! n->vector A, m->vector B.
{
	k_th = readInt();

	n = readInt(); a = vi(n+1, 0);
	FOR(i, 1, n) a[i] = readInt();

	m = readInt(); b = vi(m+1, 0);
	FOR(i, 1, m) b[i] = readInt();

	sort(whole(a));
	sort(whole(b));

	FOR(i, 1, n) if(a[i] < 0) neg_a.push_back(-a[i]);
	else pos_a.push_back(a[i]);
	FOR(i, 1, m) if(b[i] < 0) neg_b.push_back(-b[i]);
	else pos_b.push_back(b[i]);

	reverse(neg_a.begin(), neg_a.end());
	reverse(neg_b.begin(), neg_b.end());

	sz[1] = pos_a.size();
	sz[2] = neg_a.size();
	sz[3] = pos_b.size();
	sz[4] = neg_b.size();

//    cerr << "==================================\n";
//    for(auto x: pos_a) cerr << x << sp; cerr << el;
//    for(auto x: neg_a) cerr << x << sp; cerr << el;
//    for(auto x: pos_b) cerr << x << sp; cerr << el;
//    for(auto x: neg_b) cerr << x << sp; cerr << el;
//    cerr << "==================================\n";
}

//Process
ll count_same_sign(vi &_a, vi &_b, ll X)
{
    ll ret = 0LL;
    int j = _b.size() - 1;

    for(auto a_i: _a)
    {
        while(j >= 0 && 1LL * a_i * _b[j] > X) --j;
        if(j < 0) break;

        ret += j+1;
    }

//    cerr << el;
//    for(auto x: _a) cerr << x << sp; cerr << el;
//    for(auto x: _b) cerr << x << sp; cerr << el;
//    cerr << "Return value: " << ret << el;
//    cerr << el;


    return ret;
}
bool check(ll X)
{
    ll ret = 0LL;

    ret += count_same_sign(pos_a, pos_b, X);
    ret += count_same_sign(neg_a, neg_b, X);

    ret += 1LL * sz[2] * sz[3] - count_same_sign(neg_a, pos_b, -X-1LL);
    ret += 1LL * sz[1] * sz[4] - count_same_sign(pos_a, neg_b, -X-1LL);

//    cerr << ret << sp;

    return (ret >= k_th);
}
void Solve()
{
    ll L = -inf, R = inf, mid = 0LL;
    while(L <= R)
    {
        mid = (L + R) >> 1;
        if(check(mid))
        {
            R = mid - 1LL;
            res = mid;
        }
        else L = mid + 1LL;

//        cerr << el;
//        cerr << L << sp << R << sp << mid << el;
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
