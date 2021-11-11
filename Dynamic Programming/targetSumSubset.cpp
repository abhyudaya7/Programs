#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) {
        cin >> i;
    }

    int target; 
    cin >> target;

    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

    for (int i = 0; i <= n;i++) {
        for (int j = 0; j <= target;j++) {

            if (i == 0 and j == 0) {
                dp[i][j] = true;
            }
            else if (i == 0) {
                dp[i][j] = false;
            }
            else if (j == 0) {
                dp[i][j] = true;
            }
            else { 
                if (dp[i-1][j]) {
                    dp[i][j] = true;
                }
                else if (j - arr[i-1] >= 0 and dp[i-1][j-arr[i-1]]) {
                    dp[i][j] = true; 
                }
            }
        }
    } 

    if (dp[n][target]) {
        cout << "There exists a subset with sum equal to " << target << endl;
    }
    else {
        cout << "There exist no such subset with sum equal to " << target << endl;
    }

    return 0;
}