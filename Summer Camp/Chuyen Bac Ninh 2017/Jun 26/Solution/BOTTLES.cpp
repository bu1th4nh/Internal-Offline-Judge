#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define taskname "BOTTLES"

typedef long long lli;
const int maxN = 4e5 + 2;
int n, k, a[maxN];
lli f[maxN];
deque<int> Queue;

void Enter()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = 0;
}

void Solve()
{
    f[0] = 0;
    Queue.push_back(0);
    for (int i = 1; i <= n + 1; i++)
    {
        if (Queue.front() < i - k) Queue.pop_front();
        f[i] = f[Queue.front()] + a[i];
        while (!Queue.empty() && f[i] <= f[Queue.back()])
            Queue.pop_back();
        Queue.push_back(i);
    }
}

void Print()
{
    lli sum = 0, fvalue = f[n + 1];
    int cnt = n;
    for (int i = n; i >= 1; i--)
        if (f[i] == fvalue)
        {
            fvalue -= a[i];
            a[i] = -a[i];
            cnt--;
        }
        else sum += a[i];
    cout << cnt << ' ' << sum << '\n';
    for (int i = 1; i <= n; i++)
        if (a[i] > 0) cout << i << ' ';
}

int main()
{
#ifndef hoang
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);

    Enter();
    Solve();
    Print();
}
