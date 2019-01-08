#include <bits/stdc++.h>

using namespace std;

vector <int> mang;
int n;

void Init()
{
    freopen("SXCB.inp", "r", stdin);
    freopen("SXCB.out", "w", stdout);
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
        mang.push_back(x);
    }
}

void Process()
{
    sort(mang.begin(), mang.end());
    for (int i = 0; i<n; i++) cout << mang[i] << " ";
}

int main()
{
    Init();
    Input();
    Process();
    Close();
    return 0;
}
