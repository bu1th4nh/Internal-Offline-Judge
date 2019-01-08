#include "science.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 4096;

int x, y;
int Time = 0, aTime = 0;
int f[N][N];
int cntRow[N], cntCol[N];
pair<int, int> marks[10004];

void mark(int i, int j) {
    assert(i >= 0 && i < N && j >= 0 && j < N);
    assert(++Time <= 10000);
    marks[Time] = {(i + x) % N, (j + y) % N};
}

void neoCall() {
    assert(++Time <= 10000);
    cntRow[marks[Time].second]++;
    cntCol[marks[Time].first]++;
}

int numRow(int j) { return neoCall(), cntRow[j]; } 
int numColumn(int i) { return neoCall(), cntCol[i]; }

void found(int i, int j) {
    assert(i == x && j == y);
    cout << max(Time, aTime) << endl;
    exit(0);
}

int main() {
    cin >> x >> y;
    trinity(); aTime = Time; Time = 0;
    neo(); 
}

