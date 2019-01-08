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
#define task "SCHOOLS"
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
typedef map<string, int> msi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef set<string> ss;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int n, res1;
vs res2;
ss sstr;
msi mp;

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
    sstr.clear();
    mp.clear();

    string s = "", sample = "0123456789";

    scanf("%d", &n);
    cin.ignore(1);
    FOR(i, 1, n)
    {
        getline(cin, s);

        int p1 = s.find_first_of(sample);
        int p2 = s.find_last_of(sample);

        s = s.substr(p1, p2 - p1 + 1);

        if(s.length() != 0)
        {
            mp[s]++;
        }
    }
}

//Process
bool cmp(string _a, string _b)
{
    return (_a.size() < _b.size() || (_a.size() == _b.size() && _a < _b));
}
void Solve()
{
    res1 = 0;
    for(auto ptr = mp.begin(); ptr != mp.end(); ptr++)
    {
        if(ptr->second <= 5)
        {
            res2.push_back(ptr->first);
            ++res1;
        }
    }

    sort(whole(res2), cmp);

    printf("%d\n", res1);
    for(string t: res2)
    {
        printf("%s\n", t.c_str());
    }
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    FileClose();
    return 0;
}
