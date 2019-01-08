#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "MAXXOR"


//=====================================
//Typedef
vector <long long> vect;
int n;
long long res;

//=====================================
//Functions and procedures
//Initialization
void FileInit()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void Init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

//Input
void Input()
{
    cin >> n;
    for(int i=1; i<n; ++i)
    {
        long long x;
        cin >> x;
        vect.push_back(x);
    }
}


//Process
void Process()
{
    res = -INFINITY;
    for(int i=0; i<n; ++i)
        for(int j=i; j<n; ++j) res = max(res, vect[i]^vect[j]);
    cout << res;
}




int main()
{
    FileInit();
    Input();
    Process();
    FileClose();
    return 0;
}
