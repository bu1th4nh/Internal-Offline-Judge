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
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "PSWAP"
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
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
const ll inf = 1e18;
ll a[100001], b[100001], F[100001];
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
ll _abs(ll __a)
{
	if(__a < 0) return -__a;
	return __a;
}

//Enter
void Enter()
{
    scanf("%d", &n);

    FOR(i, 0, n) F[i] = 1e18;

    FOR(i, 1, n) scanf("%lld%lld", &a[i], &b[i]);
}

//Process
ll Get2(int u, int v)
{
	ll tmp = 1e18;
	if(a[u] != b[u] and a[v] != b[v]) tmp = _abs(a[u] - b[u]) + _abs(a[v] - b[v]);
	if(a[u] != b[v] and a[v] != b[u]) tmp = min(tmp, _abs(a[u] - b[v]) + _abs(a[v] - b[u]));
	return tmp;
}
ll Get3(int u, int v, int z)
{
	ll tmp = 1e18;

	if(a[u] != b[u] and a[v] != b[v] and a[z] != b[z]) tmp = min(tmp, _abs(a[u] - b[u]) + _abs(a[v] - b[v]) + _abs(a[z] - b[z]));
	if(a[u] != b[u] and a[v] != b[z] and a[z] != b[v]) tmp = min(tmp, _abs(a[u] - b[u]) + _abs(a[v] - b[z]) + _abs(a[z] - b[v]));

	if(a[u] != b[v] and a[v] != b[u] and a[z] != b[z]) tmp = min(tmp, _abs(a[u] - b[v]) + _abs(a[v] - b[u]) + _abs(a[z] - b[z]));
	if(a[u] != b[v] and a[v] != b[z] and a[z] != b[u]) tmp = min(tmp, _abs(a[u] - b[v]) + _abs(a[v] - b[z]) + _abs(a[z] - b[v]));

	if(a[u] != b[z] and a[v] != b[u] and a[z] != b[v]) tmp = min(tmp, _abs(a[u] - b[z]) + _abs(a[v] - b[u]) + _abs(a[z] - b[v]));
	if(a[u] != b[z] and a[v] != b[v] and a[z] != b[u]) tmp = min(tmp, _abs(a[u] - b[z]) + _abs(a[v] - b[v]) + _abs(a[z] - b[u]));

	return tmp;
}
void Solve()
{
	F[0] = 0;

	if(n == 1)
	{
		cout << _abs(a[1] - b[1]);
		return;
	}
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);

	swap(b[1], b[2]);

	F[1] = _abs(a[1] - b[1]);
	a[0] = 1e18; b[0] = -1e18;


	FOR(i, 2, n)
	{
		F[i] = F[i-2] + Get2(i-1, i);
		if(i >= 3) F[i] = min(F[i], F[i-3] + Get3(i-2, i-1, i));

		//cerr << F[i] << "\n";
	}

	cout << F[n];

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
