#include<bits/stdc++.h>
using namespace std;

int n;

int GetLevel(int id)
{
    if (id >= n) return 0;
    int tmp = 1;
    while(id > 0)
    {
        id /= 2;
        ++tmp;
    }
    return tmp;
}


int main()
{
    int i;
    cin >> n >> i;
    n = 1 << n;
    cout << "LVS " << GetLevel(i);
}

