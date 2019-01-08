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
#define maxvalueinp (int)()
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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n, a, b, res;
vii vect;
vi peach;

//=====================================
//Functions and procedures
//Input
void Input()
{
    vect.push_back(ii(-1, -1));
    scanf("%d%d%d", &n, &a, &b);
    FOR(i, 1, n)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        vect.push_back(ii(x, y));
    }
}

//Check
bool cmp(int x, int y)
{
    return x > y;
}

//Process
void Process()
{
    res = 0;
    make_heap(whole(peach), cmp);
    int cnt = 1;
    FORl(i, a, b)
    {
        while(vect[cnt].first <= i)
        {
            peach.push_back(vect[cnt].second);
            push_heap(whole(peach));
            ++cnt;
        }
        res += peach.front();
        pop_heap(whole(peach));
    }
    printf("%d", res);
}

//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
