#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 1000;
const int lim = 1000;
const int NA = -1;
int n, q, a[maxN], cnt[maxN];
int _trace[2 * lim + 1], *trace;


void Enter()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= q;
    }
    fill(begin(_trace), end(_trace), NA);
    trace = _trace + lim;
}

void Solve()
{
    queue<int> Queue;
    for (int i = 0; i < n; i++)
        if (trace[a[i]] == NA)
        {
            trace[a[i]] = i;
            Queue.push(a[i]);
        }
    while (!Queue.empty())
    {
        int u = Queue.front(); Queue.pop();
        for (int i = 0; i < n; i++)
        {
            int v = u + a[i];
            if (v >= -lim && v <= lim && trace[v] == NA)
            {
                trace[v] = i;
                if (v == 0) return;
                Queue.push(v);
            }
        }
    }
}

void Print()
{
    if (trace[0] == NA)
        cout << "NO";
    else
    {
        cout << "YES\n";
        fill(begin(cnt), end(cnt), 0);
        int v = 0;
        do
        {
            int i = trace[v];
            cnt[i]++;
            v -= a[i];
        }
        while (v != 0);
        for (int i = 0; i < n; i++)
            cout << cnt[i] << ' ';
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("COCKTAIL.inp", "r", stdin);
    freopen("COCKTAIL.out", "w", stdout);

    Enter();
    Solve();
    Print();
}
