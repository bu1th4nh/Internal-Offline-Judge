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

const int inf = 100007;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, char> ci;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ci> vci;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, res;
vci vect;
vi S, C;

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

//Enter
void Enter()
{
    int u;
    char k;
    scanf("%d", &n);

    C = vi(n+1, 0);
    S = vi(n+1, inf);
    vect.push_back(ci(-inf-99, '?'));

    FORl(i, 0, n)
    {
        cin >> u >> k;
        vect.push_back(ci(u, k));
    }
}

//Process
void Solve()
{
    int max_1 = 0, max_2 = 0;
    S[0] = 0;

    sort(whole(vect));

    int prev = 1, tmp = 1;
    FOR(i, 1, n)
    {
        if(vect[i].se == vect[prev].se) tmp = i;
        else
        {
            max_1 = max(max_1, vect[i].fi - vect[prev].fi);
            prev = i, tmp = i;
        }
    }

    FOR(i, 1, n)
    {
        C[i] = C[i-1] + (vect[i].se == 'H') ? 1 : -1;
        if(S[C[i]] >= inf) S[C[i]] = i;
        else max_2 = max(max_2, vect[i].fi - vect[S[C[i]+1]].fi);
    }

    cout << max(max_1, max_2);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
