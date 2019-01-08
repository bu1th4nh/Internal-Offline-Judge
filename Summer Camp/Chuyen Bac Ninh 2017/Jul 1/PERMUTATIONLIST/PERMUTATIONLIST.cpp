#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros


//=====================================
//Typedef
int k, n;
int perm[10001];


//=====================================
//Functions and procedures
//Input
void Input()
{
    cin >> n >> k;
    for(int i=1; i<=n; ++i)
    {
        perm[i] = i;
    }
}
//Process
int Process()
{
    int i = n-1;
    while(i>0 && perm[i] > perm[i+1]) --i;
    if (i<=0)
    {
        return 1;
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
        return 0;
    }
}

void Output()
{
    for(int ii=1; ii<k; ++ii)
    {
        if(Process())
        {
            cout <<-1;
            return;
        }
    }
    for(int i=1; i<=n; ++i) cout << perm[i] << " ";
}

int main()
{
    Input();
    Output();
    return 0;
}
