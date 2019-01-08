#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros


//=====================================
//Typedef
int m, n;
int perm[10001];


//=====================================
//Functions and procedures
//Input
void Input()
{
    cin >> n;
    for(int i=1; i<=n; ++i)
    {
        cin >> perm[i];
    }
}
//Process
void Process()
{
    int i = n-1;
    while(i>0 && perm[i] > perm[i+1]) --i;
    if (i<=0)
    {
        cout << -1;
        return;
    }
    else
    {
        int k = n;
        while(perm[k]<perm[i]) --k;
        swap(perm[i], perm[k]);
        int a = i+1, b = n;
        while(a<b)
        {
            swap(perm[a], perm[b]);
            ++a;
            --b;
        }
        for(int kk=1; kk<=n; ++kk) cout << perm[kk] << ' ';
    }
}

int main()
{
    Input();
    Process();
    return 0;
}
