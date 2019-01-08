#include<bits/stdc++.h>
using namespace std;

main(){
    freopen("DOUBLEGAME.inp","r",stdin);
    freopen("DOUBLEGAME.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    vector<bool> deg(n+1);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        deg[u]=1;
    }
    int ans=0;
    for (int i=1;i<=n;++i){
        int a;
        scanf("%d",&a);
        if (deg[i]) ans ^= a&1;
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
}
