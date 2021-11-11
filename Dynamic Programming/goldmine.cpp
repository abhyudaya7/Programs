#include <bits/stdc++.h>
using namespace std;

int maxGold(int r, int c, vector<vector<int>> arr) {
    vector<vector<int>> dp(r, vector<int>(c, 0));

    for (int j = c-1; j>=0;j--) {
        for (int i=0; i < r;i++) {
            if (j == c-1) {
                dp[i][j] = arr[i][j];
            }
            else if (i == 0) {
                dp[i][j] = arr[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
            }
            else if (i == r-1) {
                dp[i][j] = arr[i][j] + max(dp[i][j+1], dp[i-1][j+1]);
            }
            else {
                dp[i][j] = arr[i][j] + max(dp[i][j+1], max(dp[i+1][j+1], dp[i-1][j+1]));
            }
        }
    }

    int m = INT_MIN;
    for (int i = 0;i<r;i++) {
        m = max(m, dp[i][0]);
    }

    return m;
}

int main() {
    int r,c;
    cin >> r >> c;
    vector<vector<int>> arr;

    for (int i=0;i<r;i++) {
        vector<int> temp;
        for (int j=0;j<c;j++) {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        arr.push_back(temp);
        temp.clear();
    }

    cout << maxGold(r,c,arr);
    return 0;
}