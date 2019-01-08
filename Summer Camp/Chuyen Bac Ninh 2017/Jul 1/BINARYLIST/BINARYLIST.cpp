#include <bits/stdc++.h>
#define maxn int(1e4 + 2)
#define oo int(1e9 + 1)

using namespace std;
int N, K, I, x[maxn];
int64_t f[maxn];

int64_t tinhF(int n)
{
    if(f[n])return f[n];
    if(n < I)
    {
        f[n] = (1 << n);
        return f[n];
    }
    for(int i = 1; i <= I; ++i)
    {
        f[n] += tinhF(n - i);
        if(f[n] > oo)
        {
            f[n] = oo;
            return f[n];
        }    }
    return f[n];
}

int F(int n){
    if(n == 0)return 0;
    if(n < I){
        x[N - n + 1] = (((K - 1) >> (n - 1)) & 1);
        F(n - 1);
        return 0;
    }
    int s;
    for(int i = I; i >= 1; --i)
    {
        s = tinhF(n - i);
        if(K <= s)
        {
            x[N - n + i] = 1;
            F(n - i);
            return 0;
        }
        K -= s;
    }
    return 0;
}

int solve()
{
    scanf("%d%d%d", &N, &K, &I);
    if(K > tinhF(N))
    {
        printf("-1");
        return 0;
    }
    F(N);
    for(int i = 1; i <= N; ++i)printf("%d ", x[i]);
    return 0;
}

int main()
{
    solve();
    return 0;
}
