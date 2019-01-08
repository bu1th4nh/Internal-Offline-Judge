//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(1000001)
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef queue<int> qi;
int F[maxvalueinp];
string s;
qi que;
int n;

//=====================================
//Functions and procedures
//Input
void Input()
{
    scanf("%d", &n);
    cin >> s;
    sort(whole(s));
    MEMS(F, -1);
}


//Breath-first Search
void BFS()
{
    FORl(i, 0, len(s))
    {
        que.push((int)(s[i]) - 48);
    }
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        if(F[u%n] == -1)
        {
            F[u%n] = u;
            FORl(i, 0, len(s))
            {
                int x = s[i] - '0';
                que.push(u*10 + x);
            }
        }
    }
    if(F[0] == -1) printf("0");
    else printf("%d", F[0]);
}

//Main Procedure
int main()
{
    Input();
    BFS();
    return 0;
}
