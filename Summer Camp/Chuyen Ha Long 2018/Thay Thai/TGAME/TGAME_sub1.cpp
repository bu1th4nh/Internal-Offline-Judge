#include<bits/stdc++.h>
using namespace std;
template<typename T> ostream& operator<<(ostream& os, vector<T> a){os<<"( ";for(T &x:a)os<<x<<" ";os<<")\n";return os;}
template<typename T> ostream& operator<<(ostream& os, set<T> a){os<<"( ";for(T x:a)os<<x<<" ";os<<")\n";return os;}
template<typename T> ostream& operator<<(ostream& os, pair<T,T> a){os<<"("<<a.first<<" "<<a.second<<") ";return os;}
template<typename T> ostream& operator<<(ostream& os, complex<T> a){os<<"(r="<<a.real()<<" i="<<a.imag()<<") ";return os;}
typedef long long ll;
typedef double dd;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
#define all(a) a.begin(),a.end()
#define DEBUG 1
#define debug(a) if(DEBUG)cout<<#a<<" = "<<a<<endl
#define x first
#define y second
//===========================Head=========================//
const int nmax=1011;

int n,g[nmax],f[nmax][nmax];
vvi e;
vi st;

void dfs(int x){
    st.push_back(x);
    for (int y:e[x]) dfs(y);
}

int main(int argc,char** argv){
    freopen("TGAME.inp","r",stdin);
    freopen("TGAME.out","w",stdout);
    int x,y;
    while (scanf("%d%d%d",&n,&x,&y)==3){
        if (n==0) break;
        e = vvi(n+1);
        for (int i=1;i<=n;++i){
            int p;
            scanf("%d",&p);
            e[p].push_back(i);
        }

        //cal st
        int root = e[0].back();
        st.clear();
        dfs(root);

        //cal f
        for (int i=st.size()-1;i;--i) for (int j=st.size()-1;j;--j){
            int x=st[i], y=st[j];
            f[x][y]=0;
            for (int xx:e[x]) if (f[xx][y]==0) f[x][y]=1;
            for (int yy:e[y]) if (f[x][yy]==0) f[x][y]=1;
        }

        //print
        if (f[x][y]) printf("YES\n");
        else printf("NO\n");
    }
}
