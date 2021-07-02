#include <bits/stdc++.h>
using namespace std;

int searchInArray(int arr[], int key, int low, int high) {
    if (low > high) 
        return -1;
    
    int mid = (low + high) / 2;
    if (arr[mid] == key) 
        return mid;
    
    if (arr[low] <= arr[mid]) {
        if (key >= arr[low] and key <= arr[mid]) {
            return searchInArray(arr,key,low,mid-1);
        }
        return searchInArray(arr,key,mid+1,high);
    }

    if (key >= arr[mid] and key <= arr[high]) 
        return searchInArray(arr,key,mid+1,high);
    return searchInArray(arr,key,low,mid-1);
}

int main() {
    int arr[] = {6,7,8,9,10,1,2,5};
    int idx = searchInArray(arr,8,0,7);
    if (idx == -1) {
        cout << "Element not found\n";
    }
    else 
        cout << "Element found at: " << idx << "\n";
    return 0;
}