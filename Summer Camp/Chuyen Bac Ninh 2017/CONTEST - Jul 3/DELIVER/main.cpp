#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "DELIVER"
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)


//=====================================
//Typedef
struct pnt
{
    int x, a;
    bool done;
};
vector<pnt> vect;
int n, m;
int64_t res;
int f[100002];


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
    FORi(1, n)
    {
        pnt q;
        scanf("%d%d", &q.x, &q.a);
        q.done = false;
        vect.push_back(q);
    }
}

void Process()
{
    res = 0;
    int prev = 0;
    int avail = m;
    FORj(0, n-1)
    {
        FORi(j, n-1)
        {
            if((!vect[i].done))
            {
                avail -= min(vect[i].a, avail);
                vect[i].a -= min(vect[i].a, avail);
                if (vect[i].a == 0) vect[i].done = true;
                prev = vect[i].x*2;
            }
            if (avail == 0)
            {
                avail = m;
                res += 2*vect[i].x ;
            }

        }
    }
    printf("%I64d", res);
}

int main()
{
    FileInit();
    Input();
    Process();
    FileClose();
    return 0;
}




