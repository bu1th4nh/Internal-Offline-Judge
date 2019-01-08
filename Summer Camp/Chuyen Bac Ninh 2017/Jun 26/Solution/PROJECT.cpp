/*
#dequeue, #greedy
*/
#define taskname "PROJECT"
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long lli;
const int maxN = 4e5 + 1;
int n, a[maxN], b[maxN], amax[maxN];
lli h, s, d, Cost;
int t;

void Enter()
{
    cin >> n;
    cin >> h >> s >> d;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    t = (h + d) / s + 1;
}

void Init()
{
    deque<int> q;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!q.empty() && a[q.back()] <= a[i])
            q.pop_back();
        q.push_back(i);
        if (q.front() - i >= t) q.pop_front();
        amax[i] = a[q.front()];
    }
}

void Solve()
{
    b[0] = a[0];
    Cost = h * b[0] + s * b[0];
    for (int i = 1; i < n; ++i)
    {
        b[i] = b[i - 1] <= a[i] ? a[i] : min(b[i - 1], amax[i]);
        if (b[i] > b[i - 1]) Cost += h * (b[i] - b[i - 1]);
        else Cost += d * (b[i - 1] - b[i]);
        Cost += b[i] * s;
    }
    Cost += b[n - 1] * d;
}

void Print()
{
    cout << Cost << '\n';
    for (int i = 0; i < n; ++i)
        cout << b[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Init();
    Solve();
    Print();
}

