#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "UNFAIR"

//=====================================
//Typedef and variable declaration
struct Gamer
{
    int power;
    bool pick;
};
vector <Gamer> a;
vector <Gamer> b;
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
bool cmp(Gamer x, Gamer y)
{
    return x.power < y.power;
}

//Input
void Input()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        Gamer x;
        scanf("%d", &x.power);
        x.pick = false;
        a.push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        Gamer x;
        scanf("%d", &x.power);
        x.pick = false;
        b.push_back(x);
    }
}

//Process
void Process()
{
    res = 0;
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if ((a[j].power < b[i].power)&&(!a[j].pick)&&(!b[i].pick))
            {
                res++;
                a[j].pick = 1;
                b[i].pick = 1;
            }
        }
    }
    printf("%d", res);

}


int main()
{
    FileInit();
    Init();
    Input();
    Process();
    FileClose();
    return 0;
}
