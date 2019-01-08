#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros


//=====================================
//Typedef
string s;
int n;


//=====================================
int main()
{
    cin >> n;
    cin >> s;
    string s1 = s;
    int i = (int)s.length() - 1;
    while(i > 0 && s[i] == '1') --i;
    if(i == 0)
    {
        cout << -1;
        return 0;
    }
    else
    {
        s[i] = '1';
        for(int j=i+1; j<n; ++j) s[j] = '0';
        cout << s;
    }
    return 0;
}
