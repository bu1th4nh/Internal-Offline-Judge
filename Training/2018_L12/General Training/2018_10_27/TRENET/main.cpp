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

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#endif // __cplusplus

using namespace std;


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task "TRENET"
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


const long long inf = 123456789876545;
//=====================================
//Vertex declaration
struct data
{
    typedef long long ll;
    ll id, layer, offset;

    data() {}
    data(ll i)
    {
        id = i;

        ll tmp = floor(sqrt(id));
        if(tmp * tmp == id)
        {
            layer = tmp;
            offset = id - (tmp - 1) * (tmp - 1);
        }
        else
        {
            layer = tmp + 1;
            offset = id - (tmp) * (tmp);
        }

        //cerr << "ID layer and offset is: " << id << sp << layer << sp << offset << el;
    }

    vector<data> transform()
    {
        vector<data> ret;
        if(id == 1)
        {
            ret.push_back(data(3));
        }
        else if(offset == 1)
        {
            ret.push_back(data(id+1));
            ret.push_back(data(layer * layer + 2));
        }
        else if(layer * layer == id)
        {
            ret.push_back(data(id-1));
            ret.push_back(data((layer + 1) * (layer + 1) - 1));
        }
        else
        {
            ret.push_back(data(id-1));
            ret.push_back(data(id+1));
            if(layer & 1)
            {
                if(offset & 1) ret.push_back(data(id + layer * 2));
                else ret.push_back(data(id - (layer-1) * 2));
            }
            else
            {
                if(offset & 1) ret.push_back(data(id + layer * 2));
                else ret.push_back(data(id - (layer-1) * 2));
            }
        }
        return ret;
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef unordered_map<int, int> mii;
typedef unordered_map<int, ll> mill;
typedef pair<int, int> ii;
typedef vector<data> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef queue<data> qd;
typedef vector<vii> vvii;
data src, dst;
int n, m;
vll dist;
vi trace;
vb avail;
vi res;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    FILEOP_DEBUG()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
template<class T> inline void scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret *= (neg) ? -1 : 1;
}
template<class T> void print(T x)
{
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}


//Enter
void Enter()
{
    scan(n);
    scan(m);

    src = data(n);
    dst = data(m);

    dist = vll(262144*2, inf);
    trace = vi(262144*2, 0);
    avail = vb(262144*2, 1);
}

//Check
void BFS()
{
    qd que;

    dist[src.id] = 0;
    trace[src.id] = 0;
    avail[src.id] = 0;
    que.push(src);

    while(!que.empty())
    {
        data cur = que.front(); que.pop();

        if(cur.id == dst.id) break;

        vd nzxt = cur.transform();
        for(auto x: nzxt)
        {
            if(x.id <= 200000)
            {
                if(avail[x.id])
                {
                    que.push(x);
                    avail[x.id] = 0;

                    trace[x.id] = cur.id;
                    dist[x.id] = dist[cur.id] + 1;
                }
                else if(dist[x.id] > dist[cur.id] + 1)
                {
                    trace[x.id] = cur.id;
                    dist[x.id] = dist[cur.id] + 1;
                }
            }
        }
    }
}

//Process
void Solve()
{
    BFS();

    print(dist[dst.id]); putchar('\n');
    int p = dst.id;

    do
    {
        res.push_back(p);
        p = trace[p];
    }
    while(trace[p]);
    res.push_back(n);

    reverse(whole(res));
    for(auto x: res)
    {
        print(x);
        putchar('\n');
    }
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
