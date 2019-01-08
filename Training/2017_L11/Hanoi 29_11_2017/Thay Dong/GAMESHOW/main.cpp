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
	F[i][k] = t: Từ 1 -> i, ta qua k cửa, được max = t tiền
	Init: F[i][k] = -inf, F[1][1] = a[1];
		-->F[j][k + 1] = t - (j - i)*T + a[j];

	QHD: Tìm tham số mô tả trạng thái bài toán trong quá trình tìm lời giải
	ĐPT: Số bài toán * Chi phí chuyển
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
#define task "GAMESHOW"
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
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }


const long long inf = -(1000000069);
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, T;
vvi F;
vi a;

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
	scanf("%d%d", &n, &T);

	a = vi(n+3);
	F = vvi(n+3, vi(n+3, (inf)));

	FOR(i, 1, n) scanf("%lld", &a[i]);
}

//Process
void Solve()
{

//  FOR(i,1,n)
//	{
//	    FOR(j,1,n) F[i][j] = inf;
//	}


	F[1][1] = a[1];
	FOR(i, 1, n)    //Numbers of problem
	{
		FOR(k, 1, i)	//k doors passed
		{
			ll t = F[i][k];
			if(t >= 0)
            {
                F[i+1][k+1] = t + a[i+1] /*max(t + a[i+1], F[i+1][k+1])*/;
                if(t >= T && i != n-1) F[i+1][k] = max(t - T, F[i+1][k])/*max(t - T, F[i+1][k])*/;
            }
		}
	}

//	FOR(i,1,n)
//	{
//	    FOR(j,1,n) cout << F[i][j] << " ";
//	    puts("");
//	}

	FOR(i, 1, n) if(F[n][i] >= 0)
	{
		cout << i;
		return;
	}
	cout << -1;


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
