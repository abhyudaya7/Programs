#include "bits/stdc++.h"
using namespace std;

void countSort(int arr[],int n) {
    // 1. Find the maximum element in the array
    int k = arr[0];
    for (int i=0;i<n;i++) {
        k = max(k,arr[i]);
    }
    // int count[10] = {0};
    int* count = new int[k];
    
    for (int i=0;i<k;i++)
        count[i] = 0;
   
    // 2. fill the count array
    for (int i=0;i<n;i++) {
        count[arr[i]]++;
    }
    // 3. Modify the count array
    for (int i=1;i<=k;i++) {
        count[i] += count[i-1];
    }
    // 4. sort the array using the count array generated
    int output[n];
    for (int i=n-1;i>=0;i--) {
        output[--count[arr[i]]] = arr[i];
    }
    for (int i=0;i<n;i++) 
        arr[i] = output[i];
}

int main() {
    int arr[] = {5,1,3,2,4};
    countSort(arr,5);
    for (int i=0;i<5;i++) 
        cout<<arr[i]<<" ";
}