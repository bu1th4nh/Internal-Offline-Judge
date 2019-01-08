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
#define FILEOP() {freopen(task".inp", "r", stdin);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
map<string, int> mp;

vi na, nb;
int m, n;
vs a, b;
int k;

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

int main()
{
    //FileInit();
    cout << "Enter the quantity of chromosome possibilities for male and female gametes: ";
    cin >> m >> n;

    a = vs(m+1);
    b = vs(n+1);

    na = vi(m+1, 0);
    nb = vi(n+1, 0);

    cout << "Enter all chromosome possibilities for male gametes: " << el;
    FOR(i, 1, m)
    {
        cin >> a[i] >> na[i];
    }

    cout << "Enter all chromosome possibilities for female gametes: " << el;
    FOR(i, 1, n)
    {
        cin >> b[i] >> nb[i];
    }

    k = accumulate(whole(na), 0) * accumulate(whole(nb), 0);

    cout <<  el << "Table: All F1 types with corresponding probability: \n";
    cout << "|"; FOR(j, 1, m) cout << "=====================|"; cout << el;

    FOR(i, 1, n)
    {
        cout << "|  ";
        FOR(j, 1, m)
        {
            string smp = a[j] + b[i];
            sort(whole(smp));
            while(smp.size() < 10) smp += ' ';
            mp[smp] += na[j] * nb[i];


            cout << smp << " - " << na[j] * nb[i] << "/" << k <<  "  |  ";
        }

        cout << el;
        cout << "|"; FOR(j, 1, m) cout << "=====================|"; cout << el;
    }

    cerr << el << "Numbers of gene types: " << mp.size() << el << el;

    cerr << "All chromosome with corresponding rate: \n";
    for(auto x: mp)
    {
        cout << x.fi << sp << sp << "with rate:  " << x.se << " / " << k << el;
    }

    cout << "\nCode by bu1th4nh - github.com/bu1th4nh" << el;

    return 0;
}
