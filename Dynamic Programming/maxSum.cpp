// get the maximum sum of subsets which do not contain ajacent elements in the array 

#include <bits/stdc++.h>
using namespace std;

int countSum(int n, vector<int> arr) {

    int inc = arr[0];
    int exc = 0;

    for (int i=1;i < arr.size(); i++) {
        int included = exc + arr[i];
        int excluded = max(inc, exc);

        inc = included;
        exc = excluded;
    }

    return max(inc, exc);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i:arr) {
        cin >> i;
    }

    cout << countSum(n,arr);
    return 0;
}