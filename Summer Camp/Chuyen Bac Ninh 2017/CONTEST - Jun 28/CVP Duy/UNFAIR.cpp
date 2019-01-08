//NND
using namespace std;
const int maxn = 2e5;
const long long inf = 1e18 + 703;
#include <bits/stdc++.h>
#define nof "UNFAIR"
#define fi nof".INP","r",stdin
#define fo nof".OUT","w",stdout
#define X first
#define Y second
#define foru(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define ford(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define sc scanf
#define pr printf
int n;
int a[maxn], b[maxn];
int main() {
    freopen(fi);
    freopen(fo);
    sc("%d", &n);
    for (int i=1; i<=n; i++) sc("%d", &a[i]);
    for (int i=1; i<=n; i++) sc("%d", &b[i]);
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    int vt = 1;
    int res = 0;
    int i = 1;
    while (i <= n && vt <=n) {
        if (b[i] > a[vt]) {
            res ++;
            vt ++;
        }
        i++;
    }
    pr("%d", res);
    fclose(stdin);
    fclose(stdout);
 return 0;
}
