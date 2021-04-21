#include<bits/stdc++.h>
using namespace std;

bool isPowerOf2(int n) {  // check wether the given number is a power of two or not
    return (n  && !(n & n-1));
}
int countSetBits(int n) { // retrun the number of set bits
    int count =0;
    while(n>0) {
        n = n & (n-1);
        count++;
    }
    return count;
}
int main() { 
    int n; 
    cin >> n;
    cout << countSetBits(n) << endl;
}