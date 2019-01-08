#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define max 51
#define module (int)(1e6+1)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)


//=====================================
//Typedef
typedef unsigned long long ull;
typedef unsigned int ui;
ull  n, m, k;
ull res;
int T;



//=====================================
//Functions and procedures
//Input
ull fact(ull k)
{
    if (k==0 || k==1) return 1;
    else return fact(k-1)*k;
}

ull ckn(ull k0, ull n0)
{
    if (k0 == 0 || k0 == n) return 1;
	return (ckn(n0- 1, k0 - 1) + ckn(n0 - 1, k0));
}

void Process()
{
    res = 0;
    cin >> m >> n >> k;
    res = ( (ull)ckn(k, m)*ckn(k, n)*fact(k) ) % module;
    cout << res << endl;
}

int main()
{
    cin >> T;
    FORi(1, T) Process();
    return 0;
}
