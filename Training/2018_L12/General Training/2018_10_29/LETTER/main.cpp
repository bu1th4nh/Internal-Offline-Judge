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
#define task "LETTER"
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
typedef vector<vii> vvii;




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
bool check(int n)
{
    string s = to_string(n);
    int freq[256];
    for(char x: s) if(freq[x]) return 0;
    return 1;
}
bool check(string s)
{
    int freq[256];
    for(char x: s) if(freq[x]) return 0;
    return 1;
}
void trans(int n)
{
    bool neg = (n < 0);
    if(neg) n *= -1;

    string s = to_string(n);
    if(!neg)
    {
        char min_unused = '0';
        int freq[255];
        bool mrk = 0;

        for(char &c: s)
        {
            if(!freq[c])
            {
                freq[c] = 1;
            }
            else
            {
                if(!mrk)
                {
                    while(freq[c]) ++c;
                    mrk = 1;
                }
                else c = min_unused;

                freq[c] = 1;
            }

            FOR(ch, min_unused, '9') if(!freq[ch]) min_unused = ch;
        }
    }
}

//Process
void Solve()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        if(n > 987654321)
        {
            puts("0");
            continue;
        }
        if(check(n))
        {
            cout << n << el;
            continue;
        }
    }
}


//Main Procedure
int main()
{
    Solve();
    return 0;
}
