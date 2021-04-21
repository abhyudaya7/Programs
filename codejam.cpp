#include <bits/stdc++.h>
using namespace  std;

int main() {
    int t;
    cin >> t;int c=1;
    while(t>0) {
        int n;
        cin >> n;
        long long int arr[n];
        for (int i=0;i<n;i++) 
            cin >> arr[i];
        int count=0;
        for (int i=1;i<n;i++) {
            while(arr[i] <= arr[i-1]) {
                int lastelement = arr[i-1] % 10;
                if (lastelement == 9){
                    arr[i] = arr[i]*10;
                    count++;
                }
                else {
                    arr[i] = arr[i]*10 + (lastelement+1);
                    count++;
                }
            }
        }
        cout<<"Case #"<<c++<<": "<<count<<endl;
        count = 0;
        t--;
    }
}

