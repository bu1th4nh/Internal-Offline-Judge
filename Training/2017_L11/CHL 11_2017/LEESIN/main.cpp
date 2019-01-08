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
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "LEESIN"
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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
struct Data
{
    int next[4];
    int x, y, pos, id, cr1, cr2;
    Data(int _x, int _y, int _id)
    {
        next[0] = next[1] = next[2] = next[3]  = -1;
        x = _x, y = _y, id = _id;
        cr1 = x + y, cr2 = x - y;
    }
};
vector<Data> vect;
string cmd;
int n, k;
vi srt;

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
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Enter
void Enter()
{
    char str[1000001];
    int u, v;

    scanf("%d%d", &n, &k);
    scanf("%s", &str);
    cmd = string(str);

    FOR(i, 0, n-1)
    {
        scanf("%d%d", &u, &v);
        vect.push_back(Data(u, v, i));
        srt.push_back(i);
    }

}


//Process
bool cmp_BC(int a, int b)
{
    return (vect[a].cr1 != vect[b].cr1) ? vect[a].cr1 < vect[b].cr1 : vect[a].cr2 < vect[b].cr2;
}
bool cmp_AD(int a, int b)
{
    return (vect[a].cr2 != vect[b].cr2) ? vect[a].cr2 < vect[b].cr2 : vect[a].cr1 < vect[b].cr1;
}

void Solve()
{
    sort(whole(srt), cmp_BC);
    FORl(i, 1, n)
    {
        if(vect[srt[i-1]].cr1 == vect[srt[i]].cr1)
        {
            vect[srt[i-1]].next[1] = srt[i];
            vect[srt[i]].next[2] = srt[i-1];
        }
    }


    sort(whole(srt), cmp_AD);
    FORl(i, 1, n)
    {
        if(vect[srt[i-1]].cr2 == vect[srt[i]].cr2)
        {
            vect[srt[i-1]].next[0] = srt[i];
            vect[srt[i]].next[3] = srt[i-1];
        }
    }

    int ptr = 0;
    for(char t: cmd)
    {
        int _next = vect[ptr].next[t - 'A'];
        if(_next == -1) continue;

        FOR(j, 0, 3)
        {
            if(vect[ptr].next[j] != -1)
            {
                vect[vect[ptr].next[j]].next[3 - j] = vect[ptr].next[3 - j];
            }
        }
        ptr = _next;
    }

    printf("%d %d", vect[ptr].x, vect[ptr].y);
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

