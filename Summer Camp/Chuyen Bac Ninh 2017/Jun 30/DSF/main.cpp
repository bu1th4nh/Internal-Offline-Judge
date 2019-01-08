#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "DSF"
#define maxn 100001

//=====================================
//Typedef
int m, n;
int lab[maxn];

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
    scanf("%d%d", &n, &m);
}

int FindSet(int u)
{
    return (lab[u] < 0) ? u : lab[u] = FindSet(lab[u]);
}

void Union(int r, int s)
{
    if (lab[s]<lab[r]) swap(r, s);
    lab[r] += lab[s];
    lab[s] = r;
}

void Process()
{
    memset(lab, -1, sizeof(lab));
    int cc = n;
    for(int i=1; i<=m; ++i)
    {
        int u, v;
        cin >> u >> v;
        int x = FindSet(u), y = FindSet(v);
        if (x!=y)
        {
            Union(x, y);
            --cc;
        }
        printf("%d\n", cc);
    }
}

int main()
{
    //FileInit();
    Input();
    Process();
    //FileClose();
    return 0;
}
