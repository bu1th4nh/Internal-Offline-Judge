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
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)()
#define MODUL (int)(10e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
string src, dst;
int n;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP(task)
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Check
char CheckHex(string t)
{
    assert(len(t)==4);
    int val = strtol(t.c_str(), NULL, 0);
    switch (val)
    {
        case 0000: {return '0'; break;}
        case 0001: {return '1'; break;}
        case 0010: {return '2'; break;}
        case 0011: {return '3'; break;}
        case 0100: {return '4'; break;}
        case 0101: {return '5'; break;}
        case 0110: {return '6'; break;}
        case 0111: {return '7'; break;}
        case 1000: {return '8'; break;}
        case 1001: {return '9'; break;}
        case 1010: {return 'A'; break;}
        case 1011: {return 'B'; break;}
        case 1100: {return 'C'; break;}
        case 1101: {return 'D'; break;}
        case 1110: {return 'E'; break;}
        case 1111: {return 'F'; break;}
        default: cout << "Invalid Input!!!" << endl;
    }
}

//Main Procedure
int main()
{
    getline(cin, src);
    while(src.length()%4 != 0)
    {
        src = '0' + src;
    }
    n = len(src);
    string tmp;
    FORli(0, n)
    {
        tmp+=src[i];
        if (tmp.length()==4)
        {
            dst += CheckHex(tmp);
            tmp = "";
        }
    }
    cout << dst << endl;
    system("pause");
    return 0;
}
