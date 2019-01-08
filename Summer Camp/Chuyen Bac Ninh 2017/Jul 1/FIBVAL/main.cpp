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
int k, u, v;



//=====================================
//Mat. Multiplication
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



//=====================================
//Functions and procedures
//Initialization
char Note(ll x)
{
    int mod = (int)x % 7;
    switch (mod)
    {
        case 1: return 'C';
        case 2: return 'D';
        case 3: return 'E';
        case 4: return 'F';
        case 5: return 'G';
        case 6: return 'A';
        case 0: return 'B';
        default: return ' ';
    }
}

ll Fibonacci(int x)
{
    Matrix FibUnit(1, 0, 1, 0);
    Matrix Unit(1, 1, 1, 0);
    Matrix A1 = Power(Unit, x-1);
    Matrix A2 = A1*FibUnit;
    return A2.val[1][1];
}

//Input
void Input()
{
    cin >> k;
}

void Process()
{
    cin >> u >> v;
    string s;
    FORi(u, v)
    {
        s += Note(Fibonacci(i));
    }
    cout << s;
}

int main()
{
    Process();
    return 0;
}
