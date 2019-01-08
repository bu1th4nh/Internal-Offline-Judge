#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <iomanip>

using namespace std;
#define For(i , a , b) for (int i = a , _b = b ; i <= _b ; ++i)
#define Ford(i , a  ,b) for (int i = a , _b = b : i >= _b ; --i)
#define Rep(i , n) for (int i = 0 , _n = n ; i < _n ; ++i)
#define sz(A) ((int)A.size())
#define LL(x) (x << 1)
#define RR(x) ((x << 1) | 1)

typedef pair<double, double> pt;

const int maxn = 100000 + 123;
const long double eps = 1e-7;
int n;
pt a[maxn];

long double sqr(const double a) {
    return 1LL * a * a;
}
long double sqrDis(pt &a, pt &b) {
    return sqr(a.first - b.first) + sqr(a.second - b.second);
}

void ReadData() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a + 1, a + 1 + n);
}

struct cmp{
    bool operator() (int i, int j) const {
        return a[i].second < a[j].second;
    }
};
set<int, cmp > S; 

void Process() {
    long double res = sqrDis(a[1], a[2]);

    int j = 1;
    for (int i = 1; i <= n; i++) {
        ///first get answer
        while (j <= n && a[i].first - a[j].first > sqrt(res) + eps) {
            ///pop j
            S.erase(j++);
        }
        a[0].second = a[i].second - (int)sqrt(res) - 2;
        set<int, cmp>::iterator it = S.lower_bound(0);
        while (it != S.end()) {
            int id = (*it);
            if (a[id].second > a[i].second + sqrt(res) + eps) break;
            res = min(res, sqrDis(a[id], a[i]));
            ++it;
        }
        ///second insert point 
        S.insert(i);
    }

    cout << fixed << setprecision(4);
  //  cout << res << endl;
    cout << (double) sqrt(res) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("nearest.inp", "r", stdin);
    freopen("nearest.out", "w", stdout);
    ReadData();
    Process();

    return 0;

}