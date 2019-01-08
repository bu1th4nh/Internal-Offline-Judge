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
#include <tuple>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "SAFEKEY"
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
string src, dst;
int res;

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
	char str[131072];
	scanf("%s", &str); src = string(str);
	scanf("%s", &str); dst = string(str);
}

//Check
void Decr()
{
    int n = src.size(); --n;

    while(src[n] == '0') src[n--] = '9';
    --src[n];

    if(n > 0 && src[0] == '0') src.erase(0, 1);
}
int Calc(string &s)
{
    int sz = s.length(), last = 1, ret = 0;

    if(sz == 1) return ((s[0] - '0') + 1);


    ret = 10 + 90 * (sz - 2) + 10 * (s[0] - '0' - 1) + (s[1] - '0');

    int d = (s[0] - s[1] + 10)%10;

    FORl(i, 2, sz)
    {
        if((s[i-1] + d - '0') % 10 > (s[i] - '0')) break;
        if((s[i-1] + d - '0') % 10 < (s[i] - '0'))
        {
            last = 0;
            break;
        }
    }


    //cerr << sz << "\n" << ret << "\n";

    ret += last;

    return ret;
}


//Process
void Solve()
{
    Decr();

    //cerr << src << "\n" << dst << "\n";

    res = Calc(dst) - Calc(src);
    cout << res << "\n";
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
