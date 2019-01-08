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
#define task "PASSWORD"
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



const unsigned long long    DEFAULT_MODULUS    = int(1e9 + 7);
const unsigned long long    DEFAULT_BASE_POW   = 47;
const int                   DEFAULT_N          = 300009;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ull> vll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;

//=====================================
//Hashing
class HASHING
{
private:

	vll POW, HASH;
	ull BASE, MOD;
	int N;

	void InitHash(string t)
	{
		POW = vll(N, 0LL);                POW[0] = 1;
		HASH = vll(t.length() + 16, 0LL); HASH[0] = 1;
		FOR(i, 1, N) POW[i] = (POW[i-1] * BASE) % MOD;

		FOR(i, 1, t.length()-1)   //Start from 1
		{
			HASH[i] = (HASH[i-1] * BASE + t[i]) % MOD;
		}
	}

public:
	HASHING(string t)
	{
		BASE = DEFAULT_BASE_POW;
		MOD  = DEFAULT_MODULUS;
		N    = DEFAULT_N;
		InitHash(t);
	}
	HASHING(string t, ull __BASE, ull __MOD, int __N)
	{
		BASE = __BASE;
		MOD  = __MOD;
		N    = __N;
		InitHash(t);
	}
	HASHING()
	{
		BASE = DEFAULT_BASE_POW;
		MOD  = DEFAULT_MODULUS;
		N    = DEFAULT_N;
	}

	ll get(int __l, int __r)
	{
		return (HASH[__r] - HASH[__l - 1] * POW[__r - __l + 1] + MOD*MOD*1LL) % MOD;
	}
};


//=====================================
//Variable declaration
string a, b;
HASHING ha;
HASHING hb;
int n, pos;

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

//Main Procedure
int main()
{
	char st[300009]; scanf("%s", &st); a = b = string(st);
	reverse(whole(b));

	a = ' ' + a, b = ' ' + b;
	n = a.length() - 1;

	ha = HASHING(a);
	hb = HASHING(b);

    bool cc = true;
	FOR(i, 2, n)
	{
		cc = cc && (a[i] == a[1]);
		if(!cc) break;
	}
	if(cc || n == 1)
	{
		a.erase(0, 1);
		printf("%s\n", a.c_str());
		return 0;
	}


	FORb(i, n, 1)
	{
	    ull sb = hb.get(1, i), sa = ha.get(n - i + 1, n);

		if(sa == sb)
		{
		    pos = i;
		    break;
		}
	}

	a.erase(0, 1);
	printf("%s", a.c_str());
	FOR(i, pos+1, n) printf("%c", b[i]);

    return 0;
}
