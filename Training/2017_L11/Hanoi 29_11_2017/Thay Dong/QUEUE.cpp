#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#define NAME "QUEUE."
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
#define maxn (50000+5)
int n;
int x[maxn],y[maxn];

void input(){
    cin>>n;
    FOR(i,1,n){
        cin>>x[i]>>y[i];
    }

//    FOR(i,1,n){x[i]+=n; y[i]+=n;}
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
}

int tv(int l, int r){
    int n=r-l+1;
//    if (n&1) return l+(n/2+1)-1;
//    else return l+(n/2+1)-1;
    return l+(n/2+1)-1;
}

ll tinh(int r, int c){
    ll sx=0, sy=0;
    int xx[maxn],yy[maxn];
    int times=0, i=1, mid;
    while (i<=n){
        FOR(k,i,i+r-1) xx[k]=x[k]-times;
        i+=r; times++;
    }

    sort(xx+1,xx+n+1);
    times=0; i=1; mid=tv(1,n);
    while (i<=n){
        FOR(k,i,i+r-1) sx+=abs(xx[mid]+times-x[k]);
        i+=r; times++;
    }

    times=0; i=1;
    while (i<=n){
        FOR(k,i,i+c-1) yy[k]=y[k]-times;
        i+=c; times++;
    }
    sort(yy+1,yy+n+1);
    i=1; mid=tv(1,n); times=0;
    while (i<=n){
        FOR(k,i,i+c-1) sy+=abs(yy[mid]+times-y[k]);
        i+=c; times++;
    }
    return (sx+sy);
}

ll res=1e17;

void Xuli(){
    FOR(i,1,int(sqrt(n)))
    if ((n%i)==0){
        res=min(res,tinh(i,n/i));
        res=min(res,tinh(n/i,i));
    }
    cout<<res;
}

int main()
{
    freopen(NAME"inp","r",stdin);
    freopen(NAME"out","w",stdout);
    iostream::sync_with_stdio(0);
    srand(time(NULL));
    input();
    Xuli();
//    tinh(1,3); cout<<"\n"; tinh(3,1);
//    cout<<tv(2,10);
}
