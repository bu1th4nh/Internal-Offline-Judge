//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define task "OTOMAT"
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
typedef pair<int, char> ci;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ci> vci;
typedef bitset<8> bs;
int src_int, dst_int;
string __src, __dst;
bs src, dst;
vci trace;
vb avail;
vc res;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
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
	cin >> __src >> __dst;
	for(int i = 0, j = 7; i <= j; ++i, --j)
    {
        swap(__src[i], __src[j]);
        swap(__dst[i], __dst[j]);
    }
    src = bs(__src);
    dst = bs(__dst);
    src_int = src.to_ulong();
    dst_int = dst.to_ulong();
}

//Check
void Check567(bs & sample, int __pos)
{
    assert(__pos >= 5 && __pos <=7);
    sample.flip(__pos);
}

void Check34(bs & sample, int __pos)
{
    assert(__pos == 3 || __pos == 4);
    if(__pos == 3)
    {
        if(sample[3]) Check567(sample, 6);
        else Check567(sample, 5);
    }
    else
    {
        if(sample[4]) Check567(sample, 7);
        else Check567(sample, 6);
    }
    sample.flip(__pos);
}

void CheckABC(bs & sample, int __pos)
{
    assert(__pos >= 0 || __pos <= 2);
    if(__pos == 0)
    {
        if(sample[0]) Check34(sample, 3);
        else Check567(sample, 5);
    }
    else if(__pos == 1)
    {
        if(sample[1]) Check34(sample, 4);
        else Check34(sample, 3);
    }
    else
    {
        if(sample[2]) Check567(sample, 7);
        else Check34(sample, 4);
    }
    sample.flip(__pos);
}


bs TogglePlace(bs sample, int __n)
{
    bs tmp = sample;
    CheckABC(tmp, __n);
    return tmp;
}

//Process
void Init()
{
    trace = vci(257, ci(-1, '?'));
    avail = vb(257, true);
}

void BFS(bs start)
{
    queue<bs> que;
    que.push(start);
    avail[start.to_ulong()] = false;
    while(!que.empty())
    {
        bs cur = que.front();
        que.pop();

        FOR(i, 0, 2)
        {
            bs n3xt = TogglePlace(cur, i);
            if(avail[n3xt.to_ulong()])
            {
                que.push(n3xt);
                avail[n3xt.to_ulong()] = false;
                trace[n3xt.to_ulong()] = ci(cur.to_ulong(),   (char)((int)('A') + i)  );
            }
        }

    }
}

void Solve()
{
    Init();
    BFS(src);
    if(src_int == dst_int)
    {
        printf("AABBCC");
        return;
    }
    else if(trace[dst_int].fi == -1)
    {
        printf("NO");
        return;
    }
    else
    {
        while(src_int != dst_int)
        {
            res.push_back(trace[dst_int].se);
            dst_int = trace[dst_int].fi;
        }
        FORb(i, res.size()-1, 0)
        {
            cout << res[i];
        }
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
