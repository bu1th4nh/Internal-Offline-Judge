#include <bits/stdc++.h>
using namespace std;
//===================================
//Typedef
typedef long long ll;
//Variable
const int MOD = 1e9 + 7;
ll n;
int M;

class matrix
{

public:

    int val[3][3];

    matrix()
    {
        memset(val, 0, sizeof(val));
    }

    matrix operator * (const matrix & x )
    {
        matrix res;
        for (int i=1; i<=2; i++)
            for (int j=1; j<=2; j++)
                for (int k=1; k<=2; k++)
                   {res.val[i][j] = ( (ll)val[i][k]*x.val[k][j] + res.val[i][j] ) % MOD;}
        return res;
    }

};

matrix POW3R(matrix A, long long B)
{
    matrix C;
    for (int i=1; i<=2; i++) C.val[i][i] = 1;
    for(; B; B >>= 1, A = A * A)
    {
        if (B&1) C = C * A;
    }
    return C;
}


void Init()
{


    freopen("TILE.INP", "r", stdin);
    freopen("TILE.OUT", "w", stdout);


}

void Close()
{


    fclose(stdin);
    fclose(stdout);


}

void Process()
{


    matrix T;
    matrix K;
    T.val[1][1] = 1;
    T.val[1][2] = 2;
    T.val[2][1] = 1;
    T.val[2][2] = 0;
    /*for (int i=1; i<=2; i++) {
        for (int j=1; j<=2; j++) cout << T.val[i][j] << " ";
        cout << endl;
    }*/
    cin >> n;
    matrix res;
    res = POW3R(T, n-1);
    res.val[1][1] = (res.val[1][1] + res.val[1][2])%MOD;
    cout << res.val[1][1] << endl;

}

int main()
{
    //Init();
    cin >> M;
    for(int i=1; i<=M; i++) Process();
    //Close();
    return 0;
}
