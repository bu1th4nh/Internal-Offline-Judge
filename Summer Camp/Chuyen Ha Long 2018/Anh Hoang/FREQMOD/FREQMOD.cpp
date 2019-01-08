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
const int maxn = 100000;
static int LP[maxn+1];
vector<int> prime;

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

//=====================================
//Typedef
void Sieve()
{
    FOR(i, 2, maxn)
    {
        if(LP[i] == 0)
        {
            LP[i] = i;
            prime.push_back(i);
        }
        for(int j = 0; j<(int)(prime.size()) && prime[j]<=LP[i] && i*prime[j]<=maxn; ++j)
        {
            LP[i*prime[j]] = prime[j];
        }
    }

    //cerr << prime.size() << sp << prime[0];
}

//Fast IO
inline int ReadInt()
{
    char b;
    for (b = getchar(); b < '0' || b > '9'; b = getchar());
    int res = b - '0';
    for (b = getchar(); b >= '0' && b <= '9'; b = getchar())
        res = res * 10 + b - '0';
    return res;
}
void WriteInt(ll x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

//Main Procedure
int main()
{
    int a[10001];

    Sieve();
    int T;
    T = ReadInt();
    while(T--)
    {
        int n, res = 0;
        int minva = 1234568970;
        n = ReadInt();


        FOR(i, 1, n)
        {
            //a[i] = ReadInt();

            scanf("%d", &a[i]);
        }

        int cnt = 0;

        for(int x: prime)
        {
            unordered_map<int, int> UZI;
            FOR(i, 1, n) res = max(res, ++UZI[a[i] % x]), ++cnt;

            if(cnt >= 1000000) break;
        }
        WriteInt(res); putchar('\n');
    }

    return 0;
}
