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
#define task "BITSTR"
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

const int inf = 123456789;
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
int c, n, ok, res, st1, st0;        //c: number of step to change s[i] (From i-3 to i).
string s;
vi b;                               //b[i] = true if it is necessary to change s[i], = false otherwise.


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
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
	scanf("%s", &str);
	s = string(str);
	n = s.length();
}

//Process
void Solve()
{
    //Switch to 0
    b = vi(n, 0); c = 0;
    FORl(i, 0, n)
    {
        if(s[i] == '0' && c == 0) continue;
        b[i] = (c + s[i]) & 1;
        if(i > 2) c += b[i] - b[i-3];
        else c += b[i];
    }

    ok = b[n-1] + b[n-2] + b[n-3];
    st0 = (ok == 0) ? accumulate(whole(b), 0) : inf;


    //Switch to 1
    b = vi(n, 0); c = 0;
    FORl(i, 0, n)
    {
        if(s[i] == '1' && c == 0) continue;
        b[i] = 1 - ((c + s[i]) & 1);
        if(i > 2) c += b[i] - b[i-3];
        else c += b[i];
    }

    ok = b[n-1] + b[n-2] + b[n-3];
    st1 = (ok == 0) ? accumulate(whole(b), 0) : inf;

    //cerr << "It takes " << st0 << " steps to convert whole string into 0\n";
    //cerr << "It takes " << st1 << " steps to convert whole string into 1\n";


    res = min(st0, st1);

    if(res == inf) puts("-1");
    else printf("%d", res);
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
