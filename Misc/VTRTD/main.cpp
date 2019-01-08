#include <bits/stdc++.h>

using namespace std;

unsigned long h;
int n;
long double res;
const float g = 9.8;

void Init()
{
    freopen("VTRTD.inp", "r", stdin);
    freopen("VTRTD.out", "w", stdout);
}

void Close()
{
    fclose(stdin);
    fclose(stdout);
}

void Process()
{
    cin >> n;
    if (n<9999)
    {for (int i=1; i<=n; i++)
    {
        cin >> h;
        res = sqrt(2*h*g);
        cout << setprecision(5) << res << endl;
    }}
    else
    {for (int i=1; i<=n; i++)
    {
        cin >> h;
        res = sqrt(2*h*g);
        cout << setprecision(3) << res << endl;
    }
    }
}

int main()
{
    Init();
    Process();
    Close();
    return 0;
}
