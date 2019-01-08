#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
#define taskname "RECT"
const int maxN = 5e5 + 1;
int m, n, h[maxN], L[maxN], R[maxN];
typedef long long lli;
stack<int> s;
lli res;

void Enter()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
}

inline void Update(lli t)
{
    if (res < t) res = t;
}

void Analyze()
{
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && h[s.top()] >= h[i])
            s.pop();
        if (s.empty()) L[i] = 0;
        else L[i] = s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && h[s.top()] >= h[i])
            s.pop();
        if (s.empty()) R[i] = n + 1;
        else R[i] = s.top();
        s.push(i);
        Update(lli(R[i] - L[i] - 1) * h[i]);
    }
}

void Solve()
{
    res = 0;
    Analyze();
    for (int i = 1; i <= n; i++)
        h[i] = m - h[i];
    Analyze();
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

