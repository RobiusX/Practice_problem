#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────
// 1. RECURSIVE
// ─────────────────────────────────────────
int LCS_recursive(int i, int j, string &s1, string &s2) {
    if (i == s1.length() || j == s2.length())
        return 0;

    if (s1[i] == s2[j])
        return 1 + LCS_recursive(i + 1, j + 1, s1, s2);

    return max(LCS_recursive(i + 1, j, s1, s2),
               LCS_recursive(i, j + 1, s1, s2));
}

// ─────────────────────────────────────────
// 2. MEMOIZATION (Top-Down)
// ─────────────────────────────────────────
int dp_memo[1001][1001];

int LCS_memo(int i, int j, string &s1, string &s2) {
    if (i == s1.length() || j == s2.length())
        return 0;

    if (dp_memo[i][j] != -1)
        return dp_memo[i][j];

    if (s1[i] == s2[j])
        return dp_memo[i][j] = 1 + LCS_memo(i + 1, j + 1, s1, s2);

    return dp_memo[i][j] = max(LCS_memo(i + 1, j, s1, s2),
                                LCS_memo(i, j + 1, s1, s2));
}

// ─────────────────────────────────────────
// 3. TABULATION (Bottom-Up)
// ─────────────────────────────────────────
int LCS_tabulation(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

// ─────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────
int main() {
    memset(dp_memo, -1, sizeof(dp_memo));  // ← Move HERE, at the start
    
    string s1, s2;
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    // Recursive
    cout << "\nRecursive LCS: " << LCS_recursive(0, 0, s1, s2);

    // Memoization
    cout << "\nMemoization LCS: " << LCS_memo(0, 0, s1, s2);

    // Tabulation
    cout << "\nTabulation LCS: " << LCS_tabulation(s1, s2);

    cout << endl;
    return 0;
}
