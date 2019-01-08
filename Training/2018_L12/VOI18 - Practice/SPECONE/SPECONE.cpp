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
#define task "SPECONE"
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
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;


typedef pair<string, string> pss;
typedef map<string, int> mp_str_int;
typedef map<int, string> mp_int_str;
typedef set<ii> sii;

typedef vector<pss> vpss;
typedef vector<string> vs;


//Raw Data - Level 0 Data
int n, m, contd, n_fame;
vpss raw_contact_list;
vs raw_fame_list;

//Level 1 Data
mp_str_int student_list;         //Name ---> ID
mp_int_str student_name;         //ID ---> Name


//Level 2 Data
vii final_edge_list;
vi final_fame_list;

//Level 3 Data
vi ct_from_fame;
vb is_famous;
vvi adj;

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

//Enter
void Enter()
{
    char name[64];

	scanf("%d%d%d%d", &n, &contd, &n_fame, &m);

	raw_contact_list = vpss(m);
	raw_fame_list = vs(n_fame);

	ct_from_fame = vi(n+1, 0);
	is_famous = vb(n+1, 0);
	adj = vvi(n+1);

	for(auto &x: raw_fame_list)
    {
        scanf("%s", &name);
        x = string(name);
    }
    for(auto &x: raw_contact_list)
    {
        scanf("%s", &name);
        x.fi = string(name);
        scanf("%s", &name);
        x.se = string(name);
    }
}

//Preparation
void generate_sid()
{
    int id = 0;
    for(auto x: raw_fame_list)
    {
        if(student_list[x] == 0)
        {
            student_list[x] = ++id;
            student_name[id] = x;
        }
    }
    for(auto x: raw_contact_list)
    {
        if(student_list[x.fi] == 0)
        {
            student_list[x.fi] = ++id;
            student_name[id] = x.fi;
        }

        if(student_list[x.se] == 0)
        {
            student_list[x.se] = ++id;
            student_name[id] = x.se;
        }
    }
}
void generate_graph()
{
    sii filter;
    for(auto x: raw_fame_list) final_fame_list.push_back(student_list[x]);
    for(auto x: raw_contact_list)
    {
        int u = student_list[x.fi];
        int v = student_list[x.se];

        if(u > v) swap(u, v);
        filter.insert(ii(u, v));
    }
    final_edge_list = vii(whole(filter));

    for(ii x: final_edge_list)
    {
        adj[x.fi].push_back(x.se);
        adj[x.se].push_back(x.fi);
    }
}

//Process
void BFS()
{
    queue<int> que;
    int u, v;

    for(auto x: final_fame_list) is_famous[x] = 1, que.push(x);
    while(!que.empty())
    {
        u = que.front(); que.pop();

        for(int v: adj[u])
        {
            ++ct_from_fame[v];
            if((!is_famous[v]) && ct_from_fame[v] >= contd)
            {
                que.push(v);
                is_famous[v] = 1;
            }
        }
    }
}


//Output
void Preps()
{
    generate_sid();
    generate_graph();
}
void Solve()
{
    vs res;

    BFS();
    FOR(i, 1, n) if(is_famous[i]) res.push_back(student_name[i]);
    sort(whole(res));

    printf("%d\n", (int)res.size());
    for(auto x: res) printf("%s ", x.c_str());
}

//Debug
//#define DEBUG
void debug()
{
    #ifdef DEBUG

            for(auto x: raw_fame_list) cerr << student_list[x] << sp; cerr << el;
            for(auto x: raw_contact_list) cerr << student_list[x.fi] << sp << student_list[x.se] << el; cerr << el;

            FOR(i, 1, student_list.size()) cerr << student_name[i] << el; cerr << el;

    #endif // DEBUG
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Preps();

    debug();

    Solve();
    return 0;
}
