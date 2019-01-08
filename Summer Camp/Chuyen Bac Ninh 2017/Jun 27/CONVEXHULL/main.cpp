#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "CONVEXHULL"
#define inf INFINITY

//=====================================
//Typedef and variable declaration
typedef pair<int, int> p2i;
typedef long long ll;
vector <p2i> dots;
int n, m;
p2i leftmost, rightmost, uppermost, lowermost;

//=====================================
//Functions and procedures
//File I/O
void FileInit()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void Init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    leftmost.first = inf;
    rightmost.first = -inf;
    uppermost.second = -inf;
    lowermost.second = inf;
}
//Input
void Input()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        p2i x;
        scanf("%d%d", &x.first, &x.second);
        dots.push_back(x);
        leftmost = (leftmost.first > x.first) ? x : leftmost;
        rightmost = (rightmost.first > x.first) ? rightmost : x;
        uppermost = (uppermost.second > x.second) ? uppermost : x;
        lowermost = (lowermost.second > x.second) ? lowermost : x;
    }
}
//Preprocess
void Preprocess()
{

}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
