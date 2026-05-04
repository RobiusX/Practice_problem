#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int LIS(int i, int p, vector<int> &num, int n) {
    if (i >= n) return 0;

    if (dp[i][p + 1] != -1) return dp[i][p + 1];

    // skip current element
    int skip = LIS(i + 1, p, num, n);

    // take current element
    int take = 0;
    if (p == -1 || num[i] > num[p]) {
        take = 1 + LIS(i + 1, i, num, n);
    }

    return dp[i][p + 1] = max(take, skip);
}

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << LIS(0, -1, num, n) << endl;

    return 0;
}
