#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "CARRIAGE"
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define whole(x) x.begin(), x.end()
#define FORBi(x, y) for(int i=x; i>=y; --i)
#define FORBj(x, y) for(int j=x; j>=y; --j)


//=====================================
//Typedef
typedef vector<int> vi;
typedef stack<int>  si;
int n, m, k;
int tlength;
int nTime;
si a;
vi b;


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
void PopA()
{
    tlength -= a.top();
    a.pop();
    ++nTime;
}

void Input()
{
    tlength = 0;
    scanf("%d%d%d", &n, &m, &k);
    FORi(1, n)
    {
        int x;
        scanf("%d", &x);
        tlength += x;
        a.push(x);
    }
    FORi(1, m)
    {
        int x;
        scanf("%d", &x);
        b.push_back(x);
    }
}

void Process()
{
    sort(whole(b));
    FORBi((int)b.size()-1, 0)
    {
        if(k-tlength==b[i])
        {
            printf("%d", nTime);
            return;
        }
        if(k-tlength<b[i]) PopA();
        else
        {
            tlength+=b[i];
            a.push(b[i]);
            ++nTime;
        }
    }
}

int main()
{
    FileInit();
    Input();
    Process();
    FileClose();
    return 0;
}
