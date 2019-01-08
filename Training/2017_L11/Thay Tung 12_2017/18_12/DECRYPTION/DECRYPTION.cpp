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
#define task "DECRYPTION"
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

//Main Procedure
int main()
{
    FileInit();

    int n, x, r, res1 = 0;
    scanf("%d%d", &n, &r);

    vii a(n);
    vi res2(n);

    FOR(i, 0, n-1)
    {
        scanf("%d", &x);
        a[i] = ii(x, i);
    }

    sort(whole(a));

    ll y = -2147483648;

    FORl(i, 0, n)
    {
        if(a[i].fi - r > y)
        {
            y = a[i].fi - r;
            ++res1;
            res2[a[i].se] = y;
            continue;
        }
        else if(a[i].fi + r <= y)
        {
            res2[a[i].se] = a[i].fi;
            continue;
        }
        else if(a[i].fi - r <= y || a[i].fi + r > y)
        {
            ++res1;
            res2[a[i].se] = ++y;
        }
    }

    printf("%d\n", res1);
    for(int r: res2) printf("%d ", r);


    FileClose();

    return 0;
}
