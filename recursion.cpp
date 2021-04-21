#include <bits/stdc++.h>
using namespace std;
int Sum(int n) {
    if (n==0)
        return 0;
    return (n + Sum(n-1));
}
int power(int n,int p) {
    if (p==0){
        return 1;
    }
    // if (p==1){
    //     return n;
    // }
    return n*power(n,p-1);
}
int factorial(int n) {
    if (n==1 || n==0) {
        return 1;
    }
    return n*factorial(n-1);
}
int fib(int n) {
    if (n==0) 
        return 0;
    if (n==1)
        return 1;
    return fib(n-1) + fib(n-2);
}
int main(){
    int n;
    cin >> n;
    for (int i=0;i<=n;i++) {
        cout << fib(i) << " ";
    }
}