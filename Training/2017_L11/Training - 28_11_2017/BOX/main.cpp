/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
//=====================================
//Solution Explain
/*
	Giả sử ta đang xét đến a[i] và b[j]. 
	
	h_a[i] = a[1] + ... + a[i];
	h_b[i] = b[1] + ... + b[i];

	h0 = Chiều cao đã lấy của tủ a.
		Giả sử ta đang mở ngăn a[i], ta có 2TH: a[i+1] hoặc b[j] với điều kiện:
					b[1] + ... + b[j-1] > h_a[i]. 
	Giờ chỉ việc lấy max của 2TH thôi :3
*/

//=====================================
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
#define task ""
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
struct Data
{
	int id, h, type;
	Data(int __h, int __id, int __type)
	{
		h = __h, id = __id, type = __type;
	}
	bool operator < (const Data &other) const
	{
		return this->h < other.h;
	}
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef set<Data> sdt;
in t m, n;
vi a, b;
sdt st;

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

//Enter
void Enter()
{
	int h = 0, h2 = 0;
	scanf("%d%d", &m,  &n);
	FOR(i, 1, m)
	{
		scanf("%d", &u);
		h += u;
		a.pb(u);
	}

	FOR(i, 1, n)
	{
		scanf("%d", &u);
		h2 += u;
		b.pb(u);
	}
}

//Check





//Process




//Output





//Main Procedure
int main()
{
    //Your code goes here
    return 0;
}
