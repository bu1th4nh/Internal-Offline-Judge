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
struct NODE
{
    int f, fi, fo, fio;
    NODE(int x, int y, int z, int t)
    {
        f = x;
        fi = y;
        fo = z;
        fio = t;
    }
    NODE()
    {
        f = 0;
        fi = 1;
        fo = -1;
        fio = -100000057;
    }
};
typedef stack<NODE> sn;
string s;
int res;
sn stck;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    cin >> s;
}


//Check
NODE Serial(NODE a, NODE b)
{
    NODE res;
    res.f = max(a.f + b.f    ,  a.fo + b.fi - 1);
    res.fi = max(a.fi + b.f  ,  a.fio + b.fi - 1);
    res.fo = max(a.f + b.fo  ,  a.fo + b.fio - 1);
    res.fio = max(a.fi + b.fo,  a.fio + b.fio -1);
    return res;
}

NODE Parallel(NODE a, NODE b)
{
    NODE res;
    res.f = a.f + b.f;
    res.fi = a.fi + b.fi - 1;
    res.fo = a.fo + b.fo - 1;
    res.fio = a.fio + b.fio - 2;
    return res;
}


//Process
void Process()
{
    res = -100000057;
    int lgth = len(s) - 1;
    FORb(i, lgth, 0)
    {
        NODE x;
        switch ((int)(s[i]))
        {
            case ((int)('g')):
            {
                x = NODE();
                break;
            }
            case ((int)('S')):
            {
                NODE g1 = stck.top(); stck.pop();
                NODE g2 = stck.top(); stck.pop();
                x = Serial(g1, g2);
                break;
            }
            case ((int)('P')):
            {
                NODE g1 = stck.top(); stck.pop();
                NODE g2 = stck.top(); stck.pop();
                x = Parallel(g1, g2);
                break;
            }
            //default: x = NODE();
        }
        stck.push(x);
    }

    NODE k = stck.top();

    res = max(res, k.f);
    res = max(res, k.fi);
    res = max(res, k.fo);
    res = max(res, k.fio);
    stck.pop();

    printf("%d", res);
}


int main()
{
    Enter();
    Process();
    return 0;
}
