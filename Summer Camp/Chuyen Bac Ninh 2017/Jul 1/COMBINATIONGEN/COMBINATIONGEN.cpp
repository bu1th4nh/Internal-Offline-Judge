#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros


//=====================================
//Typedef
int m, n;
int combi[10001];


//=====================================
//Functions and procedures
//Input
void Input()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        cin >> combi[i];
    }
}

//Process
int Process()
{
    int i = m;
    while(i > 0 && combi[i] == n-m+i) --i;
    if(i <= 0)
    {
        cout << -1;
        return 0;
    }
    else
    {
        ++combi[i];
        for(int j=i+1; j<=m; ++j) combi[j] = combi[j-1] + 1;
        for(int k=1; k<=m; ++k) cout << combi[k] << " ";
    }
}

int main()
{
    Input();
    Process();
    return 0;
}
