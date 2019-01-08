/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/

//I very appreciate your problem statement ( ͡° ͜ʖ ͡°)


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
#define task "GOODS"
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
typedef pair<char, int> ci;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef stack<ci> stci;
string s;
ll res;
int n;
vi F;

//=====================================
//Functions and procedures
//Initialization and preparation
void LiveToday()
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
void LoveTomorrow()
{
    char str[1048576];
	scanf("%s", &str);
	s = '^' + string(str);
	n = (int)s.size() - 1;
	F = vi(n+1, 0LL);
}

//Process
void UniteForever()
{
    unordered_map<char, char> mp;
    stci st;

    mp[']'] = '[';
    mp['}'] = '{';
    mp[')'] = '(';

    if(n <= 1)
    {
        if(n == 1 && (s[1] == ']' || s[1] == '[' || s[1] == ')' || s[1] == '(' || s[1] == '{' || s[1] == '}')) puts("0");
        else puts("1");
    }

    res = 0LL;
    FOR(i, 1, n)
    {
        if(s[i] == ']' || s[i] == ')' || s[i] == '}')
        {
            if(!st.empty() && st.top().first == mp[s[i]])
            {
                F[i] = 1LL + F[st.top().second-1];
                //cerr << st.top().first << sp << st.top().second << el;
                st.pop();
            }
            else while(!st.empty()) st.pop();
        }
        else st.push(ci(s[i], i));

        res += 1LL * F[i];
    }

    //cout << accumulate(whole(F), 0LL);
    cout << res << el;
}



//Main Procedure
int main()
{
    LiveToday();
    LoveTomorrow();
    UniteForever();
    return 0;
}
