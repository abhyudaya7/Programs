#include <bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<int> prices){ 
    vector<int> ans;
    stack<pair<int,int>> st;
    for (auto price: prices) {
        int days = 1;
        while (!st.empty() and st.top().first <= price) {
            days += st.top().second;
            st.pop();
        }
        st.push({price,days});
        ans.push_back(days);
    }
    return ans; 
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) 
        cin >> i;
    vector<int> res = stockspan(a);
    for (auto i:res) 
        cout << i << " ";
    return 0;
}