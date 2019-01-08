#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter limit: ";
    cin >> n;
    system("pause");
    srand(time(NULL));
    cout << "R4nd0m: " << rand()%n + 1;
    return 0;
}
