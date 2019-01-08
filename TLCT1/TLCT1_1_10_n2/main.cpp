#include <bits/stdc++.h>
using namespace std;

//=====================================
//Macros
#define task ""

//=====================================
//Typedef
int a[1024];
int n, s;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	cin >> n >> s;
	for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
}

//Process
void Solve()
{
    for(int i = 1; i < n; ++i)
    {
        for(int j = i+1; j <= n; ++j)
        {
            int tmp = 0;
            for(int k = i; k <= j; ++k)
            {
                tmp += a[k];
            }
            if(tmp == s)
            {
                for(int k = i; k <= j; ++k)
                {
                    cout << a[k] << " ";
                }
                return;
            }
        }
    }
}


//Main Procedure
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    Enter();
    Solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
