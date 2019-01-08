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
#define task "Letters"
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
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vii> vvii;
int n, m, k;
vvi ps;
vvc a;

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

//Enter
void Enter()
{
	scanf("%d%d%d\n", &n, &m, &k);

	ps = vvi(n+1, vi(m+1, 0));
	a = vvc(n+1, vc(m+1));

	FOR(i, 1, n)
	{
	    FOR(j, 1, m)
	    {
	        a[i][j] = getchar();
	        ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + int(a[i][j] == 'a');
	    }
	    scanf("\n");
	}
}

//Check
int get(int x1, int y1, int x2, int y2)
{
    return ps[x2][y2] - ps[x2][y1-1] - ps[x1-1][y2] + ps[x1-1][y1-1];
}
bool chk(int i, int j, int i2, int j2)
{
    return (a[i][j] == a[i2][j2] && a[i][j] == a[i][j2] && a[i][j] == a[i2][j]);
}
void sub1()
{
    ll res = 0LL;
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            FOR(i2, i+1, n)
            {
                FOR(j2, j+1, m)
                {
                    if(get(i, j, i2, j2) <= k && chk(i, j, i2, j2)) ++res;
                }
            }
        }
    }
    cout << res << el;
}



//Process




//Output





//Main Procedure
int main()
{
    FileInit();
    Enter();
    sub1();
    return 0;
}
