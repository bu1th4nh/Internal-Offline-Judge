/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
/*
                                            #DP #PALINDROME
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
using namespace std;


//=====================================
//Macros
#define task "NEARLY"
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
typedef vector<vvb> vvvb;
typedef vector<vii> vvii;
vvvb valid;
string s;
int n;


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

//Process
void Solve(int n1)
{
    FOR(i, 1, n1)
        FOR(w1, 0, 1)
            FOR(w2, 0, 1)
            {
                if(i == 1)
                {
                    valid[i][w1][w2] = (s[w1] == s[n-1 - w2]);
                    continue;
                }
                FOR(nw1, 0, 1 - w1)
                {
                    FOR(nw2, 0, 1 - w2)
                    {
                        char c1 = (w1) ? s[i] : (nw1) ? s[i-2] : s[i-1];
                        char c2 = (w2) ? s[n-1 - i] : (nw2) ? s[(n-1) - (i-2)] : s[(n-1) - (i-1)];

                        if(c1 == c2) valid[i][w1][w2] = valid[i][w1][w2] || valid[i-1][nw1][nw2];
                    }
                }
            }
}



//Main Procedure
int main()
{
    FileInit();
    char str[1000000];
    scanf("%s", &str);
    s = string(str);

    n = s.length();
    if(n == 1) {printf("YES"); return 0;}

    valid = vvvb(n/2+5, vvb(2, vb(2, 0)));
    Solve(n/2);

    if(n & 1)
    {
        bool res = valid[n/2][0][0] | valid[n/2][1][0] | valid[n/2][0][1];
        printf("%s", (res) ? "YES" : "NO");
    }
    else
    {
        bool res = valid[n/2][0][0];
        printf("%s", (res) ? "YES" : "NO");
    }
    FileClose();
    return 0;
}
