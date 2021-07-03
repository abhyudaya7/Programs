#include <bits/stdc++.h>
using namespace std;

int minSubArraySize(int arr[], int n, int x) {
    int sum = 0, minLen = n+1, start = 0, end = 0;
    
    while (end < n) {
        while (sum <= x and end < n) {
            sum += arr[end++];
        }
        while (sum > x and start < n) {
            if (end - start < minLen) {
                minLen = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLen;
}

int main() {
    int arr[] = {1,4,45,6,10,19};
    cout << minSubArraySize(arr,6,51);
    return 0;
}