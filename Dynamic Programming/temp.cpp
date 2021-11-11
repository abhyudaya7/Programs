
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &i:arr) {
        cin >> i;
    }

    int sum = 0;
    for (int i=0;i<n;i++) {
        if (i == 0) {
            sum = sum + (arr[i] > arr[i+1] ? arr[i] : 0); 
        }
        else if (i == n-1) {
            sum = sum + (arr[i] > arr[i-1] ? arr[i] : 0);
        }
        else {
            sum = sum + ((arr[i] > arr[i-1] and arr[i] > arr[i+1]) ? arr[i] : 0);
        }
    }

    cout << sum << endl;
    return 0;
}