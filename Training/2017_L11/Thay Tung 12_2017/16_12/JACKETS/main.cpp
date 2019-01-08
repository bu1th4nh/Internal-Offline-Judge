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
#define task "JACKETS"
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
typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef set<int> sti;
viii events;
vvi fits, F;
int n, m;
vi res;

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
    int u, v;
    scanf("%d%d", &n, &m);

    events.reserve(n + 2*m);

    FORl(i, 0, n)
    {
        scanf("%d", &u);
        events.emplace_back(u, 0, i);
    }

    FORl(i, 0, m)
    {
        scanf("%d%d", &u, &v);
        events.emplace_back(u, -1, i);
        events.emplace_back(v, 1, i);
    }

    sort(whole(events));
}

//Process
void Solve()
{
    int x, type, id;
    sti cur_jacket;
    fits = vvi(n);

    for(auto ev: events)
    {
        tie(x, type, id) = ev;
        if(type == 0)
        {
            int cnt = 0;
            for(auto it: cur_jacket)
            {
                fits[id].pb(it);
                ++cnt;
                if(cnt == 3) break;
            }
        }
        else if(type == -1) cur_jacket.insert(id);
        else cur_jacket.erase(id);
    }


    F = vvi(n);

    FORl(i, 0, fits[0].size()) F[0].pb(0);

    FORl(i, 1, n)
    {
        FORl(j, 0, fits[i].size())
        {
            F[i].pb(-1);

            FORl(k, 0, fits[i-1].size()) if(F[i-1][k] != -1 && fits[i][j] != fits[i-1][k])
            {
                F[i][j] = k;
                break;
            }
        }
    }
//
//
//    puts("===============events================");
//    for(auto &e: events)
//    {
//        int x, y, z; tie(x, y, z) = e;
//        printf("%d°C - %d - ID: %d\n", x, y, z);
//    }
//    puts("=====================================");
//
//    puts("================fits=================");
//    for(vi x: fits)
//    {
//        for(int y: x) cout << y << " ";
//        puts("");
//    }
//    puts("=====================================");
//
//    cerr << ("=================dp==================\n");
//    for(vi x: F)
//    {
//        for(int y: x) cerr << y << " ";
//        cerr << "\n";
//    }
//    cerr << ("=====================================\n");

//    cerr << "Step 3 completed\n";
//


    for(int i = 0; i < F[n-1].size(); ++i)
    {
        if(F[n-1][i] == -1) continue;

        printf("Yes\n");

        res = vi(n);
        int cur = i;

        for(int pos = n - 1; pos >= 0; --pos)
        {
            res[pos] = fits[pos][cur];
            cur = F[pos][cur];
        }


        for(int r: res) printf("%d ", r + 1);
        return;
    }

    printf("No");
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
