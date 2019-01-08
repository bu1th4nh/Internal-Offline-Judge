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
#define task "SD2EQ"
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



const long long inf = 1000000000000000;
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;
typedef vector<iii> viii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vll F, RF, L, R, a;
ll res;
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
    scanf("%d", &n);

    res = -inf;
    a = F = RF = L = R = vll(n+2, -inf);

    FOR(i, 1, n) scanf("%lld", &a[i]);
}

//Process
void UniteForever()
{
    FOR(i, 1, n) F[i] = max(F[i-1] + a[i], a[i]);
    FORb(i, n, 1) RF[i] = max(RF[i+1] + a[i], a[i]);

    FOR(i, 1, n) L[i] = max(F[i], L[i-1]);
    FORb(i, n, 1) R[i] = max(RF[i], R[i+1]);

    //FOR(i, 1, n) res = max(res, L[i-1] + R[i]);
    FOR(i, 1, n-1) res = max(res, L[i] + R[i+1]);

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
