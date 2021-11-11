#include <bits/stdc++.h>
using namespace std;

// memoization approach
long long fib(int n, map<int,long long> &m) {
    if (n <= 1) {
        return n;
    }
    if (m.count(n) != 0) {
        return m[n];
    }
    m[n] =  fib(n-1,m) + fib(n-2,m);
    return m[n];
}

// Tabulation approach
int fibTab(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i=2;i<=n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n ; 
    map<int, long long> m;
    cin >> n;
    cout << fib(n,m) << endl;
    cout << fibTab(n) << endl;
    return 0;
}   