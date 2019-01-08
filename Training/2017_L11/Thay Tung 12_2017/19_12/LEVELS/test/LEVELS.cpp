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
#define task "LEVELS"
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
int n, m;
vi res;
vii a;

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
inline int ReadInt()
{
    char b;
    for (b = getchar(); b < '0' || b > '9'; b = getchar());
    int res = b - '0';
    for (b = getchar(); b >= '0' && b <= '9'; b = getchar())
        res = res * 10 + b - '0';
    return res;
}
void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Enter1()
{
    n = ReadInt(); m = 1 << n;
    a = vii(m);
    res = vi(m, n);

    FORl(i, 0, m) a[i] = ii(ReadInt(), i);

}
void Enter2()
{
    n = ReadInt(); m = 1 << n;
    a = vii(m);
    res = vi(m, n);

    int u;
    FORl(i, 0, m) scanf("%d", &u), a[i] = ii(u, i);
}



//Main Procedure
int main()
{
    FileInit();

    Enter2();

    sort(whole(a));
    int k = m - 1, lv = 0, t = a[k].fi, p = 0;
    while(true)
    {
        while(k >= 0 && a[k].fi == t)  res[a[k--].se] = lv;                //Duplicated value
        if(k <= 0) break;
        t = a[k].fi, p = k + 1;
        FORb(i, n-1, 0) if((1 << i) & p) {lv = n - i; break;}
    }

    //for(int x: res) printf("%d ", x);
    for(int x: res) WriteInt(x), putchar(' ');


    FileClose();
    return 0;
}
