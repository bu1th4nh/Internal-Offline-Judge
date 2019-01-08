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
using namespace std;


//=====================================
//Macros
#define task "NANGSUAT"
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi matchY, matchX;
vb used;
vvi g;
int n;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit() {
    FILEOP();
}
void FileClose() {
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter() {
	scanf("%d", &n);

	g = vvi(n, vi(n));

	FORl(i, 0, n) {
        FORl(j, 0, n) {
            scanf("%d", &g[i][j]);
        }
	}
}

//Check
bool DFS(int s, int lim) {
    FORl(u, 0, n) if(!used[u] && g[s][u] >= lim) {
        used[u] = true;
        if(matchY[u] == -1 || DFS(matchY[u], lim)) {
            matchY[u] = s, matchX[s] = u;
            return true;
        }
    }
    return false;
}

//Process
void Solve() {
    int l = 0, h = 1000000000;
    int res1;
    vi res2;

    while(l <= h) {
        matchY = matchX = vi(n, -1);
        bool ok = true;
        int mid = (l + h) / 2;

        for(int u = 0; u < n && ok; ++u) {used = vb(n, false); ok &= DFS(u, mid);}
        if(ok) l = mid + 1, res2 = matchX, res1 = mid;
        else h = mid - 1;
    }

    printf("%d\n", res1);
    for(int x: res2) printf("%d\n", x + 1);
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
