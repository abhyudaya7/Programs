#include <bits/stdc++.h>
using namespace std; 

int coinChange(int n, vector<int> arr, int amt) {
    vector<int> dp(amt+1, 0);
    dp[0] = 1;
    for (int i=0;i < n;i++) {
        for (int j = arr[i]; j <= amt;j++) {
            dp[j] = dp[j] + dp[j - arr[i]];
        }
    }

    return dp[amt];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &i : arr) {
        cin >> i;
    }

    int amount;
    cin >> amount;
    
    cout << "Minimum combinations are: " << coinChange(n,arr,amount);
    return 0;
}