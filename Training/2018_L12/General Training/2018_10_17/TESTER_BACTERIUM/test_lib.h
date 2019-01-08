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
#include <chrono>
#include <random>
#endif // __cplusplus

using namespace std;


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define whole1(x) x.begin()+1, x.end()
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
//Randomizer Initialization
mt19937_64 GEN(chrono::steady_clock::now().time_since_epoch().count());


//=====================================
//Generating Utilities
int rand_int(int limit, int start = 0)
{
    uniform_int_distribution<> die(start, limit);
    return die(GEN);
}
string rand_str(int n, int CASE_SETTINGS = 0, int NUMBER_SETTINGS = 0)
{
    vector<char> __even ({'0', '2', '4', '6', '8'});
    vector<char> __odd  ({'1', '3', '5', '7', '9'});


    /*
            CASE_SETTINGS:
                -1: Don't use Latin letter
                0: Use lower-case only
                1: Use upper-case only
                2: Use all upper/lower-case Latin letter
            NUMBER_SETTINGS: From 0->9
                0: Don't use number
                1: Use all numbers
                2: Use even numbers
                3: Use odd numbers
    */

    vector<char> seed;

    string ret;
    FOR(i, 1, n)
    {
        seed.clear();
        switch(CASE_SETTINGS)
        {
            case 0: seed.push_back(char(rand_int('z', 'a')));
                    break;
            case 1: seed.push_back(char(rand_int('Z', 'A')));
                    break;
            case 2: seed.push_back(char(rand_int('z', 'a')));
                    seed.push_back(char(rand_int('Z', 'A')));
                    break;
            default: break;
        }
        switch (NUMBER_SETTINGS)
        {
            case 1: seed.push_back(char(rand_int('9', '0')));
                    break;
            case 2: random_shuffle(whole(__even));
                    seed.push_back(__even[1]);
                    break;
            case 3: random_shuffle(whole(__odd));
                    seed.push_back(__odd[1]);
                    break;
            default: break;
        }

        shuffle(whole(seed), GEN);
        ret += seed[0];
    }

    return ret;
}
string rand_BigInt(int NUMBER_LIMIT)
{
    string ret;
    int num = rand_int(NUMBER_LIMIT, 0);

    if(num == 0) ret += '0';
    ret += char('0' + rand_int(9, 1));
    FOR(i, 2, num) ret += char('0' + rand_int(9, 0));

    return ret;
}
string rand_double(int NUMBER_LIMIT, int FP_RND_LIMIT)
{
    string ret;
    int num    = rand_int(NUMBER_LIMIT, 0);
    int fp_rnd = rand_int(FP_RND_LIMIT, 0);

    if(num == 0) ret += '0';
    ret += char('0' + rand_int(9, 1));
    FOR(i, 2, num) ret += char('0' + rand_int(9, 0));

    ret += '.';
    if(fp_rnd == 0) ret += '0';
    FOR(i, 1, fp_rnd) ret += char('0' + rand_int(9, 0));

    return ret;
}
