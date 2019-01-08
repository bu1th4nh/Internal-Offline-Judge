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
#define task "ANAGRAM"
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


const long long base = 311;
const long long mod = 1000000037;
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef unordered_set<ll> mll;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vvi char_freq_1, char_freq_2;
vi pow_mod, hash_1, hash_2;
string s, t;
int n, m;
mll mp;

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
	cin >> s >> t;
	n = s.size();
	m = t.size();

    s = '.' + s;
    t = '.' + t;
    char_freq_1 = vvi(n+1, vi(30, 0));
    char_freq_2 = vvi(m+1, vi(30, 0));
	pow_mod = vi(32, 0LL);
    hash_1  = vi(n+3, 0LL);
    hash_2  = vi(m+3, 0LL);

    if(n > m)
    {
        swap(char_freq_1, char_freq_2);
        swap(hash_1, hash_2);
        swap(n, m);
        swap(s, t);
    }
}


//Process
void initHash()
{
    pow_mod[0] = 1LL;
    FOR(i, 0, 30) pow_mod[i] = (pow_mod[i-1] * base) % mod;

//    FOR(i, 1, n)
//    {
//        char_freq_1[i] = char_freq_1[i-1];
//        ++char_freq_1[i][s[i] - 'a' + 1];
//    }
//    FOR(i, 1, m)
//    {
//        char_freq_2[i] = char_freq_2[i-1];
//        ++char_freq_2[i][t[i] - 'a' + 1];
//    }


    FOR(i, 1, n)
    {
        hash_1[i] = (hash_1[i-1] + (pow_mod[s[i] - 'a' + 1]) % mod) % mod;
    }

    FOR(i, 1, m)
    {
        hash_2[i] = (hash_2[i-1] + (pow_mod[t[i] - 'a' + 1]) % mod) % mod;
    }


//    FOR(i, 1, n)
//    {
//        FOR(j, 'a', 'z') cerr << char_freq_1[i][j-'a'] << sp;
//        cerr << el;
//    }
//    FOR(i, 1, m)
//    {
//        FOR(j, 'a', 'z') cerr << char_freq_2[i][j-'a'] << sp;
//        cerr << el;
//    }

}
ll retrieveHash(int l, int r, const vi &hash_val)
{
//    cerr << (hash_val[r] - hash_val[l-1] + mod * mod) % mod << el;
    return  (hash_val[r] - hash_val[l-1] + mod * mod) % mod;
}
void Solve()
{
    initHash();

    FOR(i, 1, n)
    {
        FOR(j, i, n)
        {
            mp.insert(retrieveHash(i, j, hash_1));
        }
    }

    //cerr << el;

    int res = 0;
    FOR(i, 1, m)
    {
        FORb(j, m, i)
        {
            if(mp.find(retrieveHash(i, j, hash_2)) != mp.end()) res = max(res, j-i+1);
        }
    }

    cout << res << el;
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
