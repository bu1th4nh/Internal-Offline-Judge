/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Solution Briefing - Foreword
/*
        1. Solution: Use forest.

        2. Data Structure:
            * Base Information: A node contains:
                - node* next[26]
                - vector<int> ends      //Mark the end of words
                - Constructor:
                    next[i] = NULL w/a i

            * Auxiliary Data Structure
                - node *root = new node()
                - vector<int> st        //Maintain the index of ending words
                - bool isChild[N]
                - vector<pair<int, int>> res //Maintain the result
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
#include <tuple>
#include <vector>
#include <utility>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
#endif // __cplusplus

using namespace std;

// #define DEBUG
// #define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task "ACCOUNT"
#define maxinp ()
#define fi first
#define se second
#define pb push_back
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define r_whole(x) x.rbegin(),x.rend()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP()                        \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
    freopen(task".err", "w", stderr);   \
}

//Macroes - Optional
#ifdef OPTIONAL_FEATURE
    #define pc(x) putchar(x)
    #define gc() getchar()
#endif



//=====================================
//Auxilary Functions and Fast I/O
#ifdef OPTIONAL_FEATURE
    template<class T, class R> T max(T &x, R &y)
    {
        return x > y ? x : y;
    }
    template<class T, class R> T min(T &x, R &y)
    {
        return x < y ? x : y;
    }
    template<class T, class R> void maximize(T &x, R y)
    {
        x = x > y ? x : y;
    }
    template<class T, class R> void minimize(T &x, R y)
    {
        x = x < y ? x : y;
    }
    template<class T> int getBit(T &x, int i)
    {
        return ((x >> i) & 1) == 1;
    }
    template<class T> T __abs(T &x)
    {
        return (x = (x < 0) ? -x : x);
    }
#endif
//Fast I/O
template<class T> inline void scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret = (neg) ? -ret : ret;

    #ifdef DEBUG
        cerr << "FastScan Diagnostic: " << ret << el;
    #endif
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

//=====================================
//Constants



//=====================================
//Typedefs
//template<int MAX_CHARACTER> struct Trie
//{
    typedef pair<int, int> ii;
    typedef vector<bool> vb;
    typedef vector<int> vi;
    typedef vector<ii> vii;


    struct Node
    {
        Node* child[311];
        bool isLeaf;
        vi ends;                  //Contains id of string

        Node()
        {
            FOR(i, 0, 250) child[i] = NULL;
            ends = vi();
            isLeaf = 0;
        }
        ~Node()
        {
            FOR(i, 'a', 'z') if(child[i]) delete child[i];
        }
    };
    typedef Node* pnode;
    pnode root = new Node();


    pnode insert(string s, int i)
    {
        pnode n = root;
        for(char c: s)
        {
            if(n->child[c] == NULL)
            {
                n->child[c] = new Node();
            }
            n = n->child[c];
        }
        n->isLeaf = 1;
        n->ends.push_back(i);
        return n;
    }
    void DFS(pnode n, vi &st, vb &isChild, vii &res)
    {
        if(!n) return;

        for(int x: n->ends) st.push_back(x);
        FOR(i, 'a', 'z') if(n->child[i]) DFS(n->child[i], st, isChild, res);

        for(int x: n->ends) isChild[x] = 1;
        while(st.size() > 1 && isChild[st.back()])
        {
            int n1 = st.back(); st.pop_back();
            int n2 = st.back(); st.pop_back();
            res.push_back(ii(n2, n1));
        }

        if(st.size() == 1 && isChild[st.back()]) st.pop_back();
        for(int x: n->ends) isChild[x] = 0;
    }
    void operation(vi &st, vb &isChild, vii &res)
    {
        DFS(root, st, isChild, res);
    }


//    Trie()
//    {
//        root = new Node();
//    }
//    ~Trie()
//    {
//        delete root;
//    }
//};


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
//Trie<256> tree;
vb isChild;
vii res;
vi st;
int n;

//=====================================
//Functions and procedures
//File I/O and utilities
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    #ifdef DEBUG
        FILEOP_DEBUG()
    #else
        FILEOP()
    #endif
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}


//Enter
void Enter()
{
    char str[512000];
    scanf("%d", &n);

    isChild = vb(2*n+1, 0);
//    tree = Trie<256>();

    FOR(i, 1, 2*n)
    {
        scanf("%s", &str);
        insert(string(str), i);
    }
}

//Process
void Solve()
{
    operation(st, isChild, res);
    for(ii x: res) cout << x.fi << sp << x.se << el;
}


//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}

/*
2
abac
abacab
aba
abaa
*/

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
