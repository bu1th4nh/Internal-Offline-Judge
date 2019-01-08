//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "data"
#define maxvalueinp (int)()
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================


class BigInt
{
public:
    string val;

    BigInt(string t)
    {
        val = t;
    }
    BigInt()
    {
        val = "";
    }

    int compare(BigInt a, BigInt b)
    {
        while(len(a.val)<len(b.val)) a.val = '0' + a.val;
        while(len(a.val)>len(b.val)) b.val = '0' + b.val;
        if(a.val == b.val) return 0;
        if(a.val > b.val) return 1;
        return -1;
    }

    BigInt operator+ (const BigInt& B)
    {
        string a = this->val;
        string b = B.val;
        int carry = 0;
        BigInt res;

        while(len(a)<len(b)) a = '0' + a;
        while(len(a)>len(b)) b = '0' + b;

        FORb(i, len(a)-1, 0)
        {
            int tmp = a[i] + b[i] - 96 + carry;
            carry = tmp/10;
            tmp = tmp%10;
            res.val = (char)(tmp + 48) + res.val;
        }

        if (carry > 0) res.val = '1' + res.val;
        return res;
    }


};

//=====================================
//Typedef
vector<BigInt> vect;
stack<BigInt> stck;
int cnt;
BigInt n;

//=====================================
//Functions and procedures
void FileInit()
{
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
}
int main()
{

    FileInit();

    /*
    while(stdin)
    {
        char t;
        cin >> t;
        n.val = n.val + t;
    }
    */

    cin >> n.val;


    cout << n.val.length() << endl;

    vect.push_back(BigInt("1"));
    vect.push_back(BigInt("1"));
    cnt = 1;
    while(n.compare(vect[cnt], n) == -1)
    {
        vect.push_back(vect[cnt] + vect[cnt-1]);
        ++cnt;
    }

    BigInt sum;
    FORb(i, cnt, 0)
    {
        stck.push(vect[i]);
        if(sum.compare(sum + stck.top(), n) == 1)
        {
            stck.pop();
        }
        else
        {
            sum = sum + stck.top();
        }
    }

    cout << stck.size() << endl;

    assert(!stck.empty());

    cout << " = ";
    while(stck.size()>1)
    {
        cout << stck.top().val << " + ";
        stck.pop();
    }
    cout << stck.top().val;
    stck.pop();

    return 0;
}
