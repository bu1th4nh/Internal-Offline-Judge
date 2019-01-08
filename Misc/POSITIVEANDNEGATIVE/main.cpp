#include<bits/stdc++.h>

using namespace std;

long long x;

int main()
{
    freopen("POSITVEANDNEGATIVE.INP","r",stdin);
    freopen("POSITVEANDNEGATIVE.OUT","w",stdout);
    cin >> x;
    if (x==0) {cout << "ZERO" << endl;}
    else
    {
        if (x%2 != 0) {cout << "POSITIVE" << endl;} else cout << "NEGATIVE" << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
