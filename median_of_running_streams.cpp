// numbers are coming from an array and we have to tell the median after each input

#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > minheap;
priority_queue<int, vector<int> > maxheap;

void insert(int x) {

    if (maxheap.size() == minheap.size()) {
        if (maxheap.size() == 0) {
            maxheap.push(x);
            return;
        }
        if (x < maxheap.top()) 
            maxheap.push(x);
        else 
            minheap.push(x);
    }

    // if size of maxheap and minheap is not equal
    // then 2 cases are possible
    // case 1: size of maxheap > size of minheap
    // case 2: size of minheap > size of maxheap

    else {
        // case 1
        if (maxheap.size() > minheap.size()) {
            if (x >= maxheap.top()) {
                minheap.push(x);
            }
            else {
                int temp = maxheap.top();
                maxheap.pop();
                minheap.push(temp);
                maxheap.push(x);
            }
        }
        // case 2
        else { 
            if (x <= minheap.top()) 
            {
                maxheap.push(x);
            }
            else 
            {
                int t = minheap.top();
                minheap.pop();
                maxheap.push(t);
                minheap.push(x); 
            }
        }
    }
}

double findMedian() {
    if (maxheap.size() == minheap.size()) 
        return (maxheap.top() + minheap.top())/2.0;
    else if (maxheap.size() > minheap.size()) 
        return maxheap.top();
    return minheap.top();
}

int main() {
    int arr[] = {10,15,21,30,18,19};
    for (int i = 0;i<6;i++) {
        insert(arr[i]);
        cout << findMedian() << endl;
    }
    return 0;
}