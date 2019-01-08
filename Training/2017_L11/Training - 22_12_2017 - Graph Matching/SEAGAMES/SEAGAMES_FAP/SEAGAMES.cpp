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
#define task "SEAGAMES"
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
vi ovr, place, matchX, matchY;
int n, k;
vb used;
vvi g;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit() {
    FILEOP()
}
void FileClose() {
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter() {
	scanf("%d%d", &n, &k);
	g = vvi(n, vi(n));
	place = vi(k);

	FORl(i, 0, k) scanf("%d", &place[i]), --place[i];

	FORl(i, 0, n) {
        FORl(j, 0, n) {
            scanf("%d", &g[i][j]);
        }
	}
}

//Check
bool DFS(int s, int lim) {
    FORl(u, 0, n) if(!used[u] && g[s][u] <= lim) {
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
    int l = 0, h = 1000000;
    int db;

    while(l <= h)
    {
        matchX = matchY = vi(n, -1);
        int mid = (l + h) / 2;
        bool ok = true;

        for(int i = 0; i < n && ok; ++i) {
            used = vb(n, false);
            ok &= DFS(i, mid);
        }

        if(ok) h = mid - 1, db = mid, ovr = matchX;
        else l = mid + 1;
    }


    cerr << db << "\n";
    for(int x: place) printf("%d ", ovr[x]+1);

}


void CheckDebug() {
    vi test({1, 0, 2, 3, 4});
    vi ans({2, 3, 0, 4, 1});


    int out = 0, aaa = 0;

    FORl(i, 0, 5)
    {
        out = max(out, g[test[i]][ovr[test[i]]]);
        aaa = max(aaa, g[test[i]][ans[i]]);
    }


    cerr << "\n" << out << " " << aaa << "\n";
    if(out == aaa) cerr << "Correct!\n";
    else cerr << "Wrong!\n";
}



//Main Procedure
int main() {
	FILEOP();
    Enter();
    Solve();
    return 0;
}
