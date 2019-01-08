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
#define task "AIRPLANS"
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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
int n, m, LLim, RLim, cur;
vi res, nblock, pos;
string a, cmd;

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
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Main Procedure
int main()
{
	FileInit();
	char st[131072];
	scanf("%d%d", &n, &m);

	scanf("%s", &st); a = string(st); a = '#' + a + '#';
	scanf("%s", &st); cmd = string(st); cmd = '?' + cmd;

	nblock = vi(n+2, 0); nblock[0] = 0;

	cur = LLim = RLim = 0;
	FOR(i, 1, m)
	{
		cur += (cmd[i] == 'L') ? -1 : 1;
		LLim = min(LLim, cur);
		RLim = max(RLim, cur);
	}

	FOR(i, 1, n+1)
	{
		nblock[i] = nblock[i-1] + ((a[i] == '#') ? 1 : 0);
		if(i <= n && a[i] == 'D') pos.pb(i);
	}

	for(int p:pos)
	{
		int l = p + LLim;
		int r = p + RLim;

		if(l > 0 && r <= n && (( nblock[r] - nblock[l-1] ) == 0)) res.pb(p);
	}

	cout << res.size() << "\n";
	for(int RES: res) cout << RES << " ";

	FileClose();

    return 0;
}
