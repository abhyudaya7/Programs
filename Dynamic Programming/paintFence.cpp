// paint fence problem leetcode

#include <bits/stdc++.h>
using namespace std;

int countWays(int n,int k) {
    int same = k * 1;
    int diff = k * (k-1);
    int total = same + diff;
    
    for (int i=3;i <= n;i++) {
        same = diff * 1;
        diff = total * (k-1);
        total = same + diff;
    }

    return total;
}

int main() {
    int n,k;
    cin >> n >> k;

    cout << countWays(n,k);
    return 0;
}