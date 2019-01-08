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
#define task "CONNECT"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)(1024)
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
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;
bool avail[maxinp];
vi adj[maxinp];
int m, n, res;
vi CComp;

//=====================================
//Functions and procedures
//Initialization
void FileInit()
{
    FILEOP();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}


//Enter
void Enter()
{
	int u, v;
	MEMS(avail, true);
	scanf("%d %d", &n, &m);
	FOR(i, 1, m)
	{
	    scanf("%d %d", &u, &v);
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
}

//BFS
int BFS(int start)
{
    qi que;
    int tmp = 0;
    que.push(start);
    avail[start] = false;

    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        ++tmp;
        for(int v: adj[u])
        {
            if(avail[v])
            {
                que.push(v);
                avail[v] = false;
            }
        }
    }

    return tmp;
}


//Process
void Solve()
{
    int cnt = 0;
    FOR(i, 1, n)
    {
        if(avail[i])
        {
            int x = BFS(i);
            CComp.push_back(x);
            ++cnt;
        }
    }
    if(cnt <= 1)
    {
        printf("%d", n);
    }
    else
    {
        sort(whole(CComp));
        res = CComp[cnt-1] + CComp[cnt - 2];
        printf("%d", res);
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
