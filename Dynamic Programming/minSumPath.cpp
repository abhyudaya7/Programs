#include <bits/stdc++.h>
using namespace std;

int getMinPathSum(vector<vector<int>> arr) {
    int r = arr.size();
    int c = arr[0].size();

    vector<vector<int>> dp(r, vector<int>(c,0));

    for (int i = r-1; i >= 0; i--) {
        for (int j = c-1; j >= 0; j--) {
            if (i == r-1 and j == c-1) // for last element
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == r-1) // for last row
            {
                dp[i][j] = dp[i][j+1] + arr[i][j];
            }
            else if (j == c-1) // for last column
            {
                dp[i][j] = dp[i+1][j] + arr[i][j];
            }
            else // for elsewhere
            {
                dp[i][j] = arr[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    return dp[0][0];
}

int main() {
    int r,c;
    cin >> r >> c;
    vector<vector<int>> arr;
    
    for (int i=0;i<r;i++) {
        vector<int> temp;
        for (int j=0;j<c;j++) {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        arr.push_back(temp);
        temp.clear();
    }

    cout << getMinPathSum(arr);
    return 0;
}