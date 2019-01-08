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
#define task "FROG"
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
typedef stack<int> si;
int n, s[2000000];
vi h, j;


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
	scanf("%d", &n);
	h = j = vi(n+1);

	FOR(i, 1, n) scanf("%d", &h[i]);
	FOR(i, 1, n) scanf("%d", &j[i]);
}

//Process
void Solve() {
    vi res;
    int b = 1000000;
    int top = n;

    s[0] = b;
    FOR(i, 0, n - 1) s[i] = 1000000 - i + 1;

    FORb(i, n, 1)
    {
        while(h[i] > s[top]) --top;
        s[++top] = (h[i]);
        if(top + j[i] < 1000001) res.push_back(s[top] + j[i]);
        else res.push_back(-1);
    }
    reverse(whole(res));
    for(int f: res) printf("%d ", f);
}

//Main Procedure
int main() {
    Enter();
    Solve();
    return 0;
}
