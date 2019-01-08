#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "DOMINANT"

//=====================================
//Typedef and variable declaration
string s;
int n, res1, res2;

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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool CVB(char x)
{
    return (x=='1');
}

//Input
void Input()
{
    getline(cin, s);
    n = s.length();
}

//Process
void Process()
{
    int c0 = 0, c1 = 0;
    res1 = 0;
    res2 = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=i; j<n; j++)
        {
            for (int k = i; k<=j; k++)
            {
                if(CVB(s[k])) {c1++;} else c0++;
                res1 = ((c0 < c1)&&(k-i+1 > res1)) ? k-i+1 : res1;
            }
            c1 = 0; c0 = 0;
        }
    }
    if (res1 == n)
    {
        res2 = 1;
    }
    else
    {
        for(int i=0; i<n - res1 +1; i++)
        {
            for(int j=i; j < i + res1; j++)
            {
                if(CVB(s[j])) {c1++;} else c0++;
            }
            if ((c0+c1 == res1)&&(c1 > c0)) res2++;
            c0 = 0; c1 = 0;
        }
    }
    cout << res1 << " " << res2;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    FileInit();
    Input();
    Process();
    FileClose();
    return 0;
}
