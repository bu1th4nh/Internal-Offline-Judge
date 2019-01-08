//=====================================
//Libraries and namespace
#include <bits/stdc++.h>
using namespace std;


//=====================================
//Macro
#define sp ' '
#define el '\n'
#define task "DSUM"
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++i)
#define FORl(i, a, b) for(int (i) = (a); (i) < (b); ++i)
#define FORb(i, a, b) for(int (i) = (a); (i) >= (b); --i)
#define FORlb(i, a, b) for(int (i) = (a); (i) > (b); --i)
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define FILEOP()                            \
{                                           \
    freopen(task".inp", "r", stdin);        \
    freopen(task".out", "w", stdout);       \
}

template<class T> T _abs(T x)
{
    return (x < 0) ? -x : x;
}

//=====================================
//Typedefs
string N;
int sum;


//=====================================
//Function and procedures
void FileInit()
{
    FILEOP();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    char str[256];
    scanf("%s", &str);
    N = string(str);
    for(auto x: N) sum += x - '0';
}

//Subtask 1
string tostring(int x)
{
    stringstream ss;
    ss << x;
    return string(ss.str());
}
void Sub1()
{
    int res = 0;
    int p = atol(N.c_str());
    FOR(i, 1, p)
    {
        int k = 0;
        string tmp = tostring(i);
        for(auto x: tmp) k += x - '0';
        if(k == sum) ++res;
    }
    cout << res << el;
}



//Main Procedure
int main()
{
    FileInit();
    Enter();
    Sub1();
    return 0;
}
