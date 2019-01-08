#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "MAXPROFIT"

//=====================================
//Typedef
struct Work
{
    int p, d, w;
};
vector <Work> vect;
int n, res;

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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool cmp(Work x, Work y)
{
    return x.d < y.d;
}

//Input
void Input()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        Work x;
        cin >> x.p >> x.d >> x.w;
        vect.push_back(x);
    }
}
//Process
void Process()
{
    sort(vect.begin(), vect.end(), cmp);
    int time = 0;
    for(int i=0; i<n; i++)
    {
        if (vect[i].p + time <= vect[i].d)
        {
            res += vect[i].w;
            time += vect[i].p;
        }
    }
    cout << res;
}

//Main program
int main()
{
    FileInit();
    Input();
    Process();
    FileClose();
    return 0;
}
