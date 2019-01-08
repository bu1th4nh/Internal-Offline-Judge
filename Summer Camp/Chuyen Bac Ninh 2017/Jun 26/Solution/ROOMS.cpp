#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
#define taskname "ROOMS"
const int maxN = 1e5 + 1;

/*Mỗi cuộc họp (s, f] có 2 đầu mút: s: mở, f: đóng.
Có 2n đầu mút
Mỗi đầu mút:
Tọa độ: x
Loại: Đóng = 0, Mở = 1;
Thuộc về cuộc họp nào?: Conference?
*/
struct TPoint
{
    int x;
    int kind;
    int Conference;
};

TPoint p[2 * maxN];
int Room[maxN]; //Room[k] = phòng cấp cho cuộc họp k
int n;
stack<int> s;

typedef vector<int> TRoom;

TRoom r[maxN]; //n vector r[1]... r[n]

void Enter()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int s, f;
        cin >> s >> f;
        p[i].x = s; p[i].kind = 1; p[i].Conference = i;
        p[i + n].x = f; p[i + n].kind = 0; p[i + n].Conference = i;
    }
}

bool lf(const TPoint &p, const TPoint &q)
{
    return p.x < q.x || (p.x == q.x && p.kind < q.kind);
}

void Solve()
{
    int res = 0;
    int Cnt = 0;
    for (int i = n; i >= 1; i--) s.push(i);
    for (int i = 1; i <= 2 * n; i++)
        if (p[i].kind == 1)
        {
            int a = p[i].Conference;
            int b = s.top();

            Room[a] = b; r[b].push_back(a);

            s.pop();
            Cnt++;
            if (res < Cnt) res = Cnt;
        }
        else
        {
            s.push(Room[p[i].Conference]);
            Cnt--;
        }
    cout << res << '\n';
    for (int i = 1; i <= res; i++)
    {
        for (auto q:r[i]) cout << q << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    sort(p + 1, p + 2 * n + 1, lf);
    Solve();
}

