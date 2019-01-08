#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "CPATH"

//=====================================
//Typedef and variable declaration
int n, m, k;
vector<int> adj[51];

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
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1; i<=m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
}
//Process
void Process();


int main()
{
    FileInit();
    Input();
    FileClose();
    return 0;
}
