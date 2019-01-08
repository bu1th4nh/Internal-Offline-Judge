//=====================================
//Libraries and namespace
#include <bits/stdc++.h>
using namespace std;


//=====================================
//Macro
#define sp ' '
#define el '\n'
#define fi first
#define se second
#define task "DSUM"
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++i)
#define FORl(i, a, b) for(int (i) = (a); (i) < (b); ++i)
#define FORb(i, a, b) for(int (i) = (a); (i) >= (b); --i)
#define FORlb(i, a, b) for(int (i) = (a); (i) > (b); --i)
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define FILEOP()                            \
{                                           \
    freopen(task".inp", "r", stdin);        \
    freopen(task".out", "w", stdout);       \
}

template<class T> T _abs(T x)
{
    return (x < 0) ? -x : x;
}

//=====================================
//Typedefs
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<ii> sii;

int n, m;
vb avail;
vvi adj;
sii st;


//=====================================
//Function and procedures
void FileInit()
{
    FILEOP();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    int u, v;
    scanf("%d%d", &n, &m);

    avail = vb(n+1, 1);
    adj = vvi(n+1);

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        if(u < v) swap(u, v);
        st.insert(ii(u, v));
    }

    for(auto x: st)
    {
        adj[x.fi].push_back(x.se);
        adj[x.se].push_back(x.fi);
    }
}

//DFS
void DFS(int u, int &p)
{
    ++p;
    avail[u] = 0;
    for(int v: adj[u]) if(avail[v] == 1)
    {
        DFS(v, p);
    }
}
ll computePath(int len)
{
    return 1LL * len * len * (len + 1) - (1LL * len * (len + 1) * (len - 1) / 3) * 2;
}

//Process
void Solve()
{
    ll res = 0LL;
    FOR(i, 1, n)
    {
        if(avail[i] && adj[i].size() == 1)
        {
            int tmp = 0;
            DFS(i, tmp);

            res += computePath(tmp - 1);
        }
    }
    FOR(i, 1, n) if(avail[i])
    {
        int tmp = 0;
        DFS(i, tmp);

        if(tmp & 1)
        {
            int x = (tmp-1) / 2;
            res += computePath(x) * 2 + 2;
        }
        else
        {
            int x = tmp / 2;
            res += computePath(x) + computePath(x-1) + 2;
        }
    }

    cout << res << el;
}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
