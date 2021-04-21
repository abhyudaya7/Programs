#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,x;
        cin >> n >> x;
        int choco[n];
         
        for (int i =0 ;i<n;i++)
           cin >> choco[i];
        int e=0;int eat=0;
        for (int i=0;i<n;i++) {
            if (e<=n-x){
                if (choco[i]!=eat)
                {
                    e++;
                    eat = choco[i];
                }
            }
            if(e==n-x)
                break;
        } 
        cout << e << endl;   
          
    }
}