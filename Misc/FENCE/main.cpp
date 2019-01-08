#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "WALL"
#define max (int)(2*1e8)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORli(x, y) for(int i=x; i<y; ++i)

//=====================================
//Typedef
typedef vector<int> vi;
int a[100001], b[100001];
int m, n, res, res2;
vi res3, res4;

//=====================================
//Functions and procedures
//Initialization
void FileInit()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void Init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Input
void Input()
{
    cin >> n;
    FORi(1, n)
    {
        cin >> a[i];
    }
    cin >> m;
    FORi(1, m)
    {
        cin >> b[i];
    }
}

//Check
bool check(int k)
{
    int j = 1;
    int cnt = 0;
    vi tag, pick;
    FORi(1, n)
    {
        if(a[i]<k)
        {
            while(j<=m && (a[i]+b[j])<k) ++j;
            if(j<=m && (a[i]+b[j])>=k)
            {
                tag.push_back(i);
                pick.push_back(j);
                ++j;
                ++cnt;
            }
        }
        if(j>m && a[i]<k) return false;
    }
    res3 = tag;
    res4 = pick;
    res2 = cnt;
    return true;
}

//Process
void Process()
{
    res = 0;
    int first = 0, last = max;
    while(first <= last)
    {
        int mid = (first + last)/2;
        if (check(mid))
        {
            res = mid;
            first = mid + 1;
        }
        else last = mid - 1;
    }
    cout << res << " " << res2 << endl;
    FORli(0, res3.size())
    {
        cout << res3[i] << " " << res4[i] << endl;
    }
}

int main()
{
    FileInit();
    Init();
    Input();
    Process();
    FileClose();
    return 0;
}
