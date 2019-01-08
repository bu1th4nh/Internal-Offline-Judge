#include <bits/stdc++.h>
using namespace std;
//=====================================
//Typedef and variable
struct comp {
    int a, b;
    bool c;
};
vector <comp> vect;
int n, res;


//=====================================
//Functions and procedures
//Initialization
void FileInit(){
    freopen("PHANMAY.inp", "r", stdin);
    freopen("PHANMAY.out", "w", stdout);
}

void FileClose(){
    fclose(stdin);
    fclose(stdout);
}

void Init(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Process
void Input(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        comp x;
        scanf("%d%d", &x.a, &x.b);
        vect.push_back(x);
    }
}
bool cmp(comp x, comp y){
    return x.a < y.a;
}
void Process()
{
    res = 0;
    sort(vect.begin(), vect.end(), cmp);
    for(int i=0; i<n; i++) vect[i].c = 0;
    for(int i=0; i<n-1; i++)
    {
        if(!vect[i].c)
        {
            res++;
            int stop = vect[i].b;
            vect[i].c = 1;
            for(int j=i + 1; j<n; j++)
            {
                if ((vect[j].a >= stop)&&(!vect[j].c))
                {
                    vect[j].c = 1;
                    stop = vect[j].b;
                }

            }
        }
    }
    printf("%d",res);

}


int main()
{
    FileInit();
    Input();
    Process();
    FileClose();
    return 0;
}
