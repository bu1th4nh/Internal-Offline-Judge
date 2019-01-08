#include <bits/stdc++.h>
using namespace std;
//=====================================                     //Face thầy Bình: binhlt68@gmail.com
//Macros
#define task "ANDO"
#define maxk 31

//=====================================
//Typedef
vector <long long> vect;
vector <bool> pick;
int n, nT;
long long res;

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
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        int64_t x;
        scanf("%I64d", &x);
        vect.push_back(x);
        pick.push_back(true);
    }
}

//Process
void Process()
{
    int cnt = 0;
    for(int k=maxk; k>=0; --k)
    {
        int c1 = 0;
        vector<int> dnf;
        for(int i=0; i<n; ++i)
        {
            if(pick[i])
            {
                if (((vect[i] >> k)&1)==1) ++c1;
                else dnf.push_back(i);
            }
        }
        if (c1>=2) for(int j=0; j<(int)dnf.size(); ++j) pick[dnf[j]] = false;
    }
    vector<int> choose;
    for(int i=0; i<n; i++)
    {
        if(pick[i]&&(cnt<2))
        {
            choose.push_back(i);
            ++cnt;
        }
    }
    printf("%I64d", (int64_t) (vect[choose[0]]&vect[choose[1]]));
}


int main()
{
    FileInit();
    Input();
    Process();
    FileClose();
    return 0;
}
