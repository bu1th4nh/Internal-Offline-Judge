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
#define task "PLEASANT"
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

const int base = 1000000007;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ll MAIN_RESULT;
string a, b;                        //d[0][j]: Number of plesant number which have EXACT j significant numbers
vvi d;								//d[i][j]: Number of plesant number which start from i and contain EXACT j numbers
vi T;   							//T[j]: Number of plesant number which have UP TO j significant numbers
                                 	//F[x]: Number of plesant number from 1 to x

//=====================================
//Functions and procedures
//Initialization and preparation
ll ModBase(ll __i)
{
	return (__i + base) % base;
}
void FileInit()
{
    FILEOP()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Enter
void Enter()
{
	char st[101];
	scanf("%s", &st); a = string(st);
	scanf("%s", &st); b = string(st);


	//cout << a << "\n" << b << "\n";

	T = vi(101, 0);
	d = vvi(10, vi(101));
}


//Premilinary Process
int ToInt(char __t)
{
	return (int)(__t - '0');
}

ll CalcF(string t)
{
	ll l_res = 1;int n = t.length();
	FORl(i, 1, n)
	{
		int delta = (t[i] - t[i-1]);
		if(delta == 0) continue;
		FORl(j, ToInt(t[i-1]), ToInt(t[i]))
		{
			l_res += d[j][n - i];
			l_res = ModBase(l_res);
		}
	}

	FORl(i, 1, ToInt(t[0]))
	{
		l_res += d[i][n];
		l_res = ModBase(l_res);
	}

	//cerr << l_res << "\n";

	l_res = ModBase(l_res + T[n-1]);

	return ModBase(l_res);
}

int Change(string &t)
{
	int n = t.length();
	FORl(i, 0, n-1)
	{
		if(t[i] > t[i+1])
		{
			FORl(j, i+1, n)
			{
				t[j] = t[i];
			}
			return 1;
		}
	}
	return 0;
}

void PreProcess()
{
	FOR(i, 1, 100) d[9][i] = 1;
	FOR(i, 1, 9) d[i][1] = 1, d[i][2] = 10 - i;
	FORb(i, 8, 1)
	{
		FOR(j, 2, 100) d[i][j] = (d[i][j-1] + d[i+1][j]) % base;
	}

	FOR(i, 1, 100)
	{
		FOR(j, 1, 9)
		{
			d[0][i] += d[j][i];
			d[0][i] = ModBase(d[0][i]);
		}
		T[i] += ModBase(T[i-1] + d[0][i]);
	}

	/*int i, j;
	while( cin >> i >> j )
	{
		printf("d[%d][%d] = %d", i, j, d[i][j]);
	}*/
}

//Process
void Solve()
{
	PreProcess();

	string old_b = b;
	Change(a), Change(b);

	MAIN_RESULT = ModBase(CalcF(b) - CalcF(a) + 1 - Change(old_b));

	cout << MAIN_RESULT;
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
