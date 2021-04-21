#include <bits/stdc++.h> 
using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    // for (int i=0;i<v.size();i++)    
    //     cout<<v[i]<<endl;
    // iterating the vector with help of an iterator
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++)  
        cout<<*it<<endl;
    // iterating through auto keyword
    for (auto element:v) 
        cout<<element<<endl;
    
    v.push_back(0);
    v.pop_back() ; // to pop the last element from the vector
    vector<int> v2 (3,50); //creates a vector of size 3 containing elements 50,50,50
    swap(v,v2);
    for (auto element:v2) 
        cout<<element<<endl;
    // too sort elements of a vector use STL method sort()
    sort(v.begin(),v.end());
}