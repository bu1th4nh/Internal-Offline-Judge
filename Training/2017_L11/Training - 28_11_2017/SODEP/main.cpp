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
#define task "SODEP"
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

const int maxn = 1e5+7;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
static int LP[maxn + 1];
bool IsPrime[maxn + 1];
vll prime, RES;
int nRes = 0;

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

//Some weird stuff
void Sieve()
{
	FOR(i, 2, maxn)
	{
		if(LP[i] == 0)
		{
			LP[i] = i;
			prime.pb(i);
			IsPrime[i] = true;
		}
		for(int j = 0; j < int(prime.size()) && prime[j] <= LP[i] && i * prime[j] <= maxn; ++j)
		{
			LP[i*prime[j]] = prime[j];
		}
	}
}
bool Check(ll x)
{
	ll tmp = 0;
	while(x > 0)
	{
		tmp += (x % 10)*(x % 10);
		x /= 10;
	}
	return IsPrime[tmp];
}

//Process
void SOLVE()
{
	RES.pb(-1);
	ll xxx = 0;
	while(nRes <= 10000)
	{
		while(!Check(xxx)) ++xxx;
		RES.pb(xxx);
		++nRes;
		++xxx;
	}


	int N;
	while(scanf("%d", &N) == 1)
	{
		printf("%lld\n", RES[N]);
	}

}


//Main Procedure
int main()
{
    FileInit();


    Sieve();
	SOLVE();
    return 0;
}
