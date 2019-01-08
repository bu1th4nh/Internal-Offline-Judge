#include <bits/stdc++.h>

using namespace std;

int a, b, x, y;

ull fact(int k)
{
    if (k==0 || k==1) return 1;
    else return fact(k-1)*k;
}

ull ckn(ull k0, ull n0)
{
    if (k0 == 0 || k0 == n) return 1;
	return (ckn(n0- 1, k0 - 1) + ckn(n0 - 1, k0));
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
