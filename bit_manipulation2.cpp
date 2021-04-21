#include "bits/stdc++.h"
using namespace std;
int unique_num(int arr[], int n) { // gives the unique number in an array 
    int xorsum = 0;
    for (int i=0;i<n;i++) {
        xorsum = xorsum^arr[i];
    }
    return xorsum;
}
bool setBit(int n,int pos) {
    return ((n & (1<<pos)) != 0) ;
}
void two_unique(int arr[] , int n) {
    int xorsum = 0;
    for (int i=0;i<n;i++) {
        xorsum = xorsum ^ arr[i];
    }
    // to find the rightmost setbit 
    int setbit = 0;int pos = 0;
    int temp = xorsum;
    while (setbit != 1) {
        setbit=xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int xorsum2 = 0;
    for (int i=0;i<n;i++) {
        if (setBit(arr[i], pos-1)) {
            xorsum2 = (xorsum2 ^ arr[i]);
        }
    }
    cout << xorsum2<< " "<< (xorsum2 ^ temp);
}
int main() {
    int arr[] = {1,2,3,1,2,3,5,7};
    two_unique(arr,8);
}