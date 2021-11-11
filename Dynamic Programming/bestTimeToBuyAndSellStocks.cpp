// single transaction allowed

#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int n, vector<int> arr) {
    int least_so_far = INT_MAX;
    int max_profit = 0;
    int profit_today = 0;

    for (int i = 0;i < n; i++) {
        if (arr[i] < least_so_far) {
            least_so_far = arr[i];
        }

        profit_today = arr[i] - least_so_far;

        if (profit_today > max_profit) {
            max_profit = profit_today;
        }
    }

    return max_profit;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) {
        cin >> i;
    }

    cout << getMaxProfit(n, arr);
    return 0;
}