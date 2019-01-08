#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, k, b;
    cin >> a >> k >> b;
    if (k>=1 && a>0)
    {
        int64_t res = ceil((k - 1)*(log(b)/log(a)));
        cout << res;
    }
    else
    {
        cout << -1;
    }
    return 0;
}
