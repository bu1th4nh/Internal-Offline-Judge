#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "SWINDOW"


//=====================================
//Typedef
typedef vector<int> vi;
string T;
string P;
int k, n, m, res;
vi z;

//=====================================
//Functions and procedures
//Initialization
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

//Input
void Input()
{
    getline(cin, T);
    getline(cin, P);
    cin >> k;
    n = T.length();
    m = P.length();
    //cout << endl << T << endl << P << endl << k;
}

//Process
vector<int> z_function(string s){
    int n = (int)s.length();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r)z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])++z[i];
        if(i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
    }
    return z;
}

int Process()
{
    string XXX = P + '*' + T;
    z = z_function(XXX);
    res = 0;
    if(m > k)
    {
        cout << 0;
        return 0;
    }
    int t = k - m, prev = m;;
    for(int i=m+1; i <= (m + n + 1) - k + 1; ++i)
    {
        if (z[i]==m)
        {
            if(i-m < t+1)
            {
                res += (prev < m + 1) ? (i-m) : ((i-m)-prev);
            }
            else
            {
                res += (prev < i - t) ? (t + 1) : ((t + 1) - (prev - (i - t) + 1));
            }
            prev = i;
        }
    }
    cout << res;
    return 0;
}


int main()
{
    //FileInit();
    Init();
    Input();
    Process();
}
