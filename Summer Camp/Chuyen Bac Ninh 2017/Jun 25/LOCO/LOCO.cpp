#include <bits/stdc++.h>
using namespace std;
//Typedef
typedef long long ll;
typedef unsigned long long ull;
//Variable
ull n;
int M;
//Functions
struct mat
{
    int val[4][4];
    mat()
    {
        memset(val, 0, sizeof(val));
    }
    mat operator * (const mat & x)
    {
        mat res;
        for (int i=1; i<=3; i++)
            for (int j=1; j<=3; j++)
                for (int k=1; k<=3; k++)
                res.val[i][j] += (ll)val[i][k]*x.val[k][j];
        return res;
    }
    mat DefaultMat()
    {
        mat a;
        for (int i=1; i<=3; i++) a.val[1][i] = 1;
        a.val[2][1] = 1;
    }
};

mat POWW(mat a, ll b)
    {
        mat c;
        for (int i = 1; i <= 3; i++) c.val[i][i] = 1;
        for(; b; b>>1, a=a*a)
        {
            if(b&1) c=c*a;
        }
        return c;
    }

void Init()
{
    freopen("LOCO.INP", "r", stdin);
    freopen("LOCO.OUT", "w", stdout);
}

void Close()
{
    fclose(stdin);
    fclose(stdout);
}

void Process()
{
    cin >> n >> M;
    mat T;
    T = T.DefaultMat();
    T = POWW(T, n-2);
    int res = (T.val[1][1]*2 + T.val[1][2]*1 + T.val[1][3]*1)%M;
    cout << res;
}


int main()
{
    Init();
    Process();
    Close();
    return 0;
}
