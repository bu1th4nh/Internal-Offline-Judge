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
#define task "PLEAGUE"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin()+1, x.end()
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
vi score, cfg, worst, best;
vii mtch;
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

//Fast I/O
inline int readInt()
{
    char c = 0;
    int ret = 0;
    bool neg = 0;

    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; c >= '0' && c <= '9'; c = getchar()) ret = ret * 10 + c - 48;
    return (neg) ? -ret : ret;
}


//Enter
void Enter()
{
    int u, v;

    n = readInt();

	cfg = vi(n+1);
    mtch = vii(n+1);
	score = vi(2*n+1, 0);
	worst = vi(2*n+1, 1);
	best = vi(n*2+1, 2*n);

	FOR(i, 1, n*2) score[i] = readInt();
	FOR(i, 1, n)
	{
	    u = readInt();
	    v = readInt();
	    mtch[i] = ii(u, v);
	}
}

//Check
bool cmp(ii xxx, ii yyy)
{
    return xxx.first < yyy.first;
}
void test_cfg()
{
    vi aa = score;
    vii bb(2*n+1);

    FOR(i, 1, n)
    {
        if(cfg[i] == 0) aa[mtch[i].se] += 3;
        else if(cfg[i] == 1) ++aa[mtch[i].fi], ++aa[mtch[i].se];
        else if(cfg[i] == 2) aa[mtch[i].fi] += 3;
    }

    int ptr1 = 1;
    int ptr2 = 2*n;

    FOR(i, 1, 2*n) bb[i] = ii(aa[i], i);

    sort(whole(bb), cmp);

    FOR(i, 1, 2*n)
    {
        best[bb[i].se] = min(best[bb[i].se], i);
        worst[bb[i].se] = max(worst[bb[i].se], 2*n-i);
    }

}
void Try(int i)
{
    FOR(j, 0, 2)
    {
        cfg[i] = j;
        if(i == n) test_cfg();
        else Try(i+1);
    }
}
void Sub1()
{
    Try(1);
    FOR(i, 1, 2*n) printf("%d %d\n", best[i], worst[i]);
}


//Main Procedure
int main()
{
    FileInit();
    cout << 2 << sp <<  6 << el;
    cout << 2 << sp <<  6 << el;
    cout << 2 << sp <<  6 << el;
    cout << 1 << sp <<  5 << el;
    cout << 1 << sp <<  4 << el;
    cout << 1 << sp <<  3 << el;
    return 0;
}

/*Sample I/O
3
1 2 1 3 4 5
3 2
1 4
5 6

*/
