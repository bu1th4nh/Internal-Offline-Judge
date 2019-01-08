#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> Brik;

void Init()
{
    freopen("TITLE.inp", "r", stdin);
    freopen("TITLE.out", "w", stdout);
}

void Close()
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
        Brik.push_back(x);
    }
}

bool cmp(int a, int b)
{
    return (a>b);
}

void Output()
{
    sort(Brik.begin(), Brik.end(), cmp);
    int cap = min(Brik[0], n), res = 1;
    if (n==1)
    {
        cout << 1;
        return;
    }
    for(int i=1; i<n; i++)
    {

    }
    cout << res;
}

int main()
{
    //Init();
    Input();
    Output();
    //Close();
    return 0;
}
