#include <iostream>
#include <cstdio>
using namespace std;
#define taskname "WEIGHT"
const int maxN = 1e6 + 2; //due to C++ slow io stream
const int infty = 1e6 + 1;
typedef long long lli;
typedef int TArray[maxN];
typedef lli TLLIArray[maxN];
int n, top;
TArray a, L, Stack;
TLLIArray f, g;
lli res;

void Enter()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = a[n + 1] = infty;
}

void Parsing(TLLIArray &f)
{
    //L[i]: Vị trí phần tử đứng trước >= a[i]
    top = 0;
    Stack[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (a[Stack[top]] < a[i]) top--;
        L[i] = Stack[top];
        Stack[++top] = i;
    }
    //R[i]: Vị trí phần tử đứng sau > a[i]
    top = 0;
    Stack[0] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        while (a[Stack[top]] <= a[i]) top--;
        int R = Stack[top];
        Stack[++top] = i;
        f[i] = lli(i - L[i]) * (R - i);
    }
}

void Solve()
{
    Parsing(f);
    for (int i = 1; i <= n; i++) a[i] = -a[i];
    Parsing(g);
    res = 0;
    for (int i = 1; i <= n; i++) res += lli(a[i]) * (g[i] - f[i]);
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Solve();
}
