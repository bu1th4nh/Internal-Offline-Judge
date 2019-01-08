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
//BigInt Class
class BigInt
{

public:

    string val;
    bool IsNegative = false;

    BigInt(string t, bool Normalize = true)
    {

        val = t;
        if(val[0] == '-') IsNegative = true;
        if(Normalize)
        {
            if(val[0] == '-')
            {
                val.erase(0, 1);
            }
        }
    }
    BigInt(unsigned long long n)
    {
        if(n < 0)
        {
            IsNegative = true;
        }
        while(n > 0)
        {
            int t = n % 10;
            val = (char)(t + '0') + val;
            n /= 10;
        }
    }
    BigInt()
    {
        val = "";
        IsNegative = false;
    }


protected:

    BigInt Add(BigInt A, BigInt B)
    {
        string a = A.val;
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

    BigInt Subtract(BigInt A, BigInt B)
    {
        string a = A.val;
        string b = B.val;

        while(len(a)<len(b)) a = '0' + a;
        while(len(a)>len(b)) b = '0' + b;

        bool neg = (a < b);
        int borrow = 0;
        BigInt res;

        if(neg) swap(a, b);

        FORb(i, len(a)-1, 0)
        {
            int tmp = a[i] - b[i] - borrow;
            if(tmp<0)
            {
                tmp+=10;
                borrow = 1;
            }
            else borrow = 0;
            res.val = (char)(tmp + 48) + res.val;
        }

        while(len(res.val)>1 && res.val[0] == '0') res.val.erase(0, 1);

        if(neg) res.val = '-' + res.val;

        res.IsNegative = neg;

        return res;
    }
public:

    int compare(BigInt a, BigInt b)
    {
        while(len(a.val)<len(b.val)) a.val = '0' + a.val;
        while(len(a.val)>len(b.val)) b.val = '0' + b.val;
        if(a.val == b.val) return 0;
        if(a.val > b.val) return 1;
        return -1;
    }

    void Normalize(BigInt &A)
    {
        if(A.val[0] == '-')
        {
            A.IsNegative = true;
            A.val.erase(0, 1);
        }
    }

    BigInt operator+(const BigInt &other)
    {
        BigInt A = *this;
        BigInt B = other;
        BigInt res;
        Normalize(A);
        Normalize(B);
        if(A.IsNegative && B.IsNegative)
        {
            res = Add(A, B);
            res.IsNegative = true;
            res.val = '-' + res.val;
        }
        else if(A.IsNegative && !B.IsNegative)
        {
            res = Subtract(B, A);
        }
        else if(!A.IsNegative && B.IsNegative)
        {
            res = Subtract(A, B);
        }
        else
        {
            res = Add(A, B);
        }
        return res;
    }

    BigInt operator-(const BigInt &other)
    {
        BigInt A = *this;
        BigInt B = other;
        BigInt res;
        Normalize(A);
        Normalize(B);
        if(A.IsNegative && !B.IsNegative)
        {
            res = Add(A, B);
            res.IsNegative = true;
            res.val = '-' + res.val;
        }
        else if(A.IsNegative && B.IsNegative)
        {
            res = Subtract(B, A);
        }
        else if(!A.IsNegative && B.IsNegative)
        {
            res = Add(A, B);
        }
        else
        {
            res = Subtract(A, B);
        }
        return res;
    }

};

//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
BigInt a, b, c;
int type;
string s;


//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    cin >> a.val >> b.val >> c.val;
    string f[3] = {a.val, b.val, c.val};

    FOR(i, 0, 2)
    {
        for(char t: f[i]) if(t <= '0' || t >= '9')
        {
            type = i + 1;
            break;
        }
    }

    switch (type)
    {
    case 1:
        {
            BigInt res = c - b;
            FORl(i, 0, res.val.size()) if(a.val[i] != res.val[i])
            {
                cout << res.val[i];
                return 0;
            }
            break;
        }
    case 2:
        {
            BigInt res = c - a;
            FORl(i, 0, res.val.size()) if(b.val[i] != res.val[i])
            {
                cout << res.val[i];
                return 0;
            }
            break;
        }
    case 3:
        {
            BigInt res = a + b;
            FORl(i, 0, res.val.size()) if(c.val[i] != res.val[i])
            {
                cout << res.val[i];
                return 0;
            }
            break;
        }

    }


    return 0;
}
