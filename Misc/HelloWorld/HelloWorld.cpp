#include <bits/stdc++.h>

using namespace std;

string s;

void Init()
{
    freopen("HelloWorld.inp", "r", stdin);
    freopen("HelloWorld.out", "w", stdout);
}

void Close()
{
    fclose(stdin);
    fclose(stdout);
}

void Process()
{
    cin >> s;
    cout << s;
}

int main()
{
    Init();
    Process();
    Close();
    return 0;
}
