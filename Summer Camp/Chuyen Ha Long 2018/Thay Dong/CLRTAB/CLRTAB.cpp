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
#define task "CLRTAB"
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

//#define bu1th4nh

//=====================================
//Typedefs
struct data
{
    int x1, y1, x2, y2;
    data(int _a, int _b, int _c, int _d): x1(_a), y1(_b), x2(_c), y2(_d) {}
    data() {}

    void print()
    {
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int m, n, nTest;
vvi src, dst;
vvb avail;
vii clr;
vi dstr;

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
	scanf("%d%d", &m, &n);

    clr = vii(n+1);
    dstr = vi(n+1, 0);
    avail = vvb(m+1, vb(n+1, 1));
    src = dst = vvi(m+1, vi(n+1, 0));

	FOR(i, 1, m)
	{
	    FOR(j, 1, n)
	    {
	        scanf("%d", &src[i][j]);
	        ++dstr[src[i][j]];
	    }
	}

	FOR(i, 1, n) clr[i] = ii(dstr[i], i);
}

//Check
void MakeDest()
{
    sort(whole(clr));
    int p = 1;

    #ifdef bu1th4nh
        cerr << "Initial: \n";
        FOR(i, 1, n) cerr << clr[i].se << sp << clr[i].fi << el;
    #endif // bu1th4nh

    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            if(clr[i].fi > 0)
            {
                --clr[i].fi;
                dst[j][i] = clr[i].se;
            }
            else
            {
                --clr[n].fi;
                dst[j][i] = clr[n].se;
            }
        }
        sort(whole(clr));

        #ifdef bu1th4nh
            cerr << "Attempt #" << i << ": \n";
            FOR(i, 1, n) cerr << clr[i].se << sp << clr[i].fi << el;
        #endif // bu1th4nh

    }
    FOR(i, 1, m) FOR(j, 1, n)
    {
        avail[i][j] = (src[i][j] != dst[i][j]);
    }

#ifdef bu1th4nh
    cerr << "======================Summary======================\n";
    cerr << "Source: " << el;
    FOR(i, 1, m)
    {
        FOR(j, 1, n) cerr << src[i][j] << sp;
        cerr << el;
    }
    cerr << "Destination: " << el;
    FOR(i, 1, m)
    {
        FOR(j, 1, n) cerr << dst[i][j] << sp;
        cerr << el;
    }
    cerr << "Available?: " << el;
    FOR(i, 1, m)
    {
        FOR(j, 1, n) cerr << avail[i][j] << sp;
        cerr << el;
    }

#endif // bu1th4nh

}

//Process
void Moving()
{
    vector<data> res;
    FOR(i, 1, m)
    {
        FOR(j, 1, n) if(avail[i][j])
        {
            FOR(k, i, m)
            {
                FOR(l, j, n) if(avail[k][l])
                {
                    if(dst[i][j] == src[k][l])
                    {
                        swap(src[i][j], src[k][l]);
                        res.push_back(data(i, j, k, l));
                    }
                }
            }
        }
    }

    printf("%d\n", res.size());
    for(data x: res) x.print();



    #ifdef bu1th4nh
        cerr << "Source, after moving: " << el;
        FOR(i, 1, m)
        {
            FOR(j, 1, n) cerr << src[i][j] << sp;
            cerr << el;
        }
        cerr << "=========================TEST ENDED=========================\n";
    #endif // bu1th4nh


}

//Multitest
void Multi()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Enter();
        MakeDest();
        Moving();
    }
}


//Main Procedure
int main()
{
    FileDebug();
    Multi();
    return 0;
}
