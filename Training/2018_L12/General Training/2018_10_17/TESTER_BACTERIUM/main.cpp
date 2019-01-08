///                       Test Generator v1.00 by bu1th4nh                       ///
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
#include <cassert>
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


#include "test_lib.h"


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task "BACTERIUM"
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


#define ENABLE_DELAY


auto timeStart = chrono::steady_clock::now();
auto timeEnd   = chrono::steady_clock::now();


//==================================================
//Input and answer generating procedures
void Generate_input()
{
    ofstream test_inp(task".inp");

    int n = rand_int(10, 5);
    test_inp << n << el;
    FOR(i, 1, n) test_inp << rand_int(10, 0) << sp << rand_int(10, 0) << el;
}
void Generate_answer()
{
    ifstream test_inp(task".inp");
    ofstream test_ans(task".ans");

    int n, res = 0;
    test_inp >> n;
    vii a(n);

    for(auto &x: a) test_inp >> x.fi >> x.se;
    FORl(state, 1, (1 << n))
    {
        vii smp;
        ll sumA = 0LL, minB = 101010101LL;
        FORl(i, 0, n) if((state >> i) & 1 == 1) smp.push_back(a[i]);
        for(auto p: smp)
        {
            minB = min(minB, 1LL * p.se);
            sumA += p.fi;
        }

        if(minB * (ll)smp.size() <= sumA) res = max(res, (int)smp.size());
    }
    test_ans << res;
}

//==================================================
//Checker
void Checker()
{
    int T;
    cout << "How many fucking test do you want to generate? Enter your value here: "; cin >> T;

    FOR(iTest, 1, T)
    {
        cout << "Test #" << iTest << ":\n";


        Generate_input();
        cout << "Input generating completed\n";


        timeStart = chrono::steady_clock::now();
        Generate_answer();
        timeEnd   = chrono::steady_clock::now();
        cout << "Answer generating completed with elapsed time: " << chrono::duration<double>(timeEnd - timeStart).count() << " second(s)" << el;


        timeStart = chrono::steady_clock::now();
        system(task);
        timeEnd   = chrono::steady_clock::now();
        cout << "Sample program completed with elapsed time: " << chrono::duration<double>(timeEnd - timeStart).count() << " second(s)" << el;

        system("fc "task".out "task".ans");

        #ifdef ENABLE_DELAY
        getchar();
        #endif // ENABLE_DELAY
    }

}


//Main Procedure
int main()
{
    Checker();
    return 0;
}
