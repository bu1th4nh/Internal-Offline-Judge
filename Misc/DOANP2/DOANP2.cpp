#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int> > a;
int n;

void Init()
{
    freopen("DOANP2.inp", "r", stdin);
    freopen("DOANP2.out", "w", stdout);
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
        int dau, cuoi;
        cin >> dau >> cuoi;
        a.push_back(make_pair(dau, cuoi));
    }
}

void Process()
{
    sort(a.begin(), a.end());
    int res = a[0].second - a[0].first;
    int dau = a[0].first;
    int cuoi = a[0].second;
    for (int i=1; i<n; i++)
    {
        dau = max(cuoi, a[i].first);
        cuoi = max(cuoi, a[i].second);
        if (cuoi-dau > 0) res += cuoi - dau;
    }
    cout << res;
}

int main()
{
    Init();
    Input();
    Process();
    Close();
    return 0;
}
