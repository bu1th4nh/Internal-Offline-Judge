#include <bits/stdc++.h>
using namespace std;
//=====================================
//Macro
#define task "WISCHEDULE"

//=====================================
//Typedef and variable
struct Comp {
    int s, f, c;
    bool pick;
};
int n, res, loc;
vector <Comp> vect;

//=====================================
//Functions and procedures
//Initialization
void FileInit(){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
void FileClose(){
    fclose(stdin);
    fclose(stdout);
}

//Process
void Input(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        Comp x;
        scanf("%d%d%d", &x.s, &x.f, &x.c);
        vect.push_back(x);
    }
}
bool cmp(Comp a, Comp b){
    return a.f < b.f;
}
int BinSearch(int c, int d){
    int first, last, i;
    first=0;
    last=d;
    while(first<last)
    {
        i = (first + last + 1) / 2;
        if (vect[i].f <= c) {first=i;} else last=i-1;
    }
    if(vect[first].f <= c) return first;
    return 0;
}
void Process(){
    res = 0;
    sort(vect.begin(), vect.end(), cmp);

}


int main()
{
    FileInit();
    Input();
    Process();
    FileClose();
    return 0;
}
