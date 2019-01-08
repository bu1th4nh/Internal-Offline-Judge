#include <bits/stdc++.h>

using namespace std;

int n;
unsigned long long x;

void Init()
{
    freopen("T-PRIMES.INP","r",stdin);
    freopen("T-PRIMES.OUT","r",stdin);
}

void Close()
{
    fclose(stdin);
    fclose(stdout);
}

void Process()
{
    int lim;
    int count0 = 2;
    cin >> x;
    lim = sqrt(x);
    for (int j=2; j<=lim+2; j++)
    {
        if (x%j == 0) count0++;
        if (count0 > 3)
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (count0 < 3)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}


int main()
{
    //Init();
    cin >> n;
    for (int i=1; i<=n; i++) Process();
    //Close();
    return 0;
}
