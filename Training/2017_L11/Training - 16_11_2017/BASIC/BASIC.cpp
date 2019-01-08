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
#define task "BASIC"
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
//Typedef and constant declaration
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ull> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
const ll MODUL = (ll)(1000000000000037);    ///1e15 + 37

//=====================================
//Variables declaration
ll Power256[31];
vi divisor;
vll Hash;
string t;
int n;

//=====================================
//Functions and procedures
//Debug
void DEbug(const vll &x)
{
    puts("==============HASH==============");
    for(ull i: x) printf("%lld \n", i);
    puts("================================");
}
void DEbug(const int i = 0)
{
    puts("============POWER256============");
    FOR(k, 0, 30) printf("%lld \n", Power256[i]);
    puts("================================");
}
void DEbug(const vi &x)
{
    puts("============DIVISORS============");
    for(int i: x) cout << i << "\n";
    puts("================================");
}


//Enter
void Enter()
{
    cin >> t;
    n = t.length();

    //Power256 = vll(31, 0LL);
    Hash = vll(n+1, 0LL);
}

//Hashing
int CI(char t)
{
    return (int)(t - 'a');
}
void GetBase()
{
    Power256[0] = 1LL;
    FOR(i, 1, 30)
    {
        Power256[i] = ((ll)( (ll)(Power256[i-1]) * (ll)(256) *1LL)) % MODUL;
    }

    //DEbug(0);

}
void InitHash()
{
    ll res = 0;
    Hash[0] = Power256[ CI(t[0]) ];
    FORl(i, 1, n)
    {
        Hash[i] = (Hash[i-1] + Power256[ CI(t[i]) ]);
    }

    //DEbug(Hash);

}
ll GetHash(int _i, int _j)
{
    if(_i == 0) return Hash[_j];
    return Hash[_j] - Hash[_i-1];
}

//Preliminary Process
void GetDiv()
{
    FORb(i, n-1, 2)
    {
        if(n % i == 0) divisor.push_back(i);
    }

    //DEbug(divisor);

}
bool PreCheck()
{
    bool ok = true;
    FOR(i, 1, n-1)
    {
        ok = ok && (t[i] == t[0]);
        if(t[i] != t[0]) break;
    }
    return ok;
}

//Process
void Solve()
{
    if(PreCheck())
    {
        cout << t[0];
        return;
    }

    GetDiv();
    GetBase();
    InitHash();

    for(int x: divisor)
    {
        bool isBreak = false;
        int m = n / x;
        FOR(i, 1, x-1)
        {
            int l = i*m, r = i*m + m - 1;
            if(GetHash(l, r) != GetHash(0, m-1))
            {
                isBreak = true;
                break;
            }
        }
        if(isBreak) continue;
        else
        {
            FOR(i, 0, m-1)
            {
                printf("%c", t[i]);
            }
            return;
        }
    }

    printf("-1");

}

//Main Procedure
int main()
{
    FILEOP();
    Enter();
    Solve();
    return 0;
}
