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
using namespace std;


//=====================================
//Macros
#define task "XH"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define sqr(x) x*x
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin()+1, x.end()-1
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


const double EPS = 1e-6;
//=====================================
//Typedef
struct Object
{
    int w, l, h;

    Object(int __w, int __l, int __h)       //Width - Length - Height, Length = 0 if the object is a cylinder
    {
        if(__l == 0)
        {
            w = (__w), h = (__h), l = 0;
        }
        else
        {
            h = (__h);
            l = max(__w, __l);
            w = min(__w, __l);
        }
    }


    bool operator < (const Object &other) const
    {
        if(this->l * other.l == 0)
        {
            double s1 = (this->l == 0) ? 1.0*3.1415926*sqr(this->w) : 1.0*this->l*this->w;
            double s2 = (other.l == 0) ? 1.0*3.1415926*sqr(other.w) : 1.0*other.l*other.w;

            return (s1 - s2 > EPS);
        }
        else return (1LL*this->l*this->w > 1LL*other.l*other.w);
    }
    bool CanPutOn(const Object &other) const
    {
        if(this->l == 0 && other.l == 0) return (this->w > other.w);
        else if(this->l != 0 && other.l != 0) return (this->w > other.w && this->l > other.l);
        else if(this->l == 0 && other.l != 0) return (1LL*sqr(this->w)*4 > 1LL*(1LL*sqr(other.w) + 1LL*sqr(other.l)));
        else return (this->w > 2*other.w);
    }
};


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<Object> vo;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, m;
vo vect;
vi F;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    vect.push_back(Object(1000000000, 1000000000, 0));
    int u, v, w;
    scanf("%d%d", &n, &m);
    FOR(i, 1, n)
    {
        scanf("%d%d%d", &u, &v, &w);
        vect.push_back(Object(u, v, w));
        vect.push_back(Object(u, w, v));
        vect.push_back(Object(v, w, u));
    }
    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        vect.push_back(Object(u, 0, v));
    }
    n = m + 3*n;
    vect.push_back(Object(1, -1, 0));
}


//Process
void Solve()
{
    sort(whole(vect));


    F = vi(n+2, 0LL);
    F[0] = vect[0].h;


    FOR(i, 1, n+1)
    {
        int jmax = 0;
        FOR(j, 0, i-1)
        {
            Object x = vect[i], y = vect[j];
            if(y.CanPutOn(x) && F[j] > F[jmax]) jmax = j;
        }
        F[i] = F[jmax] + vect[i].h;
    }


    printf("%lld\n", *max_element(whole(F)));
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
