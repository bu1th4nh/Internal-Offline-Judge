#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macros
#define task "DETAILS"

//=====================================
//Typedef
struct Part
{
    int time, index;
    bool pick = false;
};
typedef vector<Part> VP;
typedef vector<VP> V2P;
int n;
int res1 = 0;
V2P vect;
V2P vect2;
VP res2;

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
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool cmp(Part x, Part y)
{
    return x.time <= y.time;
}

//Input
void Input()
{
    cin >> n;
    for(int i=1; i<=n; ++i)
    {
        VP x;
        for(int j=1; j<=n; ++j)
        {
            Part y;0plm
            cin >> y.time;
            y.index = i;
            x.push_back(y);
        }
        vect.push_back(x);
    }
    vect2 = vect;
}


//Process
void Process()
{
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j) vect2[i][j] = vect[j][i];
    for(int i=0; i<n; ++i)
    {
        sort(vect[i].begin(), vect[i].end(), cmp);

    }
}



//Main program
int main()
{
    //FileInit();
    Input();
    Process();
    //FileClose();
    return 0;
}
