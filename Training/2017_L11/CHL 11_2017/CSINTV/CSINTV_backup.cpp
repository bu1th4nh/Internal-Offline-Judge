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
#define task "CSINTV"
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
vii vect, res2;
int n, res1;
vi F, trace;


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

//Enter
void Enter()
{
    int u, v;
	scanf("%d", &n);
	vect.push_back(ii(-1234567890, 1234567890));



	F = trace = vi(n+2, 0);

	FOR(i, 1, n)
	{
	    scanf("%d%d", &u, &v);
	    vect.push_back(ii(u, v));
	}
}
//void updateBIT(int u, int l)
//{
//    while(u <= 1000000) {
//        tree[u] = max(tree[u], l);
//        u += u & (-u);
//    }
//}
//
//int getBIT(int u)
//{
//    int t = 0;
//    while(u > 0) {
//        t = max(t, tree[u]);
//        u -= u & (-u);
//    }
//    return t;
//}

//Longest Increasing Sequence
int BinarySearch(int i, int j)
{
    //
}
void LIS()
{
    vect.push_back(ii(1234567890, -1234567890));
    int jmax = 0;
    F[n+1] = 1;

    FORb(i, n+1, 0)
    {
        jmax = n+1;
        FOR(j, i+1, n+1)
        {
            if(vect[j].fi >= vect[i].fi && F[j] > F[jmax])
            {
                jmax = j;
            }
            F[i] = F[jmax] + 1;
            trace[i] = jmax;
        }
    }

    res1 = F[0] - 2;
    printf("%d\n", res1);
    int i = trace[0];
    while(i != n+1)
    {
        printf("%d %d\n", vect[i].fi, vect[i].se);
        i = trace[i];
    }
}

//Process
bool cmp(ii _a, ii _b)
{
    return (_a.second > _b.second || (_a.second == _b.second && _a.first < _b.first));
}
void Solve()
{
    if(n == 1)
    {
        printf("1\n%d %d\n", vect[1].fi, vect[1].se);
        return;
    }

    sort(whole(vect), cmp);

    //puts(""); for(ii x: vect) printf("%d %d\n", x.first, x.second); puts("");


    LIS();

//    printf("%d\n", res1);
//    for(ii x: res2) printf("%d %d\n", x.first, x.second);

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
