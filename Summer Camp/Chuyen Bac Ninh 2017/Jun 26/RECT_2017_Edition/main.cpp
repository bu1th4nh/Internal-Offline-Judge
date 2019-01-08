//Problem RECT
#include <bits/stdc++.h>
using namespace std;
//=====================================
//Typedef and variable declaration
typedef long long ll;
int m, n;
int h[500001];
//bool a[100001][100001];


//=====================================
//Functions and procedures

//File I/O and initialization
void InitFile()
{
    freopen("RECT.INP", "r", stdin);
    freopen("RECT.OUT", "w", stdout);
}
void CloseFile()
{
    fclose(stdin);
    fclose(stdout);
}
void Init()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(1);
    //cout.tie(1);
}
//Processes
void Input()
{
    cin >> m >> n;
    for(int i=1; i<=n; i++)
    {

        cin >> h[i];

    }
}
void Process()
{
    ll res =0;
    for (int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            int hmin = h[i];
            for(int k=i+1; k<=j; k++)
            {
                hmin = min(hmin, h[k]);
            }
            res = max(res, (ll)(j - i + 1)*hmin);
        }
    }
    cout << res;
}
int main()
{
    Init();
    InitFile();
    Input();
    Process();
    CloseFile();
    return 0;
}
