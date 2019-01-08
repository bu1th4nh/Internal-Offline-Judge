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
#include <chrono>
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

//Check
void Checker()
{
    FOR(i, 0, 41)
    {
        stringstream ss, ss2;
        ss << i << ".in";
        ss2 << i << ".ans";

        string c1 = string("ren ") + ss.str() + string(" robot.inp");
        string c2 = string("fc ") + ss2.str() + string(" robot.out");
        string c3 = string("ren ") + string("robot.inp ") + ss.str();


        system(c1.c_str());

        auto timeStart = chrono::steady_clock::now();
        int ec = system("ROBOT.exe");
        auto timeEnd   = chrono::steady_clock::now();

        cerr << "Program completed with exit code " << ec << " with elapsed time: " << chrono::duration<double>(timeEnd - timeStart).count() << " second(s)" << el;

        ifstream fo("robot.out");
        ifstream an(ss2.str().c_str());

        ll a1, b1, a2, b2;

        fo >> a1 >> a2;
        an >> b1 >> b2;


        cout << "Test #" << i << ": ";
        if(a1==b1 && a2==b2) cout << "Correct!\n";
        else
        {
            cout << "Incorrect!:\n";
            cout << "************ Answer: ************" << el << b1 << sp << b2 << el;
            cout << "********* Your output: **********" << el << b1 << sp << b2 << el;
        }

        system(c3.c_str());
    }
}




//Main Procedure
int main()
{
    Checker();
    return 0;
}
