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
#define task "DRAWER"
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


//=====================================
//Typedefs
struct Data
{
    int id, a, b;

    Data() {}
    Data(int id, int a, int b): id(id), a(a), b(b) {}

    ~Data() {}

    void extract(int &__a, int &__b)
    {
        __a = a;
        __b = b;
    }

};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<Data> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, l, cur;
vi avail, lab;
vb isCircle;
vd vect;

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
    int a, b;

    scanf("%d%d", &n, &l);

    vect = vd(n+1);
    avail = lab = vi(l+1, 1);


    FOR(i, 1, n)
    {
        scanf("%d%d", &a, &b);
        vect[i] = Data(i, a, b);
    }
}

//Process
void Solve()
{
    int a, b, x;
    DisjointSet ds(l);

    FOR(i, 1, n)
    {
        vect[i].extract(a, b);

        if(avail[a])
        {
            puts("LADICA");
            //
        }
        else if(avail[b])
        {
            puts("LADICA");

        }
        else
        {
            //
        }

        puts("SMECE");
    }
}


//Main Procedure
int main()
{
    //FileInit();
    Enter();
    Solve();
    return 0;
}

/* Sample I/O
9 10
1 2
3 4
5 6
7 8
9 10
2 3
1 5
8 2
7 9

-------------
5 3
1 2
1 3
1 2
1 3
1 2

*/
