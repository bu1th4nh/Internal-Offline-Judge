#include <bits/stdc++.h>

using namespace std;

vector <int> a;
int n;

void Init()
{
    freopen("QUEUE.inp", "r", stdin);
    freopen("QUEUE.out", "w", stdout);
}

void Close()
{
    fclose(stdin);
    fclose(stdout);
}

void QuickSort(int L, int H)
{
    //srand(static_cast<unsigned int>(time(0)));
    int i, j, pivot;
    i    = L;
    j    = H;
    pivot= a[(L+H)/2];
    do
    {
        while (a[i]<pivot) {i++;}
        while (a[j]>pivot) {j--;}
        if (i<=j)
        {
            swap(a[i], a[j]);
            if(i!=j) cout << i+1 << " " << j+1 << endl;
            i++;
            j--;
        }
    }
    while (i<j);
    if (L<j) QuickSort(L, j);
    if (i<H) QuickSort(i, H);
}

void Input()
{
    //cout << "n= " << endl;
    cin >> n;
    for (int i=1; i<=n; ++i)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
}

int main()
{
    //Init();
    Input();
    QuickSort(0, n-1);
    //Close();
    return 0;
}
