/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
//=====================================
//Solution
/*
	B0: Input, tính d[i] :: TG về đích
 	B1: Sort theo t[i] :: TG xuất phát
	B2: Đánh số thứ tự theo TGXP t[i]
	B3: Sort theo d[i], kể cả STT
	B4: Tìm dãy con tăng dài nhất của STT[i].
*/

//=====================================
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
#define task "WALKING"
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
struct data
{
	int id, t, d, vel;
	data(int __x, int __v)
	{
		t = __x, vel = __v;
	}
	/*data(int __a, int __b, int __c)
	{
		id =
	}*/
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<data> vd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int l, n, res;
vd a;
vi f;

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
	int u, v;
	scanf("%d%d", &l, &n);
	FOR(i, 1, n)
	{
		scanf("%d%d", &u, &v);
		a.pb(data(u, v));
	}

}

//Check
bool cmp1(data x, data y)
{
	return x.t < y.t;
}
bool cmp2(data x, data y)
{
	return (x.t + l/x.vel < y.t + l/y.vel || ((x.t + l/x.vel == y.t + l/x.vel) && (y.vel*l*1LL < x.vel*l*1LL)));
}

//LIS
int T[131072], G[131072];
void updateBIT(int x, int v)
{
	while(x <= 131070)
	{
		T[x] = max(T[x], v);
		x += x & (-x);
	}
}
int getBIT(int i)
{
	int rs = 0;
	while(i > 0)
	{
		rs = max(rs, T[i]);
		i -= i & (-i);
	}
	return rs;
}
int LIS()
{
	int lis = 0;
	FOR(i, 1, n)
	{
		G[i] = getBIT(f[i]) + 1;
		updateBIT(f[i], G[i]);
		if(lis < G[i]) lis = G[i];
	}
	return lis;
}


//Process
void Solve()
{
	sort(whole(a), cmp1);

	FORl(i, 0, n) a[i].id = i + 1;

//	puts(""); for(data x: a) printf("%d ", x.id); puts("");

	sort(whole(a), cmp2);

	FORl(i, 0, n) f.push_back(a[i].id);
	f.push_back(0);

    reverse(whole(f));

//	puts(""); for(data x: a) printf("%d ", x.id); puts("");
//	puts(""); for(int x: f) printf("%d ", x); puts("");

	res = LIS();

	res = res*(res-1)/2;
	cout << res;

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
