#include <bits/stdc++.h>

using namespace std;

vector <int> vect;
int n, a, b;

void Init()
{
    freopen("ARMY.INP","r",stdin);
    freopen("ARMY.OUT","w",stdout);
}

void Close()
{
    fclose(stdin);
    fclose(stdout);
}

void Input()
{
    cin >> n;
    for (int i=1; i<n; i++)
    {
        int xxx;
        cin >> xxx;
        vect.push_back(xxx);
    }
    cin >> a >> b;
}

void Output()
{
    int res = 0;
    for (int i = a; i<b; i++) res += vect[i-1];
    cout << res << endl;
}

int main()
{
    Init();
    Input();
    Output();
    Close();
    return 0;
}
