// 2 transactions allowed 

#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int n, vector<int> prices) {

    int least_so_far = prices[0];
    int profit_today = 0;
    vector<int> max_profit_so_far(n, 0);

    for (int i=1;i < n;i++) {
        least_so_far = min(least_so_far, prices[i]);

        profit_today = prices[i] - least_so_far;

        max_profit_so_far[i] = max(profit_today, max_profit_so_far[i-1]);
    }

    int max_so_far = prices[n-1];
    vector<int> mpsf(n, 0);

    for (int i = n-2; i >= 0;i--) {
        max_so_far = max(max_so_far, prices[i]);

        profit_today = max_so_far - prices[i];

        mpsf[i] = max(profit_today, mpsf[i+1]);
    }

    int ans = 0;
    for (int i=0;i < n; i++) {
        ans = max(ans, max_profit_so_far[i] + mpsf[i]);
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (auto &i: prices) {
        cin >> i;
    }

    cout << getMaxProfit(n, prices);
    return 0;
}

