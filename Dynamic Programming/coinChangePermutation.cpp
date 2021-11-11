#include <bits/stdc++.h>
using namespace std; 

int coinChangePerm(int n, vector<int> arr, int target) {
    vector<int> dp(target+1, 0);

    dp[0] = 1;
    for (int i = 1;i <= target; i++) {
        for (int j = 0; j<n;j++) {
            if (i - arr[j] >= 0) {
                dp[i] = dp[i] + dp[i - arr[j]];
            }
        }
    }

    return dp[target];
}

int main() {
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i:arr) {
        cin >> i;
    }

    int target;
    cin >> target;

    cout << "Number of Permutations is: " << coinChangePerm(n,arr,target);
    return 0;
}