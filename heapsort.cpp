#include <bits/stdc++.h>
using namespace std; 

void heapify(vector<int> &a, int n, int i) {
    int maxIdx = i;
    int l = 2*i + 1; // to store the index of left child
    int r = 2*i + 2; // to store the index of right child

    if (l<n and a[l] > a[maxIdx]) 
        maxIdx = l;

    if (r<n and a[r] > a[maxIdx]) 
        maxIdx = r;
    
    if (maxIdx != i) {
        swap(a[i], a[maxIdx]);
        heapify(a,n,maxIdx);
    }
}

void heapsort(vector<int> &a) {
    int n = a.size();

    for (int i = n/2-1; i>=0;i--) // n/2-1 gives the index of first non leaf element in a tree
    {
        heapify(a,n,i);
    }

    for (int i = n-1; i>=0;i--) {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main() {
    int n; cin>>n;
    vector<int> a(n);

    for (auto &i:a) 
        cin >> i;
    
    heapsort(a);

    for (auto i:a) {
        cout << i << " ";
    }
    return 0;
}