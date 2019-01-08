#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "PANDS"
#define maxk 32

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
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        vect.push_back(x);
    }
}

//Process
void Process()
{
    res = 0;
    for(int k = 0; k <= maxk; ++k)
    {
        int dem1 = 0;
        for(int i = 0; i < n; ++i)
        {
            if(((vect[i] >> k) & 1) == 1) ++dem1;
        }
        res += ((int64_t)(dem1*(dem1-1)/2) * (1 << k));
    }
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
