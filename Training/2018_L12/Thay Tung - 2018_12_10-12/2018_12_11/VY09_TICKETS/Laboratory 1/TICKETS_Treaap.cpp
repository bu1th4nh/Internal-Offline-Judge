/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Solution Briefing - Foreword



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
#define task "TICKETS"
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
    freopen(task".out1", "w", stdout);   \
    freopen(task".err1", "w", stderr);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
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
//Treaps
mt19937_64 PRNG(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> die(0, 100000007);
template<class T, int INDEX_FROM = 0> class Treap
{
private:

    //Node implementation
    struct Node
    {
        T val;
        bool rev;
        Node *l, *r;
        int sz, priority;

        T min_value;
        T max_value;
        T gcd_value;
        T sum_value;
        T increment;

        Node(T __val = T())
        {
            sz = 1;
            rev = 0;
            l = r = 0;
            val = __val;
            min_value = __val;
            max_value = __val;
            gcd_value = __val;
            sum_value = __val;
            increment = T();
            priority = die(PRNG);
        }
        ~Node()
        {
            delete l;
            delete r;
        } 

        void push_down()
        {
            //Lazy Propagation Processing
            if(increment)
            {
                val += increment;
                sum_value += increment * sz;
                if(l) l->increment += increment;
                if(r) r->increment += increment;
                increment = T();
            }

            //Reverse Effect Processing
            if(rev)
            {
                if(l) l->rev ^= 1;
                if(r) r->rev ^= 1;
                swap(l, r);
                rev = 0;
            }
        }
        void update()
        {
            sz = 1;
            //push_down();
            min_value = max_value = gcd_value = sum_value = val;
            if(l)
            {
                //l->push_down();
                sz += l->sz;
                min_value = min(min_value, l->min_value);
                max_value = max(max_value, l->max_value);
                gcd_value = __gcd(gcd_value, l->gcd_value);
                sum_value += l->sum_value;
            }
            if(r)
            {
                //r->push_down();
                sz += r->sz;
                min_value = min(min_value, r->min_value);
                max_value = max(max_value, r->max_value);
                gcd_value = __gcd(gcd_value, r->gcd_value);
                sum_value += r->sum_value;
            }
        }
    };
    typedef Node* pnode; pnode root; //Root initialization
    int get_sz(pnode t) {return t ? t->sz : 0;}

    //Split and merge
    void split(pnode t, pnode &l, pnode &r, int pos)
    {
        if(!t) return void(l = r = NULL);
        t->push_down();
        if(get_sz(t->l) < pos)
        {
            split(t->r, t->r, r, pos - get_sz(t->l) - 1),
            l = t;
        }
        else
        {
            split(t->l, l, t->l, pos),
            r = t;
        }
        t->update();
    }
    pnode merge(pnode l, pnode r)
    {
        if((!l) || (!r)) return l ? l : r;

        l->push_down();
        r->push_down();
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
    void dfs(pnode n)
    {
        if(!n) return;
        n->push_down(); 
        if(n->l) dfs(n->l);
        cerr << n->val << sp;
        if(n->r) dfs(n->r);
    }


    //Helper Function
    T get_value(pnode t, int pos)
    {
        t->push_down();
        int lsz = get_sz(t->l);
        if(pos == lsz) return t->val;
        else return (pos < lsz) ? get_value(t->l, pos) : get_value(t->r, pos - lsz - 1);
    }
    

public:
    //Inorder traversal
    void show()
    {
        cerr << "\n-----------------\n";
        dfs(root);
        cerr << "\n-----------------\n";
    }
    //Insert a value to treap
    void insert(T x, int pos)
    {
        pnode l, r;
        split(root, l, r, pos);
        root = merge(merge(l, new Node(x)), r);
    }

    //Delete ``num`` element(s) from treap from position pos
    void erase(int pos, int num)
    {
        pnode L1, R1, L2, R2;
        split(root, L1, R1, pos);
        split(R1, L2, R2, num);
        root = merge(L1, R2);
        delete L2;
    }

    //get the i-th value of the array
    T operator[] (int id)
    {
        return get_value(root, id);
    }

    //Bring segment from l to r to front of the array
    void to_front(int l, int r)
    {
        pnode L1, R1, L2, R2;
        split(root, L1, R1, r+1);
        split(L1, L2, R2, l);
        root = merge(merge(R2, L2), R1);
    }
    
    //Cyclic shift
    void cyclic_shift(int l, int r, int k)
    {
        cerr << "CShift from " << l << " to " << r << " by " << k << el;

        int len = r - l;
        pnode T1, T2, T3, T4;
        if(k < 0) k = (len + k % len) % len;
        if(k > 0)
        {
            k %= len;
            split(root, T1, T2, l);
            split(T2, T2, T3, len - k);
            split(T3, T3, T4, k);

            cerr << "Debug: \n T1: ";
            dfs(T1);
            cerr << "\n-----\n T2: ";
            dfs(T2);
            cerr << "\n-----\n T3: ";
            dfs(T3);
            cerr << "\n-----\n T4: ";
            dfs(T4);
            cerr << "\n-----\n\n";

            root = merge(merge(merge(T1, T3), T2), T4);
        }
    }

    //Range Update/Query
    void increase(int l, int r, T val)
    {
        if(l > r) return;
        pnode L1, R1, L2, R2;
        split(root, L1, R1, l);
        split(R1, L2, R2, r-l+1);
        L2->increment = val;
        root = merge(merge(L1, L2), R2);
    }
    void extract_param(int l, int r, T &max_val, T &min_val, T &sum_val, T &gcd_val)
    {
        if(l > r) return;
        pnode L1, R1, L2, R2;
        split(root, L1, R1, l);
        split(R1, L2, R2, r-l+1);
        
        max_val = L2->max_value;
        min_val = L2->min_value;
        sum_val = L2->sum_value;
        gcd_val = L2->gcd_value;

        root = merge(merge(L1, L2), R2);
    }



    //Constructor and destructor
    Treap(const vector<T> &vect)
    {
        root = 0;
        for(T x: vect) root = merge(root, new Node(x));
    }
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
int n, s, q;


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
    FileInit();
    long long x, y, k, val, dmy;
    scan(n);
    scan(s);
    scan(q);

    Treap<long long> trp(vector<long long> (n+1, s));
    //trp.show();

    while(q--)
    {
        scan(x);
        scan(y);
        scan(k);


        trp.extract_param(x, y, dmy, val, dmy, dmy);

        //FOR(i, x, y) cerr << trp[i] << sp; cerr << el;
        cerr << val << el;

        if(val < k) {puts("0"); continue;}
        
        trp.increase(x, y-1, -k);
        puts("1");
    }

    //trp.show();

    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
