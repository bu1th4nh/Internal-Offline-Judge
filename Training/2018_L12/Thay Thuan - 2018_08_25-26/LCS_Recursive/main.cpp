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
#define task ""
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


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
string s, t;
int T, m, n;
vvi dp;

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

//Utilities
inline string readString()
{
    char c = 0;
    string ret;
    while(c < 'a' || c > 'z') c = getchar();
    for(; c >= 'a' && c <= 'z'; c= getchar()) ret += c;
    return ret;
}
int max_3(int x, int y, int z)
{
    return max(max(x, y), z);
}

//Enter
void Enter()
{
	s = ' ' + readString();
	t = ' ' + readString();

	n = s.size() - 1;
	m = t.size() - 1;

	//cerr << s << sp << t << el;

	dp = vvi(n+1, vi(m+1, -1));
}

//Check
int LCS(int i, int j)
{
    if(i == 0 || j == 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ret = 0;

    ret = max(ret, LCS(i-1, j));
    ret = max(ret, LCS(i, j-1));
    if(s[i] == t[j]) ret = max(ret, LCS(i-1, j-1) + 1);

    dp[i][j] = ret;
    return ret;
}

//Process
void Solve()
{
    printf("%d\n", LCS(n, m));
}


//Main Procedure
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        Enter();
        Solve();
    }
    return 0;
}
