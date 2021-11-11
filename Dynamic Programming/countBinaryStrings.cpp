// count the number of binary string with no consecutive zeros of lenght n

#include <bits/stdc++.h>
using namespace std;

int countStrings(int n) {
    vector<int> dp0(n+1, 0);
    vector<int> dp1(n+1, 0);
    dp0[1] = dp1[1] = 1;

    for (int i=2;i<= n;i++) {
        dp1[i] = dp1[i-1] + dp0[i-1];
        dp0[i] = dp1[i-1];
    }

    return dp0[n] + dp1[n]; 
}

int countStringsLinearSpace(int n) {
    int prev_count_zeros = 1;
    int prev_count_ones = 1;

    for (int i = 2;i<=n;i++) {
        int new_count_zeros = prev_count_ones;
        int new_count_ones = prev_count_ones + prev_count_zeros;

        prev_count_zeros = new_count_zeros;
        prev_count_ones = new_count_ones;
    }

    return prev_count_ones + prev_count_zeros;
}

int main() {
    int n;
    cin >> n;

    cout << countStringsLinearSpace(n);
    return 0;
}