/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*              -------Problem Analysis

     - 2 bulbs will change the state after 1 operation;
     - If i, j connected - exist a path ===> There was a sequence to alter the state of the i-th, j-th bulb
            (hi-level operation)
     --> k-diff ==> (k-2)-diff , by a high|low level ops if(i, j) diff.

     Until: Case 1: Exist a diff.     (k is odd)
            Case 2: No diff.          (k is even)

     ====> Needed condition: nDiff MUST be even.
           Adequate cont'd:  There EXIST a way to convert k-diff to (k-2)-diff;

     Implementation?

        FOR(i, 1, m+n)
        {
            if a[i] != b[i]
            {
                BFS/DFS from i, if found a j-th vertex that a[j] != b[j]:
                    ==>Convert the strings along the path from i to j
                    Otherwise:
                    ==>Output -1, end the algorithm.
            }
        }


    |============================================================|
    |                                                            |
    |          Convert a large-size or difference problem        |
    |    to the smaller-size or difference, same-type problem    |
    |                                                            |
    |============================================================|

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
#define task "BULB"
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef queue<int> qi;
typedef vector<vii> vvii;
typedef map<ii, int> miii;
string src, dst;
int m, n, k;
vb avail;
vi trace;
vvi adj;
miii mp;
vi res;

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
    int u, v;
    char str[131072];

	scanf("%d%d%d", &m, &n, &k);
    n += m;

    adj = vvi(n+1);
    avail = vb(n+1, 1);
    trace = vi(n+1, -1);

    scanf("%s", &str); src = ' ' + string(str);
    scanf("%s", &str); dst = ' ' + string(str);

    FOR(i, 1, k)
    {
        scanf("%d%d", &u, &v);

        v += m;

        adj[u].pb(v);
        adj[v].pb(u);

        mp[ii(u, v)] = i;
        mp[ii(v, u)] = i;
    }
}

//Process
int BFS(int start)
{
    qi q;
    avail = vb(n+1, 1);
    trace = vi(n+1, -1);

    q.push(start);
    avail[start] = 0;
    trace[start] = start;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v: adj[u])
        {
            if(avail[v])
            {
                if(src[v] != dst[v])
                {
                    trace[v] = u;
                    return v;
                }
                else
                {
                    avail[v] = 0;
                    trace[v] = u;
                    q.push(v);
                }
            }
        }
    }

    return -1;
}
void Solve()
{
    FOR(i, 1, n)
    {
        if(src[i] != dst[i])
        {
            int stat = BFS(i);
            if(stat > 0)
            {
                while(stat != i)
                {
                    res.push_back(mp[ii(stat, trace[stat])]);

                    src[stat] = (src[stat] == '0') ? '1' : '0';
                    src[trace[stat]] = (src[trace[stat]] == '0') ? '1' : '0';

                    stat = trace[stat];
                }
            }
            else
            {
                printf("-1");
                return;
            }
        }
    }

    printf("%d\n", res.size());
    for(int x: res) printf("%d ", x);
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
