#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "COVERING"

//=====================================
//Typedef and variable declaration
typedef long long ll;
struct Rect
{
    int w;
    int h;
    ll surface;
};
vector <Rect> a;
int n;
ll res;


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

//Input
void Input()
{
    Rect prev;
    prev.h = 0;
    prev.surface = 0;
    prev.w = 0;
    a.push_back(prev);
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        Rect x;
        scanf("%d%d", &x.w, &x.h);
        x.surface = x.w*x.h;
        a.push_back(x);
    }
}

//Process
void Process()
{
    res = 0;
    for (int i=1; i<=n; i++) res += a[i].surface - min(a[i].w, a[i-1].w)*min(a[i].h, a[i-1].h);
    cout << res;
}

//Main
int main()
{
    FileInit();
    //Init();
    Input();
    Process();
    FileClose();
    return 0;
}
