//NND
using namespace std;
const int maxn = 2e5;
const long long inf = 1e18 + 703;
#include <bits/stdc++.h>
#define nof "CONVERING"
#define fi nof".INP","r",stdin
#define fo nof".OUT","w",stdout
#define X first
#define Y second
#define foru(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define ford(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define sc scanf
#define pr printf
struct data {
    int x, y;
};
data a[maxn];
int n;
bool cmp(data a, data b){
    return (a.x == b.x ? a.y < b.y : a.x > b.x);
}
int main() {
    freopen(fi);
    freopen(fo);
    sc("%d", &n);
    for (int i=1; i<=n; i++) sc("%d%d", &a[i].x, &a[i].y);
    sort (a+1, a+n+1, cmp);
    long long res = 0;
    int tmp = 0;
    for (int i=1; i<=n; i++) {
        if (a[i].y > tmp) {
            res += a[i].x * (a[i].y-tmp);
            tmp = a[i].y;
        }
    }
    pr ("%d", res);
    fclose(stdin);
    fclose(stdout);
    //for (int i=1; i<=n; i++) cout << a[i].x << " " << a[i].y << "\n";
 return 0;
}
