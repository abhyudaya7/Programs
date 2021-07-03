#include <bits/stdc++.h>
using namespace std;

int findPeak(int arr[],int n,int low,int high) {
    int mid = low + (high-low)/2;

    if ((mid == 0 or arr[mid-1] <= arr[mid]) and (mid == n-1 or arr[mid] >= arr[mid+1])) 
        return mid;
    else if (mid > 0 and arr[mid-1] > arr[mid]) 
        return findPeak(arr,n,low,mid-1);
    else 
        return findPeak(arr,n,mid+1,high);
}

int main() {
    int arr[] = {0,6,8,5,7,9};
    int n = 6;
    cout << "Peak element index is: " << findPeak(arr,n,0,n-1);
    return 0;
}