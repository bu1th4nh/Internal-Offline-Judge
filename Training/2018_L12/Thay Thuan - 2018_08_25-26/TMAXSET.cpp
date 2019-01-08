#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define fi first
#define se second
#define LL long long
#define filename "ch."
using namespace std;
const int N=201;
vector<int> G[N];
vector<int> children[N];
int f[N][2];
int w[N] ;
int n,m,t,q,k;
int dd[N] ,ok[N];
int a[N];
void dfs(int u)
{
    dd[u] = 1 ;
    for(int v:G[u]) if(!dd[v]) {
        children[u].push_back(v);
        dfs(v);
    }
}
int solve(int v,int k)
{
    if(children[v].size() ==0 )
    {
        if(k==0) return f[v][k]=0;
        else {
                if( ok[v]==1 ) return f[v][k] = max( 0,w[v] ) ;
                else return f[v][k] = 0;
        }
    }

    if(f[v][k]!=0) return f[v][k];

    if(k==0)   // ko xet dinh v
    {
        for( int u : children[v]  ) if( solve(u,1) > 0)
            f[v][0] += solve(u,1);
    }
    if(k==1)   // xet dinh v
    {
        for( int u:children[v] )  if( solve(u,0) > 0)
            f[v][1] += solve(u,0);
        if(ok[v]) f[v][1]+=max( 0, w[v] );
        f[v][1] = max(f[v][1],solve(v,0));
    }
    return f[v][k];
}
int main()
{
  //  freopen(filename"INP","r",stdin);
   // freopen(filename"OUT","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        FOR(i,0,n-1) cin >>w[i] , G[i].clear(),children[i].clear(), dd[i] = 0;
        FOR(i,1,m){
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(0);
        cin >> q;
        FOR(i,1,q)
        {
            cin >> k;
            FOR(t,0,n) FOR(j,0,1) f[t][j] = 0;
            FOR(j,0,n) ok[j]=0;
            FOR(j,1,k) cin >> a[j] , ok[a[j]]=1;
            int res=solve(0,1);
            cout << res<<'\n';
        }
        cout <<'\n';
    }
}
