// to maximize minmum possilbe distance
// find k elements from the array such that minimum distance between any two points is maximized

#include <bits/stdc++.h>
using namespace std;

//fucntion to check feasibility of our chosen value
bool isFeasible(int mid,int arr[], int n,int k) {
    int pos = arr[0], elements = 1;

    for (int i=0;i<n;i++) {
        if (arr[i] - pos >= mid) {
            pos = arr[i];
            elements++;
            if (elements == k) 
                return true;
        }
    }
    return false; 
}

int largestMinDistance(int arr[], int n, int k) {
    sort(arr, arr+n);
    int res = -1;
    int left = 1, right = arr[n-1];
    while (left < right) {
        int mid = (left+right) / 2;
        if (isFeasible(mid,arr,n,k)) {
            res = max(res,mid);
            left = mid+1;
        } else {
            right = mid;
        }
    }
    return res;
}

int main () {
    int arr[] = {1,2,8,4,9};
    int n = 5,k=3;
    cout << largestMinDistance(arr,n,k);
    return 0;
}