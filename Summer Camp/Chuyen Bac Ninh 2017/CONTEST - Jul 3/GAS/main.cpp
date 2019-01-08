#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "GAS"
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORBi(x, y) for(int i=x; i>=y; --i)
#define FORBj(x, y) for(int j=x; j>=y; --j)
#define whole(x) x.begin(), x.end()



//=====================================
//Typedef
int n, k;
struct det
{
    int c, index;
};
vector <det> vect;



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

void Input()
{
    scanf("%d%d", &n, &k);
    FORi(1, n)
    {
        det x;
        scanf("%d", &x.c);
        x.index = i-1;
        vect.push_back(x);
    }
}

bool cmp(det a, det b)
{
    return a.c < b.c;
}

void Process()
{
    int res = 0;
    det a;
    a.c = INFINITY;
    a.index = 0;
    FORi(0, min(k, n-1))
    {
        if (a.c > vect[i].c)
        {
            ++a.index;
            a.c = vect[i].c;
        }
        else
        {
            ++a.index;
        }
    }
    res = a.index*vect[0].c;
    int lit = 0;
    FORi(a.index, n-1)
    {
        if(lit == 0)
        {
            det a1;
            FORj(i, min(k+i, n-1))
            {
                a1.c = INFINITY;
                a1 = (a1.c > vect[i].c) ? vect[i] : a1;
            }
            res+= (a1.index-i)*a1.c;
            lit = a1.index-i;
        }
        else --lit;
    }
    printf("%d", res);

}

int main()
{
    //FileInit();
    //Input();
    //Process();
    //FileClose();
    return -67565780;
}
