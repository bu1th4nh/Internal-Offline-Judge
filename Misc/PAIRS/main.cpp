//Libraries and namespaces
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp ()
#define MODUL (int)(10e9+57)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define whole(x) x.begin(), x.end()
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef pair<int, int> p2i;
typedef vector<p2i> vp;
vp point;
int res;
int n;


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
int Comb2(int x)
{
    return ((x*(x-1))/2);
}

//Input
void Input()
{
    cin >> n;
    FORi(1, n)
    {
        p2i x;
        cin >> x.first >> x.second;
        point.push_back(x);
    }
}

//Check and compare
bool cmpX(p2i a, p2i b)
{
    return a.first <= b.first;
}
bool cmpY(p2i a, p2i b)
{
    return a.second <= b.second;
}
bool cmp(p2i a, p2i b)
{
    return a <= b;
}

//Process
void Process()
{
    int pe, pd, first, last;
    res = 0;

    //Calculate X
    sort(whole(point), cmpX);
    FORli(0, n) cout << point[i].first << " " << point[i].second << endl;  //Debug
    pe = 0, pd = 0;
    while(pe < n-1)
    {
        ++pe;
        if(point[pe].first != point[pd].first)
        {
            first = pd;
            last = pe - 1;
            res += Comb2(last - first + 1);
            pd = pe;
        }
    }
    first = pd;
    last = pe - 1;
    res += Comb2(last - first + 1);

    //Calculate Y
    sort(whole(point), cmpY);
    FORli(0, n) cout << point[i].first << " " << point[i].second << endl;  //Debug
    pe = 0, pd = 0;
    while(pe < n-1)
    {
        ++pe;
        if(point[pe].second != point[pd].second)
        {
            first = pd;
            last = pe - 1;
            res += Comb2(last - first + 1);
            pd = pe;
        }
    }
    first = pd;
    last = pe - 1;
    res += Comb2(last - first + 1);

    //Duplicate elimination
    sort(whole(point), cmp);
    FORli(0, n) cout << point[i].first << " " << point[i].second << endl;  //Debug
    pe = 0, pd = 0;
    while(pe < n-1)
    {
        ++pe;
        if(point[pe] != point[pd])
        {
            first = pd;
            last = pe - 1;
            res -= Comb2(last - first + 1);
            pd = pe;
        }
    }
    first = pd;
    last = pe - 1;
    res -= Comb2(last - first + 1);

    cout << res;
}



//Output





//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
