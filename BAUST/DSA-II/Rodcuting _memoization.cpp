#include<bits/stdc++.h>
using namespace std;

vector<int> price;
int n;
int dp[500][500];   // dp[i][len]

// Memoized function
int RC(int i, int len){
    // Base case
    if(i > n || len == 0)
        return 0;

    // Check dp
    if(dp[i][len] != -1)
        return dp[i][len];

    // Skip case
    int skip = RC(i + 1, len);

    // Take case (unbounded)
    int take = 0;
    if(i <= len){
        take = price[i] + RC(i, len - i);
    }

    // Store and return
    return dp[i][len] = max(take, skip);
}

int main(){
    int len;
    cin >> n >> len;

    price.resize(n+1);

    for(int i = 0; i <= n; i++){
        cin >> price[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << RC(1, len) << endl;

    return 0;
}
