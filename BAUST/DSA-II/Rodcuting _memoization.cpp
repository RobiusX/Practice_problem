#include<bits/stdc++.h>
using namespace std;

int coin[] = {1, 2, 3};
int n = 3;

int dp[100][100];

// Memoization function
int coinChange(int i, int target){

    // Base case
    if(target == 0)
        return 1;

    if(i >= n || target < 0)
        return 0;

    // Check dp
    if(dp[i][target] != -1)
        return dp[i][target];

    // Skip current coin
    int skip = coinChange(i + 1, target);

    // Take current coin
    int take = 0;

    if(target >= coin[i]){
        take = coinChange(i, target - coin[i]);
    }

    // Store and return
    return dp[i][target] = take + skip;
}

int main(){

    int target;
    cin >> target;

    memset(dp, -1, sizeof(dp));

    cout << coinChange(0, target) << endl;

    return 0;
}
