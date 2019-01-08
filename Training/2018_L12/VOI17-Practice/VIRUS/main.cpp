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
#define task "VIRUS"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
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
bool check_s2;
vi dp, query;
int n, sz;
string s;

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
    char str[8192];
    scanf("%d", &n);
    scanf("%s", &str);
    s = ' ' + string(str);
    sz = s.size() - 1;
    dp = vi(sz+1, 0);
    query = vi(n+1);
    FOR(i, 1, n) scanf("%d", &query[i]);
}

//Check
void Sub1()
{
    FOR(i, 1, sz)
    {
        FOR(j, i, sz) if((j - i + 1) + j <= sz)
        {
            int ndiff = 0;
            int len = j - i + 1;

            FORl(k, 0, len)
            {
                if(s[i + k] != s[j + k + 1]) ++ndiff;
            }

            dp[ndiff] = max(dp[ndiff], len);
        }
    }


    FOR(i, 1, sz) dp[i] = max(dp[i], dp[i-1]);
    FOR(i, 1, n)
    {
        printf("%d\n", dp[query[i]]);
    }
}
void Sub3()
{
    vvi next_diff(sz+1, vi(sz+1, 0));

    FOR(i, 1, sz) FOR(j, i, sz)
    {
        next_diff[i][j] = next_diff[i-1][j-1] + (s[i] != s[j]);     //????
    }

    FOR(i, 1, sz-1)
    {
        FOR(j, i, sz)
        {
            if(2*j - i + 1 > sz) break;

            int diff = next_diff[j][2*j - i + 1] - next_diff[i-1][j];
            dp[diff] = max(dp[diff], j - i + 1);
        }
    }

    FOR(i, 1, sz) dp[i] = max(dp[i], dp[i-1]);
    FOR(i, 1, n)
    {
        printf("%d\n", dp[query[i]]);
    }
}


//Output
void Solve()
{
    if(sz == 1)
    {
        FOR(i, 1, n) puts("0");
        return;
    }


    if(sz <= 300)
    {
        Sub1();
    }
    else
    {
        Sub3();
    }
}



//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
