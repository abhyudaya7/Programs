// climb stairs with min moves 
#include <bits/stdc++.h>
using namespace std;

int getMinMoves(int n, vector<int> arr) {

    vector<int> dp(n+1, -1);
    dp[n] = 0;

    for (int i = n-1; i >= 0; i--) {
        if (arr[i] > 0) {
            int m = INT_MAX;

            for (int j = 1; j <= arr[i] and i + j < dp.size(); j++) {
                if (dp[i + j] != -1) {
                    m = min(m, dp[i + j]);
                }
            }

            if (m != INT_MAX) {
                dp[i] = m + 1;
            }
        }
    }

    return dp[0];
}

int main() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    for (auto &i: arr) {
        cin >> i;
    }

    cout << getMinMoves(n,arr);
    return 0;
}