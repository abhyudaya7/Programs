// infinte transactions allowed

#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int n, vector<int> arr) {
    int buy_date = 0;
    int sell_date = 0;  
    int profit = 0;

    for (int i = 1; i < n ;i++) {
        if (arr[i] >= arr[i-1]) {
            sell_date++;
        }
        else { 
            profit += arr[sell_date] - arr[buy_date];
            sell_date = buy_date = i;
        }
    }

    profit += arr[sell_date] - arr[buy_date];

    return profit;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &i :arr) {
        cin >> i;
    }

    cout << getMaxProfit(n, arr);
    return 0;
}