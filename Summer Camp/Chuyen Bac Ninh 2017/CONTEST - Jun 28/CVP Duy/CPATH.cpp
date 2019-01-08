//NND
using namespace std;
const int maxn = 2e5;
const long long inf = 1e18 + 703;
const int base = 2017;
#include <bits/stdc++.h>
#define nof "CPATH"
#define fi nof".INP","r",stdin
#define fo nof".OUT","w",stdout
#define X first
#define Y second
#define foru(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define ford(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define sc scanf
#define pr printf
int n, m, k;
int u[maxn], v[maxn];
//-----------------------------------------------------------------------------------------------------
int A[100][100], B[100][100], C[100][100], res[100][100], d[100][100];
void nhan(int a[100][100], int b[100][100], int c[100][100], int m, int n, int p ) {
   for(int i=1; i<=m; i++)
        for(int j=1; j<=p; j++) {
            c[i][j] = 0;
            for(int k=1; k<=n; k++)
            c[i][j] = (c[i][j]+(a[i][k]%base)*(b[k][j]%base)) % base;
        }
}
//=-----------------------------------------------------------------------------=//
void mu(int a[100][100], int n, int k, int c[100][100]) {
  if (k == 1) {
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            c[i][j]=a[i][j]%base;
  }
  else {
        memset(d,0,sizeof(d));
        mu(a, n, k/2, c);
        nhan(c, c, d, n, n, n);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                c[i][j] = d[i][j] % base;
        if (k%2 == 1) {
            nhan(c,a,d,n,n,n);
            for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                c[i][j] = d[i][j] % base;
        }

  }
}
//-----------------------------------------------------------------------------
void sub2() {
    int f[55][1100];
    memset(f, 0, sizeof(f));
    f[1][0] = 1;
    for (int j=1; j<=k; j++) {
        for (int i=1; i<=n; i++){
            for (int h=1; h<=m; h++) {
                if (v[h] == i) f[i][j] = (f[i][j] + f[u[h]][j-1]) % base;
            }
        }
    }
    //pr ("%d", f[3][4]);
    pr("%d", f[n][k]);
}
int main() {
    freopen(fi);
    freopen(fo);
    sc("%d%d%d", &n, &m, &k);
    for (int i=1; i<=m; i++) {
        sc("%d%d", &u[i], &v[i]);
        A[u[i]][v[i]]++;
    }
    //pr("%d", &f[n][k]);
    if (k <=1000) {sub2(); return 0;}
    else {
        B[1][1] = 1;
        mu(A, n, k, C);
        nhan(C, B, res, n, n, 1);
        pr("%lld",res[n][1]);
    }
    fclose(stdin);
    fclose(stdout);
 return 0;
}
