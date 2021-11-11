#include <bits/stdc++.h>
using namespace std;

int countEncodings(string s) {
    vector<int> dp(s.size(),0);

    dp[0] = 1;
    for (int i = 1;i < dp.size(); i++) {
        if (s[i-1] == '0' and s[i] == '0') {
            dp[i] = 0;
        }
        else if (s[i-1] == '0' and s[i] != '0') {
            dp[i] = dp[i-1];
        }
        else if (s[i-1] != '0' and s[i] == '0') {
            if (s[i-1] == '1' or s[i-1] == '2') {
                dp[i] = (i >= 2) ? dp[i-2] : 1;
            } else {
                dp[i] = 0;
            }
        }
        else {
            if (stoi(s.substr(i-1,2)) <= 26) {
                dp[i] = dp[i-1] + ((i >= 2) ? dp[i-2] : 1);
            }
            else {
                dp[i] = dp[i-1];
            }
        }
    }

    return dp[s.size() - 1];
}

int main() {
    string s;
    cin >> s;

    cout << countEncodings(s);
    return 0;
}