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
#define task "BOOKSORT"
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
//Class library
struct FenwickTree
{
    #define _(x) (x & -x)
    typedef vector<long long> vi;

    int n;
    vi T;

    void update(int pos, int value)
    {
        while(pos <= n)
        {
            T[pos] += value;
            pos += pos & (-pos);
        }
    }
    int query(int pos)
    {
        int ret = 0;
        while(pos > 0)
        {
            ret += T[pos];
            pos -= pos & (-pos);
        }
        return ret;
    }

    FenwickTree(int __n) {n = __n; T = vi(n+77, 0LL);}
    FenwickTree() {}

    ~FenwickTree() {T.clear();}
};

//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef multiset<int>::iterator mset_itr;
typedef multiset<int> mset;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n;ll res;
vi a, kar;


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
    scanf("%d", &n);

    res = 0LL;
    a = kar = vi(n+1, 0);

    FOR(i, 1, n) scanf("%d", &a[i]);
}

//Process
void UniteForever()
{
    vi b = a;
    sort(whole(b));
    FOR(i, 1, n) kar[i] = (lower_bound(whole(b), a[i]) - b.begin());

    //FOR(i, 1, n) cerr << kar[i] << sp; cerr << el;

    FenwickTree ft(262144);
    FORb(i, n, 1)
    {
        res += ft.query(kar[i] - 1);
        ft.update(kar[i], 1);
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
