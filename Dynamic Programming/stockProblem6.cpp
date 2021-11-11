// maximum profit with 'k' transactions allowed

#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int n, vector<int> prices, int k) {
    vector<vector<int>> dp(k+1, vector<int>(n,0));

    for (int t = 1;t <= k;t++) {
        int m = INT_MIN;
        for (int d = 1;d < n;d++) {
            dp[t][d] = dp[t][d-1];

            // for (int pd = 0;pd < d; pd++) {
            //     dp[t][d] = max(dp[t][d], prices[d] - prices[pd] + dp[t-1][pd]);
            // }

            m = max(m, dp[t-1][d-1] - prices[d-1]);

            dp[t][d] = max(dp[t][d], m + prices[d]);
        }
    }

    return dp[k][n-1]; 
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (auto &i: prices) {
        cin >> i;
    }

    int k;
    cin >> k;

    cout << getMaxProfit(n, prices, k);
    return 0;
}