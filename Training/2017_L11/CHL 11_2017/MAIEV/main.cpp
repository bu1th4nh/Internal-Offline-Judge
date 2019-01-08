/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "MAIEV"
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


//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
struct Data
{
    int x, y, mana, id;
    Data(int _x, int _y, int _mn, int _id)
    {
        x = _x, y = _y, mana = _mn, id = _id;
    }
    bool operator < (const Data &v) const
    {
        return ((x == v.x) ? y < v.y : x < v.x);
    }
};
vector<Data> vect;
int FX[131072], FY[131072], traceX[131072], traceY[300005], F[300005], trace[131072];
int n, d, tracer, sum, r2;
vi res;


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
    int u, v, c;
	scanf("%d%d", &n, &d);
	vect.push_back(Data(-123456789, -123456789, -1, -1));
	FOR(i, 1, n)
	{
	    scanf("%d%d%d", &u, &v, &c);
	    vect.push_back(Data(u, v, c, i));
	}
}


//Process
void Solve()
{
    sum = r2 = 0;
    sort(whole(vect));
    FOR(i, 1, n)
    {
        if(vect[i].id > 1 && max(FX[vect[i].x], FY[vect[i].y]) < d) F[i] = -1;
        else
        {
            if(FX[vect[i].x] > FY[vect[i].y])
            {
                F[i] = FX[vect[i].x] + vect[i].mana - d * ((vect[i].id == 1) ? 0 : 1);
                trace[i] = traceX[vect[i].x];
            }
            else
            {
                F[i] = FY[vect[i].y] + vect[i].mana - d * ((vect[i].id == 1) ? 0 : 1);
                trace[i] = traceY[vect[i].y];
            }
            if(F[i] > FX[vect[i].x])
            {
                FX[vect[i].x] = F[i];
                traceX[vect[i].x] = i;
            }
            if(F[i] > FY[vect[i].y])
            {
                FY[vect[i].y] = F[i];
                traceY[vect[i].y] = i;
            }
        }

        if(vect[i].id == n)
        {
            tracer = i;
            sum = F[i];
            break;
        }
    }


    while(tracer)
    {
        res.push_back(vect[tracer].id);
        tracer = trace[tracer];
    }
    reverse(whole(res));

    cout << sum << "\n" << res.size() << "\n";
    for(int i: res) printf("%d ", i);
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
