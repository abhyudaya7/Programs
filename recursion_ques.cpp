#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int n) {
    if (n==1) {
        return true;
    }
    // bool restArray = isSorted( arr+1,n-1 );
    return (arr[0]<arr[1] && isSorted(arr+1,n-1));
}

void dec(int n) { // print number in decreasing order
    if (n==0) 
        return;
    cout << n << endl;
    dec(n-1);
}

void inc(int n) {
    if (n==0)
        return;
    inc(n-1);
    cout << n << endl;
}
int main() {
    // int arr[] = {1,2,3,4,1};
    // cout << isSorted(arr, 5);
    int n;
    cin >> n;
    inc(n);
}