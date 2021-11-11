// divide n people into k teams such that no team is left empty

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    vector<vector<int>> dp(k+1, vector<int>(n+1,0));

    for (int i=1 ; i <= k; i++) {
        for (int j=1; j <= n; j++) {
            if (j < i) 
                dp[i][j] = 0;
            else if (j == i) 
                dp[i][j] = 1;
            else {
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1] * i;
            }
        }
    }

    cout << dp[k][n]; 

    return 0;
}