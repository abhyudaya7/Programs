// paint house problem leetcode

#include <bits/stdc++.h>
using namespace std;

int paintHouse(int n, vector<vector<int>> arr) {
    int red = arr[0][0];
    int blue = arr[0][1];
    int green = arr[0][2];
   
    for (int i = 1;i<n;i++) {
        int nr = min(blue,green) + arr[i][0];
        int nb = min(red,green) + arr[i][1];
        int ng = min(red,blue)  + arr[i][2];

        red = nr;
        blue = nb;
        green = ng;
    }

    int ans = min(red, min(blue,green));
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i=0;i<n;i++) {
        for (int j = 0;j<3;j++) {
            cin >> arr[i][j];
        }
    }

    cout << paintHouse(n, arr);
    return 0;
}