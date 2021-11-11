#include <bits/stdc++.h>
using namespace std;

int findMaxValue(int n, vector<int> val, vector<int> wt, int capacity) {
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<=capacity;j++) {
            dp[i][j] = dp[i-1][j];
            if (j - wt[i-1] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - wt[i-1]] + val[i-1]);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;
    cin >> n;

    vector<int> value(n);
    for (auto &i:value) {
        cin >> i;
    }

    vector<int> wt(n);
    for (auto &i:wt) {
        cin >> i;
    }

    int capacity;
    cin >> capacity;

    cout << "Max value is: " << findMaxValue(n, value, wt, capacity);
    return 0;
}