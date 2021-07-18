#include <bits/stdc++.h>
using namespace std;

int findCount(vector<int> arr){
    map<int,int> m;
    int sum = 0;
    int count = 0;
    m[0] = 1;
    for (int i=0;i<arr.size();i++) {
        sum += arr[i];
        if (m.count(sum) != 0) {
            count += m[sum];
            m[sum]++;
        } else {
            m[sum] = 1;
        }
    }
    return count;
}

int main() {
    int n;cin >>n;
    vector<int> a(n);
    for (auto &i:a)
        cin >> i;
    cout << findCount(a);
    return 0;
}