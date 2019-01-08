#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros


//=====================================
//Typedef
int m, n, k;
int combi[10001];


//=====================================
//Functions and procedures
//Input
void Input()
{
    cin >> n >> m >> k;
    for(int i=1; i<=m; ++i) combi[i] = i;
}

//Process
int Process()
{
    int i = m;
    while(i > 0 && combi[i] == n-m+i) --i;
    if(i > 0)
    {
        ++combi[i];
        for(int j=i+1; j<=m; ++j) combi[j] = combi[j-1] + 1;
    }
    else
    {
        return 1;
    }
    return 0;
}

int Output()
{
    for(int ii = 1; ii<=k-1; ++ii)
    {
        if (Process())
        {
            cout << -1;
            return 0;
        }
    }
    for(int ii = 1; ii<=m; ++ii) cout << combi[ii] << ' ';
}

int main()
{
    Input();
    Output();
    return 0;
}
