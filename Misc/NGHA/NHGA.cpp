#include <bits/stdc++.h>

using namespace std;

vector<int> dist;
int n;

void Init()
{
    freopen("NHGA.inp", "r", stdin);
    freopen("NHGA.out", "w", stdout);
}

void Close()
{
    fclose(stdin);
    fclose(stdout);
}

void input()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>> x;
        dist.push_back(x);
    }
}

void Output()
{
    int ans = INFINITY;
    sort(dist.begin(), dist.end());
    for(int i=0; i<n-1; i++)
    {
        ans = min(ans, dist[i+1]-dist[i]);
    }
    cout << ans;
}

int main()
{
    Init();
    input();
    Output();
    Close();
    return 0;
}
