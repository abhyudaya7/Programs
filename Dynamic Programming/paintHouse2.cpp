#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,c;
    cin >> n >> c;

    vector<vector<int>> arr(n, vector<int>(c));

    for (int i =0;i<n;i++) {
        for (int j = 0;j<c;j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(c, 0));

    dp[0] = arr[0];

    for (int i=1;i<n;i++) {
        for (int j=0;j<c;j++) {
            int m = INT_MAX;
            for (int k = 0;k<c;k++) {
                if (k != j) {
                    m = min(dp[i-1][k],m);
                }
            }
            dp[i][j] = arr[i][j] + m;
        }
    }

    int ans = INT_MAX;
    for (int i = 0;i<c;i++) {
        ans = min(dp[n-1][i],ans);
    }

    cout << ans;
    return 0;
}