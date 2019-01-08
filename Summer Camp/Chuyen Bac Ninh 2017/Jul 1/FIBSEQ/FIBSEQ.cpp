#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)


//=====================================
//Typedef
typedef int64_t ll;
int n, k1, p;
vector <ll> psum;
int test;
vector <int> res;


//=====================================
//Mat. Multiplication and Fibonacci
class Matrix
{
public:
    int val[3][3];

    Matrix(int ul, int ur, int lowl, int lowr)
    {
        val[1][1] = ul;
        val[1][2] = ur;
        val[2][1] = lowl;
        val[2][2] = lowr;
        val[0][0] = 0;
        val[0][1] = 0;
        val[0][2] = 0;
        val[1][0] = 0;
        val[2][0] = 0;
    }

    Matrix()
    {
        memset(val, 0, sizeof(val));
    }

    Matrix operator * (const Matrix & x)
    {
        Matrix res;
        FORi(1, 2)
        {
            FORj(1, 2)
            {
                FORk(1, 2)
                {
                    res.val[i][j] += (ll)val[i][k]*x.val[k][j];
                }
            }
        }
        return res;
    }
};

Matrix Power(Matrix A, ll B)
{
    Matrix C(1, 0, 0, 1);
    for(; B; B>>=1, A = A*A)
    {
        if(B&1) C = C*A;
    }
    return C;
}

ll Fibonacci(int x)
{
    Matrix FibUnit(1, 0, 1, 0);
    Matrix Unit(1, 1, 1, 0);
    Matrix A1 = Power(Unit, x-1);
    Matrix A2 = A1*FibUnit;
    return A2.val[1][1];
}

//=====================================
//Functions and procedures
//Initialization
void Process()
{

    cin >> n >> p >> k1;
    psum.push_back(0);
    int cnt = 1;
    FORi(p, n+p)
    {
        ll f = Fibonacci(i);
        psum.push_back(psum[cnt-1]+f);
    }
    FORi(2, n)
    {
        FORj(1, i-1)
        {
            if((psum[i]-psum[j]) % k1 == 0)
            {
                FORk(j, i) res.push_back(k+p);
                return;
            }
        }
    }


}

void Output()
{
    if (!res.empty())
    {
        cout << res.size() << ' ';
        FORi(0, res.size()-1)  cout << res[i] << ' ';
        cout << endl;
    }
    else cout << -1 << endl;
}


int main()
{
    cin >> test;
    FORi(1, test)
    {
        Process();
        Output();
        res.clear();
    }
    return 0;
}
