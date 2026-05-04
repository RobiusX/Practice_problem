#include <bits/stdc++.h>
using namespace std;

int LIS(int i, int p, vector<int> &num, int n) {
    if (i >= n) return 0;

    // option 1: skip current element
    int skip = LIS(i + 1, p, num, n);

    // option 2: take current element if valid
    int take = 0;
    if (p == -1 || num[i] > num[p]) {
        take = 1 + LIS(i + 1, i, num, n);
    }

    return max(take, skip);
}

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << LIS(0, -1, num, n) << endl;

    return 0;
}
