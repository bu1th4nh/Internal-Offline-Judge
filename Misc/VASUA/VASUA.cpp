#include <bits/stdc++.h>

using namespace std;

vector <int> cow;
int n;

void Init()
{
    //ios::sync_with_stdio(0);
    freopen("VASUA.inp", "r", stdin);
    freopen("VASUA.out", "w", stdout);
}

void Close()
{
    fclose(stdin);
    fclose(stdout);
}

void Input()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        cow.push_back(x);
    }
}

bool CMP(int a, int b)
{
    return (a>b);
}

void Output()
{
    int res = 0, ms = 0;
    sort(cow.begin(), cow.end(), CMP);
    for (int i=0; i<n; i++)
    {
        if (ms < cow[i]) res += cow[i] - ms;
        ms++;
    }
    cout << res;
}

int main()
{
    Init();
    Input();
    Output();
    Close();
    return 0;
}
