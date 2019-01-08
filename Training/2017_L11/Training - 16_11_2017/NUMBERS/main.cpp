/*============================================================================================================\*\                                                                                                        ||
 *                                 _           _ _   _     _  _         _                                      ||
 *                                | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   ||
 *                                | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  ||
 *                                | |_) | |_| | | |_| | | |__   _| | | | | | |                                 ||
 *                                |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 ||
/*============================================================================================================/*/
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
#define task "NUMBERS"
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
string src, dst;


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
    getline(cin, src);
    getline(cin, dst);
}

//Process
void Solve()
{
    if(src.length() < dst.length() || (src.length() == dst.length() && src != dst))
    {
        printf("NO\n");
        return;
    }
    if(src == dst)
    {
        printf("YES\n");
        return;
    }

    int j = 0, t = 0;
    FORl(i, 0, src.length())
    {
        t = (t + int(src[i] - '0')) % 10;
        char x = t + '0';
        if(dst[j] == x && j < dst.length())
        {
            t = 0;
            ++j;
        }
    }

    if(j > dst.length()-1 && t == 0) printf("YES\n");
    else printf("NO\n");

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