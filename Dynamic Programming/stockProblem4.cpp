// buy and sell stock with cooldown

#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int n, vector<int> prices) {
    int bsp = -prices[0];
    int ssp = 0;
    int csp = 0;

    for (int i=1;i < n; i++) {
        int nbsp = 0, nssp = 0, ncsp = 0;

        if (csp - prices[i] > bsp) {
            nbsp = csp - prices[i];
        } else {
            nbsp = bsp;
        }

        if (bsp + prices[i] > ssp) {
            nssp = bsp + prices[i];
        } else {
            nssp = ssp;
        }

        if (ssp > csp) {
            ncsp = ssp;
        } else {
            ncsp = csp;
        }

        csp = ncsp;
        bsp = nbsp;
        ssp = nssp;
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

    cout << getMaxProfit(n, prices);
    return 0;
}