#include <bits/stdc++.h> 
using namespace std;

void wavesort(int arr[],int n) {
    int temp;
    for (int i=1;i<n;i+=2) {
        if (arr[i] > arr[i-1]) {
            temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
        }
        if (arr[i] > arr[i+1] && i<=n-2 ){
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = arr[i];
        }

    }
}