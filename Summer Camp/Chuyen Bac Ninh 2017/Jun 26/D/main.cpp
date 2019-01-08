#include <bits/stdc++.h>
using namespace std;
//================================
//Typedef and global variable declaration
vector <int> adj[101];
int n, m, g, k;
bool avail[101];

//================================
//Function and procedures

//File I/O
void InitFile()
{
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);
}
void Close()
{
    fclose(stdin);
    fclose(stdout);
}
//Initialization
void Initial()
{
    ios_base::sync_with_stdio(0);
    cin.tie(1);
    cout.tie(1);
}
//Process
void Input()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
