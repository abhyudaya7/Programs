#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    stack<char> st;
    bool c= true;
    for (int i=0;i<s.length();i++){ 
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if (st.top() == '('){
                if (s[i] != ')'){
                    c = false;
                    break;
                }
                else 
                    {st.pop();continue;}
            }
            if(st.top() == '{')
                {
                    if(s[i] != '}')
                    {
                        c = false;
                        break;
                    }
                    else 
                        {st.pop();continue;}
                }
            if (st.top() == '[')
            {
                if(s[i] != ']')
                {
                    c = false;
                    break;
                }
                else {st.pop();continue;}
            }
        }
    }
    if (st.empty() && c)
        cout <<"TRUE";
    else cout <<"FALSE";
}