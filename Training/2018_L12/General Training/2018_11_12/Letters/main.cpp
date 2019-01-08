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
vvi a, ps;

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

	ps = a = vvi(n+1, vi(m+1, 0));

	FOR(i, 1, n)
	{
	    FOR(j, 1, m)
	    {
	        a[i][j] = getchar() - 'a';
	        ps[i][j] = ps[i-1][j] + (!a[i][j]);
	    }
	    getchar();
	}

	FOR(i, 1, n)
	{
	    FOR(j, 1, m) cerr << a[i][j] << sp;
	    cerr << el;
	}
}



//Process
void Solve()
{
    ll res = 0LL;
    FORl(x, 1, n) FOR(y, x+1, n)
    {
        int cnt_a = 0;
        int cnt_pair[26] = {};

        for(int i = 1, j = 1; i <= m; ++i)
        {
            cnt_a += ps[y][i] - ps[x-1][i];
            while(cnt_a > k)
            {
                cnt_a -= ps[y][j] - ps[x-1][j];
                if(a[x][j] == a[y][j]) cnt_pair[a[x][j]]--;
                j++;
            }

            if(a[x][i] == a[y][i]) res += max(0, cnt_pair[a[x][i]++]);
        }
    }
    cout << res << el;
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}

/*
3 4 4
aabb
baab
baab
*/
