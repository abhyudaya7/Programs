#include "bits/stdc++.h"
using namespace std;
int getBit(int pos,int n) {
    return ((n&(1<<pos))!=0);
}
int setBit(int pos,int n) {
    return (n | (1<<pos));
}
int clearBit(int pos,int n) {
    return (n & (~(1<<pos)));
}
int updateBit(int pos,int n,int value) {
    // first clear the existing bit 
    int mask = ~(1<<pos);
    n = n & mask;
    // update the bit to the specified value
    return (n | (value<<pos));
}
void subsets(int arr[], int n) { // to print all possible subsets of a given array
    for (int i=0; i<(1<<n);i++) {
        for (int j=0;j<n;j++) {
            if (i & (1<<j)) {
                cout<<arr[j]<< " ";
            }
        }
        cout<<"\n";
    }
}
int main() {
    // int n,pos;
    // cin >> n >> pos;
    // cout << getBit(pos,n);
    int arr[] = {0,1,3,5};
    subsets(arr,4);
}