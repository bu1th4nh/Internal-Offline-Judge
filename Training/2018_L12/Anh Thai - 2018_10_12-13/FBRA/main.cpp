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
#define task "FBRA"
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


const long long mod = 1000000007;
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
vc rev_bracket;
string src;
vi state;
vvi dp;
int n;

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
    rev_bracket = vc(1000, '_');
    state = vi(1000, 0);

    rev_bracket['['] = ']';
    rev_bracket['('] = ')';
    rev_bracket['{'] = '}';

    state['['] = -1;
    state['('] = -2;
    state['{'] = -3;

    state[']'] = 1;
    state[')'] = 2;
    state['}'] = 3;

    char str[10101];
    scanf("%s", &str); src = '.' + string(str);
    n = (int)src.size() - 1;

    dp = vvi(n+2, vi(n+2, 0));
}

//Check
int check(int pos1, int pos2)
{
    char &x = src[pos1];
    char &y = src[pos2];

    return ((!state[x]) && state[y] > 0) || (!state[y]) || (state[x] == -state[y]);
}

//Process
void Solve()
{
    FOR(i, 1, n+1) dp[i][i-1] = 1;
    FORb(l, n-1, 1) if(state[src[l]] <= 0)
    {
        FOR(r, l+1, n) if(state[src[r]] >= 0)
        {
            FOR(i, l+1, r) if(check(l, i))
            {
                dp[l][r] = (dp[l][r] + 1LL * dp[l+1][i-1] * dp[i+1][r] * (1 + 2*(state[src[l]] == 0 && state[src[i]] == 0))) % mod;
            }
        }
    }

    cout << dp[1][n] << el;
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
