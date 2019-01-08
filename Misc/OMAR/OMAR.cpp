#include <bits/stdc++.h>

using namespace std;

int n;

void Initialize()
{
    freopen("OMAR.INP","r",stdin);
    freopen("OMAR.OUT","w",stdout);
}

void CloseFile()
{
    fclose(stdin);
    fclose(stdout);
}

void Process()
{
    int n, x, y;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> x >> y;
        cout << x+y << endl;
    }
}

int main()
{
    Initialize();
    Process();
    CloseFile();
    return 0;
}
