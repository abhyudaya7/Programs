// infinte transactions with transaction fee included

#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int n, vector<int> prices, int fee) {
    int bsp = -1 * prices[0]; // to store the buy state profit (having one extra share)
    int ssp = 0; // to store the sale state profit (having no share)

    for (int i=1; i<n;i++) {
        int nbsp = 0;
        int nssp = 0;

        if (ssp - prices[i] > bsp) {
            nbsp = ssp - prices[i];
        } else {
            nbsp = bsp;
        }

        if (bsp + prices[i] - fee > ssp) {
            nssp = bsp + prices[i] - fee;
        }else {
            nssp = ssp;
        }

        ssp = nssp;
        bsp = nbsp;
    }

    return ssp;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (auto &i: prices) {
        cin >> i;
    }

    int fee;
    cin >> fee;

    cout << getMaxProfit(n, prices, fee);
    return 0;
}