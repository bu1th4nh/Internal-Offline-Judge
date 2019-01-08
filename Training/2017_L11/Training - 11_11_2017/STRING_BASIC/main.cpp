//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
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
#define task "STRING_BASIC"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define MODUL (int)(1e9+57)
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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ull> vull;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
string s;
vull vect;

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
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Enter
void Enter()
{
    //printf("Please enter the input string:\n")
    getline(cin, s);
}

//Check
void SpaceNormalize(string &str)
{
    while(str.length() >= 1 && str[0] == ' ') str.erase(0, 1);
    while(str.length() >= 1 && str[str.length()-1] == ' ') str.erase(str.length()-1, 1);
    FORlb(i, str.length()-1, 0) if(str[i] == str[i-1] && str[i] == ' ') str.erase(i, 1);
}

void StrWithNumbersNormalize(string &str)
{
    FORb(i, str.length()-1, 0) if(str[i] > '9' || str[i] < '0') str[i] = ' ';
    SpaceNormalize(str);
}

int CountWords(string str)
{
    if(str.length() == 0) return 0;

    int res = 0;
    string fuck;
    stringstream fff(str);

    while(fff >> fuck) ++res;
    return res;
}

vull SeperateAndSort(string str)
{
    ull x;
    vull res;

    StrWithNumbersNormalize(str);

    stringstream ss(str);

    while(ss >> x)
    {
        res.push_back(x);
    }

    sort(whole(res));
    return res;
}

//Process
void Solve()
{
    string e1 = s, e2 = s, e3 = s;
    int res1 = CountWords(e1);
    vull res2 = SeperateAndSort(e2);
    SpaceNormalize(e3);

    printf("Answer for Exercise 1: %d\n", res1);
    printf("Answer for Exercise 2: ", res1);
    for(ull x: res2) printf("%lld ", x); puts("");

    printf("Answer for Exercise 3: %s\n", e3.c_str());
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
