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
#define task "RELATIVES"
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
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef bitset<10> bs;
typedef vector<int> vi;
typedef vector<bs> vbs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
vi BitOcc;
vs vect;
ll res;
int n;

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
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Enter
void Enter()
{
    scanf("%d", &n);

    BitOcc = vi(1024, 0);

    char t[16];
    FOR(i, 1, n)
    {
        scanf("%s", &t);
        vect.push_back(string(t));
    }

//    for(string x: vect) cout << x << " ";


}

//Process
void Solve()
{
    res = 0;
    FOR(i, 0, n-1)
    {
        bs bits;
        FOR(j, 0, vect[i].length()-1)
        {
            bits[ (int)((int)vect[i][j] - (int)'0') ] = true;
        }
        BitOcc[bits.to_ulong()]++;
    }

//    FOR(i, 0, 1023) if(BitOcc[i]) printf("%d %d\n", i, BitOcc[i]);

    FOR(i, 0, 1023)
    {
        FOR(j, i, 1023)
        {
            if((i & j) != 0)
            {
                res += (i != j) ? (1LL*BitOcc[i]*BitOcc[j]) : (1LL*BitOcc[i]*(BitOcc[i]-1)/2);
            }
        }
    }

    printf("%lld\n", res);
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
