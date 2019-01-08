/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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


//=====================================
//Typedef
struct pack
{
    string s;
    int id;
    pack(const string & __s, const int & __id)
    {
        s = __s, id = __id;
    }
};
typedef long long ll;
typedef unsigned long long ull;
typedef map<string, int> msi;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef set<string> sstr;
string src, dst;
msi mp[2];

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

//Enter
void Enter()
{
    char s[32];
    scanf("%s", &s); src = string(s);
    scanf("%s", &s); dst = string(s);
}

//Check
void BFS(string t, int from)
{
    int n = t.length();
    queue<pack> q;
    mp[from][t] = 1;
    q.push(pack(t, 0));

    while(!q.empty())
    {
        string cur = q.front().s;
        int cur_id = q.front().id;
        q.pop();

        FORl(i, 1, n-1)
        {
            FORl(j, i, n-1)
            {
                string nxt = cur;
                int nxt_id = cur_id + 1;

                FOR(k, 0, (j - i) / 2) swap(nxt[i+k], nxt[j-k]);


                if(nxt_id <= 2 && Set[from].find(nxt) == Set[from].end())
                {
                    mp[from][nxt] = 1;
                    q.push(pack(nxt, nxt_id));
                }
            }
        }
    }
}

//Process
void Solve()
{
    BFS(src, 0);
    BFS(dst, 1);
    for(string t: Set[0]) if(Set[1].find(t) != Set[1].end())
    {
        cout << "Similar";
        return;
    }
    cout << "Different";
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
