#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// int findSplit(int arr[],int n){
//     int sum = 0;
//     // int n = sizeof(arr)/sizeof(arr[0]);
//     for (int i=0;i<n;i++) 
//         sum+=arr[i];
//     int product = 1;
//     for (int i=0;i<n;i++) {
//         product *= arr[i];
//         sum -= arr[i];
//         if (sum == product)
//             return i;
//     }
//     return -1;
// }
int main() {
    int t;cin>>t;
    int c=1;
    while(t>0) {
        int m;
        cin >> m;
        vector<int> v;
        for (int i=0;i<m;i++) {
            int p,n;
            cin >> p >> n;
            for (int j=0;j<n;j++) {
                v.push_back(p);
            }
        }
        int arr[v.size()];
        int n=v.size();
        
        copy(v.begin(), v.end(), arr);
        
        // int split = findSplit(arr,n);
        // cout << split << endl;
        int sum = 0;
        for (int i=0;i<n;i++) 
            sum += arr[i];
        int p = 1;
        int temp = sum;
        int ans =0;
        for (int i=0;i<n;i++) {
            p = p*arr[i];
            if(p>=sum)
                {p=arr[i];sum =temp;}
            sum -= arr[i];
            if(sum == p)
            { ans = p;break;}

        }
        
        
        cout<<"Case #"<<c++<<": "<<ans<<endl;
        t--;
    }
}