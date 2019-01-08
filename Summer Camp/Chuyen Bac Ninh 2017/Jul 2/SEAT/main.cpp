#include <bits/stdc++.h>

using namespace std;

int T, n;


unsigned long long fact(int k)
{
    if (k==0 || k==1) return 1;
    else return fact(k-1)*k;
}

int main()
{
    cin >> T;
    for(int i=1; i<T; ++i)
    {
        cin >> n;
        unsigned long long k=fact(n);
        cout << k;
    }
    return 0;
}
