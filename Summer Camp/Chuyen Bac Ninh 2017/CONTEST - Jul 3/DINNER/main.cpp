#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "DINNER"
#define MOD (int)(1e9+7)



//=====================================
//Typedef
int T, n;



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
    srand(time(NULL));
}

void Input()
{
    cin >> T;
}

void r4nd0m()
{
    cout << rand()%MOD;
}

int main()
{
    srand(time(NULL));
    FileInit();
    Input();
    for(int i=1; i<=T; ++i) r4nd0m();
    FileClose();
    return 0;
}
