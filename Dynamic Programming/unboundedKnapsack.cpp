#include <bits/stdc++.h>
using namespace std;

int findMaxValue(int n, vector<int> val, vector<int> wt, int cap) {
    vector<int> dp(cap+1, 0);

    for (int i=1;i < dp.size(); i++) {
        for (int j = 0;j<n;j++) {
            if (i - wt[j] >= 0) {
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
            }
        }
    }

    return dp[cap];
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