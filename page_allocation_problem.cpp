#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int min) {
    int student = 1, sum = 0;

    for (int i=0;i<n;i++) {
        if (arr[i] > min) 
            return false;
        if (sum + arr[i] > min) {
            student++;
            sum = arr[i];
            if (student > m) {
                return false;
            }
        }
        else {
            sum += arr[i];
        }

    }
    return true;    
}

int minAllocation(int arr[] , int n, int m) {
    if (n < m) 
        return -1; // if number of pages is less than the number of students then there is no appropriate solution
    int sum = 0;
    for (int i=0;i<n;i++) 
        sum += arr[i];
    int start = 0,end = sum, ans = INT_MAX;
    while (start <= end) {
        int mid = (start + end)/2;
        if (isPossible(arr,n,m,mid)) {
            ans = min(ans,mid);
            end = mid - 1;
        }
        else 
            start = mid + 1;
    }
    return ans;
    
}

int main() {
    int arr[] = {12,34,67,90};
    int n = 4, m = 2;
    cout << minAllocation(arr,n,m);
    return 0;
}