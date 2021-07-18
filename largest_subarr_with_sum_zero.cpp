// gives the largest subarray with sum zero 
// if the a sum of previous elements repeats itself that means the elements between the between the two sums have sum equal to zero
#include <bits/stdc++.h>
using namespace std;

int findMaxLen(vector<int> arr) {
    map<int,int> m;
    int maxlen = 0;
    m[0] = -1;
    int sum = 0;
    for(int i=0;i<arr.size();i++) {
        sum += arr[i];
        if(m.count(sum) == 0) {
            m[sum] = i;
        }
        else {
            int len = i - m[sum];
            maxlen = max(maxlen,len);
        }
    }
    return maxlen;
}

int main() {
    int n;cin >>n;
    vector<int> arr(n);
    for(auto &i:arr) 
        cin >> i;
    cout << findMaxLen(arr);
    return 0;
}