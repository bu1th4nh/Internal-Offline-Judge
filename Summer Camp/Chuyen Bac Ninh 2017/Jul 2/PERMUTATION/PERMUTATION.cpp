#include <bits/stdc++.h>
using namespace std;


string s;
int n, letter[26];
 unsigned long long res;

 unsigned long long fact(int x)
{
    if(x==0) return 1;
    else return (unsigned long long)(x*fact(x-1));
}

int main()
{
    res = 1;
    getline(cin, s);
    n = s.length();
    memset(letter, 0, sizeof(letter));
    /*for (int x = 1; x <= n; ++x)
    {
         res = res * x;
    }*/
    res = fact(n);
    for(int i=0; i<n; ++i) if(letter[i]==n)
    {
        cout << 1;
        return 0;
    }
    for(int i=0; i<n; ++i)
    {
        int aa = static_cast<int>(s[i]) - static_cast<int>('A');
        //cout << aa;
        ++letter[aa];
    }
    for(int i=0; i<26; ++i)
    {
        res /= fact(letter[i]);
    }
    cout << res;
    return 0;
}
