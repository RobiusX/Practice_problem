#include<bits/stdc++.h>
using namespace std;

// Structure to store weight and value of an item
struct Item{
    int weight, value;
};

// Global vector to store all items
vector<Item>item;

// DP table: dp[i][cap] = maximum value using items 0 to i-1 with capacity cap
int dp[500][500];

// Memoization function for 0/1 Knapsack
// i = current item index, cap = remaining capacity
int knapsack(int i, int cap){
    
    // Base case: no items left or no capacity left
    if (i == item.size() || cap == 0)
        return 0;

    // If already computed, return from DP table (memoization)
    if (dp[i][cap] != -1)
        return dp[i][cap];

    // Option 1: Skip current item (don't take it)
    int skip = knapsack(i+1, cap);

    // Option 2: Take current item (if it fits)
    int take = 0;
    if(item[i].weight <= cap){
        take = item[i].value + knapsack(i+1, cap - item[i].weight);
    }

    // Store the maximum value and return
    return dp[i][cap] = max(take, skip);
}

int main()
{
    int n, capacity;
    
    // Read number of items and knapsack capacity
    cin >> n >> capacity;
    
    // Resize vector to hold n items
    item.resize(n);

    // Read weight and value for each item
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].weight >> item[i].value;
    }
    
    // Initialize DP table with -1 (meaning not computed yet)
    memset(dp, -1, sizeof(dp));

    // Call knapsack function and print the maximum value
    cout << knapsack(0, capacity) << endl;

    return 0;
}
