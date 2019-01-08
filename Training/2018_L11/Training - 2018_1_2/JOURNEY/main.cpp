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
string cmd;
int tx, ty;
bool ok(1);

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    scanf("%d%d", &tx, &ty);

    char str[1048576];
    scanf("%s", &str);
    cmd = string(str);
}

//Process
void Solve()
{
    int x = 0, y = 0, h = 0;
    for(char t: cmd)
    {
        switch (t)
        {
        case 'D': --y;
            break;
        case 'L': --x;
            break;
        case 'R': ++x;
            break;
        case 'U': ++y;
            break;
        case '?': ++h;
            break;
        }
    }

    int rem = abs(x - tx) + abs(y - ty);
    if(rem > h || ((rem - h) & 1))
    {
        printf("IMPOSSIBLE\n");
        ok = 0;
        return;
    }

    int sd = 0, su = 0, sl = 0, sr = 0;
    if(x < tx) sr = tx - x; else sl = x - tx;
    if(y < ty) su = ty - y; else sd = y - ty;

    h = h - (sr + sl + su + sd);

    sd = sd + h / 2;
    su = su + h / 2;

    string res;

    for(auto &i: cmd)
    {
        if(i == '?')
        {
            if(sd > 0)
            {
                i = 'D';
                --sd;
            }
            else if(sl > 0)
            {
                i = 'L';
                --sl;
            }
            else if(sr > 0)
            {
                i = 'R';
                --sr;
            }
            else
            {
                i = 'U';
                --su;
            }
        }
        putchar(i);
    }
}

void Test()
{
    cerr << "\n\n====================TEST====================\n";
    if(!ok) return;
    int x = 0, y = 0, h = 0;
    for(char t: cmd)
    {
        switch (t)
        {
        case 'D': --y;
            break;
        case 'L': --x;
            break;
        case 'R': ++x;
            break;
        case 'U': ++y;
            break;
        }

        cerr << x << " " << y << "\n";
    }

    if(x == tx && y == ty) cerr << "Correct!";
    else cerr << "Wrong!";
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    Test();
    return 0;
}
