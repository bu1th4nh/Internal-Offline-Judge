#include<bits/stdc++.h>
using namespace std;
//=====================================
//Typedef and variable declaration
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
int n;
VI a;

//=====================================
//Functions and procedures
void InitFile()
{
    freopen("WEIGHT.inp", "r", stdin);
    freopen("WEIGHT.out", "w", stdout);
}
void CloseFile()
{
    fclose(stdin);
    fclose(stdout);
}
void Input()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
}
void Output()
{

}


int main()
{
    ios_base::sync_with_stdio(0);
    return 0;
}
