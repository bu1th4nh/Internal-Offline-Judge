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
#define task "CHANGEWK"
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
typedef map<char, int> mci;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int mp[26];
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

//Main Procedure
int main()
{
    FileInit();

    char str[32], chg;
    scanf("%s", &str);
    string s(str);
    n = s.length();

    for(auto &c: s) ++mp[c - 'a'];
    FOR(i, 0, 25) if(mp['a' + i] == 0)
    {
        chg = 'a' + i;
        break;
    }

    FORl(i, 2, n)
    {
        if(s[i-2] == s[i-1] && s[i-1] == s[i])
        {
            --mp[s[i] - 'a'];
            s[i] = chg;
            ++mp[chg - 'a'];
        }
    }

    FORl(i, 0, n)
    {
        char c = s[i];
        int minV = 1e5;
        if(mp[s[i] - 97] > n/2)
        {
            FOR(j, 0, 25)
            {
                if(mp[j] < minV) minV = mp[j], chg = j + 97;
            }
            s[i] = chg;
            --mp[c - 'a'];
            ++mp[chg  - 'a'];
        }
    }

    printf("%s\n", s.c_str());

    FileClose();

    return 0;
}
