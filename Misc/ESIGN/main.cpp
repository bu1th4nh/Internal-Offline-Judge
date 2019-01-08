#include <bits/stdc++.h>
using namespace std;

//=====================================
//Macros
#define task ""
#define maxmn (int)(1e5+1)
#define MODUL (long long)(1e9+57)
#define MULTI 30007
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORlj(x, y) for(int j=x; j<y; ++j)
#define FORlk(x, y) for(int k=x; k<y; ++k)

//=====================================
//Typedef
typedef unsigned long long ull;
typedef vector<int> vi;
int res, m, n;
ull h[maxmn];
vi p, a;



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
void IOSOpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


//Input
void Input()
{
    p.push_back(-100);
    a.push_back(-100);
    cin >> n;
    FORi(1, n)
    {
        int x;
        cin >> x;
        p.push_back(x);
    }
    cin >> m;
    FORi(1, m)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
}

//Hashing
void HashInit()
{
    h[1] = MODUL;
    FORi(2, maxmn-1) (h[i] = h[i-1]*MULTI) % MODUL;
}

//Process
void Process()
{
    res = 0;
    ull val = 0;
    ull chk = 0;
    FORi(1, n) val += h[p[i]];
    FORi(1, m-n+1)
    {
        chk = 0;
        FORj(i, i+n-1) chk += h[a[j]];
        if(val == chk)
        {
            cout << "YES" << endl << i << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    Input();
    HashInit();
    Process();
    return 0;
}
