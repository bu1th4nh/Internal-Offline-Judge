#include <bits/stdc++.h>

using namespace std;

int a, b, c;

void Init()
{
    freopen("QUADRATIC.inp","r",stdin);
    freopen("QUADRATIC.out","w",stdout);
}

void Close()
{
    fclose(stdin);
    fclose(stdout);
}

void Input()
{
    cin >> a >> b >> c;
}

void Process()
{
    long long delta = b*b - 4*a*c;
    if (delta < 0)
    {
        cout << "VONGHIEM";
    }
    else if (delta == 0)
    {
        cout << setprecision(4) << -b/(2*a);
    }
    else
    {
        double x1 = (-b + sqrt(delta))/(2*a), x2 = (-b - sqrt(delta))/(2*a);
        cout << setprecision(4) << x1 << endl;
        cout << setprecision(4) << x2 << endl;
    }
}

int main()
{
    Init();
    Input();
    Process();
    Close();
    return 0;
}
