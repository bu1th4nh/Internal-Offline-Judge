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



//Main Procedure
int main()
{
    FileInit();
    cout << "Hello world!" << endl;
    return 0;
}
