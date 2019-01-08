#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define taskname "LM"
const int maxN = 1e6;

int f[maxN], trace[maxN], n;
vector<int> digits;
queue<int> q;

void Enter()
{
    cin >> n;
    string s;
    cin >> s;
    bool mark[10];
    fill(begin(mark), end(mark), false);
    for (char c: s)
        mark[c - '0'] = true;
    for (int d = 0; d <= 9; d++)
        if (mark[d]) digits.push_back(d);
}

void Solve()
{
    fill(begin(f), end(f), -1);
    for (int d: digits)
        {
            if (d == 0) continue;
            if (f[d % n] == -1)
            {
                f[d % n] = d;
                trace[d % n] = -1;
                q.push(d % n);
            }
        }
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int d: digits)
        {
            int v = (u * 10 + d) % n;
            if (f[v] == -1)
            {
                f[v] = d;
                trace[v] = u;
                if (v == 0) return;
                q.push(v);
            }
        }
    }
}

void Print()
{
    if (f[0] == -1)
    {
        cout << 0;
        return;
    }
    vector<int> res;
    for (int x = 0; x != -1; x = trace[x])
        res.push_back(f[x]);
    for (auto it = res.rbegin(); it != res.rend(); it++)
        cout << *it;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Solve();
    Print();
}
