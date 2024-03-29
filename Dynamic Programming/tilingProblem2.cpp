// number of ways of tiling a m*n floor with m*1 tiles

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> dp(n+1, 0);
    for (int i = 1;i <= n;i++) {
        if (i < m) {
            dp[i] = 1;
        }
        else if (i == m) {
            dp[i] = 2;
        }
        else {
            dp[i] = dp[i-1] + dp[i - m];
        }
    }

    cout << dp[n];
    return 0;
}