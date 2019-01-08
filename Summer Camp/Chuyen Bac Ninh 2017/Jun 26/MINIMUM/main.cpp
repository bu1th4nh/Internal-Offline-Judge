#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[500001];

int main()
{
    freopen("MINIMUM.inp", "r", stdin);
    freopen("MINIMUM.out", "w", stdout);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int j=1; j<=n-k+1; j++)
    {
        int res = INFINITY;
        for(int i=j; i<=j+k-1;i++)
        {
            res = min(res, a[i] );
        }
        cout << res << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
