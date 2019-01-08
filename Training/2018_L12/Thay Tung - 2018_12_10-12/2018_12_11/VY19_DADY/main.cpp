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
    This is an implementation for Treap with explicit key
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
#define task ""
#define maxinp ()
#define fi first
#define se second
#define pb push_back
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define r_whole(x) x.rbegin(),x.rend()
#define FOR(i, x, y) for(auto i=x; i<=y; ++i)
#define FORl(i, x, y) for(auto i=x; i<y; ++i)
#define FORb(i, x, y) for(auto i=x; i>=y; --i)
#define FORlb(i, x, y) for(auto i=x; i>y; --i)
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
//Overview - Treap with explicit key
/*
    * Author : - Noam, from CP Community - Original implementation.
               - bu1th4nh - Fork and implement
    * Status : Test Pending
*/
//=====================================
uniform_int_distribution<> die(0, 100000007);
mt19937_64 PRNG(chrono::steady_clock::now().time_since_epoch().count());
template<class T, class R = size_t> class Treap
{
    /*
        T: Class/Type for key/value
        R: Class/Type for size, priority
    */

private:
    struct Node
    {
        R sz;
        Node *l, *r;
        T val, priority;


        Node(T __val = T(), T __prior = T())
        {
            sz = 1;
            l = r = 0;
            val = __val;
            priority = __prior;
        }
        ~Node()
        {
            delete l;
            delete r;
        }

        void update()
        {
            sz = 1;
            if(l) sz += l->sz;
            if(r) sz += r->sz;
        }
    };
    typedef Node* pnode; pnode root;

    //Core function: Split and merge
    void split(pnode t, pnode &l, pnode &r, T key)
    {
        if(!t) return void(l = r = 0);
        else if(t->val < key)
        {
            split(t->r, t->r, r, key);
            l = t;
        }
        else
        {
            split(t->l, l, t->l, key);
            r = t;
        }
        t->update();
    }
    pnode merge(pnode l, pnode r)
    {
        if(!l || !r) return l ? l : r;
        if(l->priority > r->priority)
        {
            l->r = merge(l->r, r);
            l->update();
            return l;
        }
        else
        {
            r->l = merge(l, r->l);
            r->update();
            return r;
        }
    }

    //DFS, Inorder traversal
    void dfs(pnode n)
    {
        if(!n) return;
        if(n->l) dfs(n->l);
        cerr << n->val << el;
        if(n->r) dfs(n->r);
    }


public:

    //Inorder traversal
    void show()
    {
        cerr << "======================\n";
        dfs(root);
        cerr << "======================\n";
    }

    //Operations
    void insert(T key, T val)
    {
        pnode L1, R1;
        split(root, L1, R1, key);
        root = merge(merge(L1, new Node(key, val)), R1);
    }
    T get_ops(int y, int b)
    {
        pnode L1, R1, L2, R2;
        split(root, L1, R1, b);
        L2 = L1, R2 = R1;

        if(!R1 || R1->priority < -y)
        {
            root = merge(L2, R2);
            return -1;
        }

        T ret = R1->val;
        while(R1 && R1->val >= b)
        {
            R1 = R1->l;
            if(R1 && R1->val >= b && R1->priority >= -y) ret = R1->val;
        }
        root = merge(L2, R2);
        return ret;
    }

    //Constructor and destructor
    Treap()
    {
        root = 0;
    }
    ~Treap() {delete root;}

};


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
int n, nQuery;

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


//Main Procedure
int main()
{
    Treap<int> trp;

    char t;
    int x, y;
    scanf("%d%d", &n, &nQuery);
    while(nQuery--)
    {
        scanf("\n%c%d%d", &t, &x, &y);
        if(t == 'M')
        {
            trp.insert(y, -x);
        }
        else
        {
            cout << trp.get_ops(x, y) << el;
        }
    }
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
