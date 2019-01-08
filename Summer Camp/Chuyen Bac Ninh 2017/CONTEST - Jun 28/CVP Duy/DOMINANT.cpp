//NND
using namespace std;
const int maxn = 2e5;
const long long inf = 1e18 + 703;
#include <bits/stdc++.h>
#define nof "DOMINANT"
#define fi nof".INP","r",stdin
#define fo nof".OUT","w",stdout
#define X first
#define Y second
#define foru(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define ford(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define sc scanf
#define pr printf
int n;
string s;
int a[maxn];
void sub1() {
    int res = 0;
    int res1 = 0;
    for (int k=n; k>=0; k--) {
        for (int i=k; i<=n; i++) {
            if (2*(a[i] - a[i-k]) > k){
                res = k;
                res1 ++;
            }
        }
        if (res != 0){
            cout << res << " " << res1;
            return;
        }
    }
    //else pr("1");
}
int main() {
    freopen(fi);
    freopen(fo);
    cin >> s;
    n = s.size();
    for (int i=0; i<n; i++) {
        a[i+1] = a[i] + (s[i] - 48);
    }
    sub1();
    fclose(fi);
    fclose(fo);
    //for (int i=0; i<n; i++) cout << a[i] << " " ;
 return 0;
}
