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
#define task "FCANDLE"
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
int n, nTest;
vi a;

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
    scanf("%d", &n);
    a = vi(n);

    ll res = 0LL;
    int cnt = 0;

    cerr << "ID: \n";
    for(int &x: a) x = ++cnt, cerr << x << sp; cerr << el;
    cerr << "All configurations:\n";

    do
    {
        bool ok = 1;
        FORl(i, 0, n)
        {
            if((i+1) & 1)
            {
                if((i == 0 && a[i] > a[i+1]) || (i == n-1 && a[i] > a[i-1]) || (i > 0 && i < n-1 && (a[i] > a[i-1] || a[i] > a[i+1])))
                {
                    ok = 0;
                    break;
                }
            }
            else
            {
                if((i == n-1 && a[i] < a[i-1]) || (i > 0 && i < n-1 && (a[i] < a[i-1] || a[i] < a[i+1])))
                {
                    ok = 0;
                    break;
                }
            }
        }

        //if(ok) {for(auto x: a) cerr << x << sp; cerr << el;}

        res += ok;
        res %= 1000000000;
    }
    while(next_permutation(whole(a)));

    string s = to_string(res);
    while(s.size() < 9) s = '0' + s;
    cout << s << el;
}

//Check





//Process




//Output





//Main Procedure
int main()
{
    FileInit();
    cin >> nTest;
    while(nTest--) Enter();


    return 0;
}
