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
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


const int inf = 1000000000;
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
string a, b;
int T, m, n;
vvi mem;

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

//Utilities
inline string readString()
{
    char c = 0;
    string ret;
    while(c < 'a' || c > 'z') c = getchar();
    for(; c >= 'a' && c <= 'z'; c= getchar()) ret += c;
    return ret;
}
void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int min_3(int x, int y, int z)
{
    return min(min(x, y), z);
}

//Enter
void Enter()
{
	a = ' ' + readString();
	b = ' ' + readString();

	n = a.size() - 1;
	m = b.size() - 1;

	//cerr << s << sp << t << el;

	mem = vvi(n+1, vi(m+1, -1));
}

//Check
int ED(int i, int j)
{
    if(!i) return j;
    if(!j) return i;

    if(mem[i][j] != -1) return mem[i][j];

    int ret = inf;
    if(a[i] == b[j]) ret = ED(i-1, j-1);
    else
    {
        ret = min_3(ED(i-1, j-1), ED(i-1, j), ED(i, j-1)) + 1;
    }

    return (mem[i][j] = ret);
}
int ED()
{
	mem = vvi(n+1, vi(m+1, inf));
    FOR(i, 0, n) mem[i][0] = i;
    FOR(i, 0, m) mem[0][i] = i;

    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            if(a[i] == b[j]) mem[i][j] = mem[i-1][j-1];
            else
            {
                mem[i][j] = min_3(ED(i-1, j-1), ED(i-1, j), ED(i, j-1)) + 1;
            }
        }
    }

    return mem[n][m];
}

//Process
void Solve()
{
    WriteInt(ED());
    putchar('\n');
}

//Main Procedure
int main()
{
    scanf("%d", &T);
    while(T--)
    {
        Enter();
        Solve();
    }
    return 0;
}
