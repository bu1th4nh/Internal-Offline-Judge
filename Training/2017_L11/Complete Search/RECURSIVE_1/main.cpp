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
#define task ""
#define fi first
#define se second
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
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
bool mark[26];
int m, sum;
int sol[6];

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP(task)
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
    cin >> m;
}

//Check
void Check()
{
    if(sum == m)
    {
        FOR(i, 1, 5) cout << sol[i] << " ";
        cout << endl;
    }
}
void Try(int i)
{
    FOR(j, 1, 25) if(mark[j])
    {
        sol[i] = j;
        sum += sol[i];
        mark[j] = false;
        if(i == 5) Check();
        else Try(i+1);
        mark[j] = true;
        sum -= sol[i];
    }
}

//Process
void Solve()
{
    sum = 0;
    MEMS(mark, true);
    Try(1);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
