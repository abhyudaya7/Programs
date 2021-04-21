#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int element){
    if (st.empty()) 
        {st.push(element);return;}
    int topele = st.top();
    st.pop();
    insertAtBottom(st,element);
    st.push(topele);
}

void Reverse(stack<int> &st) {

    if (st.empty()) 
        return ;
    int element = st.top();
    st.pop();
    Reverse(st);
    insertAtBottom(st,element);

}

int main() {

    stack<int> st; 
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    Reverse(st);
    while (!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}