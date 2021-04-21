#include <bits/stdc++.h>
using namespace std;

// find number of ways to tile a 2 x N mtrix
int tiling_ways(int n) {
    if (n==0)
        return 0;
    if (n==1) 
        return 1;
    return tiling_ways(n-1) + tiling_ways(n-2); //(n-1) for horizontally placing and (n-2) for vertically placing
}
int main() {
    cout<<tiling_ways(4);

}