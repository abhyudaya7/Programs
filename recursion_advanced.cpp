#include "bits/stdc++.h"
using namespace std;

void permutations(string s,string ans) {
    if (s=="")      
        {
            cout<<ans<<endl;
            return;
        }
    for (int i=0;i<s.length();i++) {
        char ch=s[i];
        string ros = s.substr(0,i) + s.substr(i+1);
        permutations(ros,ans+ch);
    }
}
int countPaths(int s,int e) {
    if (s==e)       
        return 1;
    if (s>e)
        return 0;
    int count=0;
    for (int i=1;i<=6;i++) {
        count += countPaths(s+i,e);
    }
    return count;
}
int countPathsMaze(int n,int i,int j) {
    if (i==n-1 && j==n-1)
        return 1;
    if (i>n-1 || j>n-1)
        return 0;
    return countPathsMaze(n,i+1,j) + countPathsMaze(n,i,j+1);
}
int main() {
    cout<<countPathsMaze(3,0,0);
} 