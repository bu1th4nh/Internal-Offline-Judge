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
#define task "G9999"
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
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;
vvvvb F;
int tc;

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


//Preliminary Process
void PreProcess()
{
    F = vvvvb(14, vvvb(14, vvb(14, vb(14, 0))));

    FORb(i, 9, 0)
        FORb(j, 9, 0)
            FORb(k, 9, 0)
                FORb(l, 9, 0)
                {
                    int tmp = 0;
                    if(i+j+k+l == 36) continue;
                    FOR(ptr, 0, 3) tmp += F[i + ptr][j][k][l];
                    FOR(ptr, 0, 3) tmp += F[i][j + ptr][k][l];
                    FOR(ptr, 0, 3) tmp += F[i][j][k + ptr][l];
                    FOR(ptr, 0, 3) tmp += F[i][j][k][l + ptr];
                    F[i][j][k][l] = (tmp == 0);
                }

}
int _(char t) {return t - '0';}

//Main Procedure
int main()
{
    FileInit();
    PreProcess();

    char str[8];

    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%s", &str); string s(str);
        while(s.length() < 4) s += '0';
        printf("%s", (F[_(s[0])][_(s[1])][_(s[2])][_(s[3])])  ?  "Y" :  "N"  );
    }

    FileClose();
    return 0;
}
