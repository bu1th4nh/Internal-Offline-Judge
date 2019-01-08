/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*          -----Problem Analysis

        Idea: Arrange n col. -----> Arrange n-1 col. -----> .... ----> Arrange the last col.
        --Same type, but smaller in size.

        Use the flood-fill algorithm. And we only pay attention to the element that:
                - Contains '1'
                - n-th element
                - 2n-th element
                - 3n-th element
        ====>State: (x1, y1, xn, yn, x2n, y2n, x3n, x3n), can jump to:
        (x1', y1', xn', yn', x2n', y2n', x3n', x3n'), change to (x1', y1', 1, n, 2n, 3n)


        Implementation?


*/

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
#define task "BD"
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
struct data
{
    int x1, y1, x2, y2;
    data(int __a, int __b, int __c, int __d): x1(__a), y1(__b), x2(__c), y2(__d) {}
    data() {}

    void print()
    {
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
};


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
vvi src, dst;
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
	scanf("%d", &n);
	src = dst = vvi(4, vi(n+1, 0));

	FOR(i, 1, 3)
	{
	    FOR(j, 1, n)
	    {
	        scanf("%d", src[i][j]);
	        dst[i][j] = (i-1) * n + j;
	    }
	}
}

//Check





//Process




//Output





//Main Procedure
int main()
{
    //Your code goes here
    return 0;
}
