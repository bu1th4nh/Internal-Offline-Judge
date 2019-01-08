#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task ""
#define max (int)(1e3+1)
#define inf (int)(1e9+7)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORlj(x, y) for(int j=x; j<y; ++j)
#define FORlk(x, y) for(int k=x; k<y; ++k)

//=====================================
//Typedef
typedef vector<int> vi;
typedef pair<int, int> p2i;
typedef queue<p2i> qp;
int m, n;
int a[max][max];
int b[max][max];
qp loc;
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
    cout.tie(NULL);
}
void Prep()
{
    memset(b, -1, sizeof(b));
    loc.push(make_pair(1, 1));
    b[1][1] = a[1][1];
}

//Input
void Input()
{
    cin >> n >> m;
    FORi(1, n)
    {
        FORj(1, m)
        {
            cin >> a[i][j];
        }
    }
}

//Process
void Process()
{
    while(!loc.empty())
    {
        p2i x = loc.front();
        loc.pop();
        int u = x.first, v = x.second;
        if (!(u+1 > n && v+1 > m))
        {
            if (b[u+1][v] > -1)
            {
                b[u+1][v] = min(b[u][v] + a[u+1][v], b[u+1][v]);
            }
            else
            {
                b[u+1][v] = b[u][v] + a[u+1][v];
                loc.push(make_pair(u+1, v));
            }


            if (b[u][v+1] > -1)
            {
                b[u][v+1] = min(b[u][v] + a[u][v+1], b[u][v+1]);
            }
            else
            {
                b[u][v+1] = b[u][v] + a[u][v+1];
                loc.push(make_pair(u, v+1));
            }

        }
    }
    cout << b[n][m];
}



int main()
{
    Input();
    Prep();
    Process();
    return 0;
}
