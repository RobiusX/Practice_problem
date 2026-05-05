/*
 * Rod Cutting Problem - Memoization Approach
 * Problem: Given a rod of length 'len' and prices for different rod sizes,
 * find the maximum profit by cutting the rod into pieces.
 * 
 * Approach: Dynamic Programming with Memoization (Top-Down)
 * Time Complexity: O(n * len)
 * Space Complexity: O(n * len) for DP table
 */

#include<bits/stdc++.h>
using namespace std;

// Array to store prices: price[i] = price of rod of length i
vector<int> price;

// n = number of different rod sizes available
int n;

// DP memoization table: dp[i][len] = max profit when considering rods from size i with remaining length len
// Initialized to -1 to indicate uncomputed states
int dp[500][500];

/**
 * RC - Recursive function with memoization to find maximum profit
 * 
 * @param i : Current rod size being considered (from 1 to n)
 * @param len : Remaining length of rod available
 * @return : Maximum profit achievable with current parameters
 */
int RC(int i, int len){
    // Base case: if rod size exceeds available sizes or no length left, return 0
    if(i > n || len == 0)
        return 0;

    // Check if this state is already computed
    if(dp[i][len] != -1)
        return dp[i][len];

    // Option 1: Skip current rod size and move to next size
    int skip = RC(i + 1, len);

    // Option 2: Take current rod size (unbounded - can take multiple pieces)
    int take = 0;
    if(i <= len){
        // If current rod size fits, take it and solve for remaining length
        take = price[i] + RC(i, len - i);
    }

    // Store the maximum of both options in DP table and return
    return dp[i][len] = max(take, skip);
}

int main(){
    // Read number of rod sizes and rod length
    int len;
    cin >> n >> len;

    // Resize price vector to store prices for rod sizes 0 to n
    price.resize(n+1);

    // Read prices for each rod size (1-indexed)
    for(int i = 0; i <= n; i++){
        cin >> price[i];
    }

    // Initialize DP table with -1 (indicating uncomputed states)
    memset(dp, -1, sizeof(dp));

    // Call recursive function starting from rod size 1 with total length
    // Print the maximum profit
    cout << RC(1, len) << endl;

    return 0;
}