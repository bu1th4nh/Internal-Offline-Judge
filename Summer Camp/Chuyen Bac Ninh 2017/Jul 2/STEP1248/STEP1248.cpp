#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define maxn (int)(1e5+1)
#define module (int)(1e9+7)


//=====================================
//Typedef
typedef unsigned long long ull;
typedef unsigned int ui;
int n;
int res;
int f[maxn];


//=====================================
//Functions and procedures
//Input
void Input()
{
    cin >> n;
    //memset(f, 0, sizeof(f));
}

void QHD()
{
    f[0] = 1;
    //f[1] = 1;
    for(int i=1; i<=n; ++i)
    {
        for(int k = 0; (1 << k) <= i; ++k) f[i] = (f[i] + f[i - (1 << k)])%module;
    }
    cout << f[n];
}

int main()
{
    Input();
    QHD();
    return 0;
}
