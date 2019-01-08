#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "EXPRESSION"
#define maxn 100001

//=====================================
//Typedef
typedef int64_t ll;
string s;

//=====================================
//Functions and procedures
//Initialization
void FileInit()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void Init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

//Input
void Input()
{
    getline(cin, s);
}

bool IsBracket(char x)
{
    return (x == ')')||(x == '(')||(x == ',');
}

bool IsSubOperator(char x)
{
    return (((x >= 'A')&&(x <= 'Z'))||((x >= 'a')&&(x <= 'z'))) && (! ((x == 'M') || (x == 'F') || (x == 'X') || (x == 'N') || (x == 'D')));
}

bool IsOperator(char x)
{
    return (x == 'M') || (x == 'F') || (x == 'X') || (x == 'N') || (x == 'D');
}

bool IsNum(char x)
{
    return (x >= '0')&&(x <= '9');
}

void Refine()
{
    for(int i=(int)s.length()-2; i>=0; --i)
    {
        if (IsBracket(s[i])) s.erase(i, 1);
        if (IsSubOperator(s[i])) s.erase(i, 1);
        if ((s[i]==' ')&&(s[i+1])==' ') s.erase(i, 1);
    }
}

ll GCD(ll a, ll b)
{
    while ( a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    return a; // or return b; a = b
}

ll Calc(ll a, ll b, char Operator)
{
    switch (Operator)
    {
        case 'M': return a+b;         //M : SUM
        case 'F': return a-b;         //F : DIFF
        case 'X': return max(a, b);   //X : MAX
        case 'N': return min(a, b);   //N : MIN
        case 'D': return GCD(a, b);   //D : GCD
    }
}

void Process()
{
    Refine();
    stack <ll> Exp;
    string k;
    for(int i=(int)s.length()-1; i>=0; --i)
    {
        if (IsNum(s[i])) k = s[i] + k;
        else if (s[i]==' ')
        {
                string::size_type sz;
                ll xxx = strtoll(k.c_str(), NULL, NULL);
                Exp.push(xxx);
        }
        else
        {
            ll a1, b1;
            a1 = Exp.top(); Exp.pop();
            b1 = Exp.top(); Exp.pop();
            Exp.push(Calc(a1, b1, s[i]));
        }
    }
    ll res = Exp.top();
    Exp.pop();
    printf("%I64d", res);
}

int main()
{
    //FileInit();
    Input();
    Process();
    //FileClose();
    return 0;
}
