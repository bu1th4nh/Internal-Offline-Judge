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
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef queue<int> qi;
vi src, cand, num, trace, res;
string s;
vb avail;
int n;
qi q;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Check
void BFS()
{
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i: cand)
        {
            int nextval = (cur*10 + i) % n;
            if(nextval == 0)
            {
                trace[0] = cur;
                num[0] = i;
                return;
            }
            if(avail[nextval])
            {
                avail[nextval] = false;
                trace[nextval] = cur;
                num[nextval] = i;
                q.push(nextval);
            }
        }
    }
}

//Process
void Solve()
{
    for(char t: s)
    {
        int x = t - '0';
        if(x % n == 0)
        {
            cout << x << "\n";
            return;
        }
        if(avail[x % n])
        {
            q.push(x);
            cand.push_back(x);
            avail[x] = false;
            num[x % n] = x;
        }
    }

    BFS();

    if(trace[0] == -1)
    {
        cout << 0;
        return;
    }

    int tracer = 0;
    while(true)
    {
        res.push_back(num[tracer]);
        tracer = trace[tracer];
        if(tracer == 0) break;
    }

    reverse(whole(res));
    for(int i : res) cout << i;

}

//Main Procedure
int main()
{
	scanf("%d", &n);
	trace = num = vi(n, 0);
	avail = vb(n, true);

	cin >> s;

	Solve();
    return 0;
}
