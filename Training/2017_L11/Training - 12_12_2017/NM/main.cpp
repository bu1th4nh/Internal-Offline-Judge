/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
//=====================================
//Solution
/*
        F[i][j]: Numbers of numbers that have i numbers <= 10 and sum = j.
        F[i][j] = F[i-1][j] + F[i-1][j-1] + ... + F[i-1][j-9]. - Big Integers
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
#define task "NM"
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
//Big Integers
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

    BigInt Multi(BigInt A, BigInt B)
    {
        BigInt res;
        int n = len(A.val), m = len(B.val);
        int len1 = n+m-1;
        int carry = 0;
        FORb(i, len1, 0)
        {
            int tmp = 0;
            FORb(j, n-1, 0)
            {
                if(i-j<=m && i-j>=1)
                {
                    tmp += (A.val[j]-48) * (B.val[i-j-1]-48);
                }
            }
            tmp += carry;
            carry = tmp/10;
            res.val = (char)(tmp%10 + 48) + res.val;
        }
        while(len(res.val)>1 && res.val[0] == '0') res.val.erase(0, 1);
        return res;
    }

    BigInt Divide(BigInt A, BigInt B)
    {
        BigInt a = A;
        BigInt b = B;
        BigInt res, tmp;
        BigInt kb[11];

        kb[0].val = "0";
        FOR(i, 1, 10)
        {
            kb[i] = Add(b, kb[i-1]);
        }
        FORl(i, 0, len(a.val))
        {
            int k = 1;
            tmp.val = tmp.val + a.val[i];
            while(BigInt::compare(tmp, kb[k]) != -1) ++k;
            res.val = res.val + (char)(k-1+48);
            tmp = Subtract(tmp, kb[k-1]);
        }
        while (len(res.val) > 1 && res.val[0] == '0') res.val.erase(0, 1);
        return res;
    }

    BigInt Mod(BigInt A, BigInt B)
    {
        BigInt a = A;
        BigInt b = B;
        BigInt tmp;
        BigInt kb[11];

        kb[0].val = "0";
        FOR(i, 1, 10)
        {
            kb[i] = Add(b, kb[i-1]);
        }
        FORl(i, 0, len(a.val))
        {
            int k = 1;
            tmp.val = tmp.val + a.val[i];
            while(BigInt::compare(tmp, kb[k]) != -1) ++k;
            tmp = Subtract(tmp, kb[k-1]);
        }
        return tmp;
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

    BigInt operator*(const BigInt &other)
    {
        BigInt A = *this;
        BigInt B = other;
        BigInt res;
        Normalize(A);
        Normalize(B);
        if(compare(A, BigInt("0")) == 0 || compare(B, BigInt("0")) == 0) return BigInt("0");
        if(A.IsNegative != B.IsNegative)
        {
            res = Multi(A, B);
            res.val = '-' + res.val;
            res.IsNegative = true;
        }
        else
        {
            res = Multi(A, B);
        }
        return res;
    }

    BigInt operator/(const BigInt &other)
    {
        BigInt A = *this;
        BigInt B = other;
        BigInt res;
        if(compare(A, BigInt("0")) == 0 || compare(B, BigInt("0")) == 0) return BigInt("0");
        Normalize(A);
        Normalize(B);
        if(A.IsNegative != B.IsNegative)
        {
            res = Divide(A, B);
            res.val = '-' + res.val;
            res.IsNegative = true;
        }
        else
        {
            res = Divide(A, B);
        }
        return res;
    }

    BigInt operator%(const BigInt &other)
    {
        BigInt A = *this;
        BigInt B = other;
        BigInt res;
        if(compare(A, BigInt("0")) == 0 || compare(B, BigInt("0")) == 0) return BigInt("0");
        Normalize(A);
        Normalize(B);
        if(A.IsNegative != B.IsNegative)
        {
            res = Mod(A, B);
            res.val = '-' + res.val;
            res.IsNegative = true;
        }
        else
        {
            res = Mod(A, B);
        }
        return res;
    }

    BigInt& operator+= (const BigInt& B)
    {
        *this = *this + B;
        return *this;
    }

    BigInt& operator-= (const BigInt& B)
    {
        *this = *this - B;
        return *this;
    }

    BigInt& operator*= (const BigInt& B)
    {
        *this = *this * B;
        return *this;
    }

    BigInt& operator/= (const BigInt& B)
    {
        *this = *this / B;
        return *this;
    }

    BigInt& operator%= (const BigInt& B)
    {
        *this = *this % B;
        return *this;
    }

    BigInt& operator++()
    {
        BigInt res = *this;
        res = res + BigInt("1");
        *this = res;
        return *this;
    }

    BigInt& operator++(int t)
    {
        BigInt res = *this + BigInt("1");
        return res;
    }

    BigInt& operator--()
    {
        BigInt res = *this;
        res = res - BigInt("1");
        *this = res;
        return *this;
    }

    BigInt& operator--(int t)
    {
        BigInt res = *this - BigInt("1");
        return res;
    }


};

//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<BigInt> vbi;
typedef vector<vbi> vvbi;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int tc, n, m;
vvbi F;

//=====================================
//Functions and procedures
//Initialization and preparation
void PreSolve()
{
    F = vvbi(128, vbi(128, BigInt("0")));
	F[0][0] = BigInt("1");


	FOR(i, 1, 120)
    {
        FOR(j, 1, 120)
        {
            FOR(k, 0, 9)
            {
                if(j - k >= 0) F[i][j] += F[i-1][j-k];
            }
        }
    }

//    FOR(i, 0, 120)
//    {
//        FOR(j, 0, 120)
//        {
//            cout << F[i][j].val << " ";
//        }
//        puts("");
//    }
}

void Solve()
{
    scanf("%d%d", &n, &m);

    BigInt res("0");

    FOR(i, 1, n) res += F[i][m];

    printf("%s\n", res.val.c_str());
}

//Main Procedure
int main()
{
    FILEOP();
    PreSolve();
    cin >> tc;
    while(tc--)
    {
        Solve();
    }
    return 0;
}
