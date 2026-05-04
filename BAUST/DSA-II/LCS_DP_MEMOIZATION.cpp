#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1005][1005];

int LCS(int i, int j) {
    int n = s1.length();
    int m = s2.length();

    if (i == n || j == m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + LCS(i + 1, j + 1);
    } else {
        int op1 = LCS(i, j + 1);
        int op2 = LCS(i + 1, j);
        return dp[i][j] = max(op1, op2);
    }
}

int main() {
    cout << "Enter 2 strings:" << endl;
    cin >> s1 >> s2;

    memset(dp, -1, sizeof(dp));

    cout << "LCS: " << LCS(0, 0) << endl;

    return 0;
}
