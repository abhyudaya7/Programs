#include <bits/stdc++.h> 

using namespace std;
// reverse a string using recursion
void reverse(string s) {
    if (s=="")      
        return;
    reverse(s.substr(1));
    cout<<s[0];
    
}
void printPi(string s) {
    if (s=="") {
        return;
    }
    if(((s.substr(0,2)).compare("pi")) == 0){
        cout << 3.14;
        printPi(s.substr(2));
    }
    else {
        cout<<s[0];
        printPi(s.substr(1));
    }
}
string removeDuplicates(string str) {
    if (str=="")
        return "";
    char ch = str[0];
    string ans = removeDuplicates(str.substr(1));
    if (ch==ans[0]) 
        return ans;
    return ch+ans;
}
void removeX(string s) {
    if (s=="")  
        return;
    if (s[0]!='x')
        cout<<s[0];
    removeX(s.substr(1));
    if (s[0]=='x') 
        cout<<s[0];
}
string moveallX(string s) {
    if (s=="") 
        return "";
    char ch = s[0];
    string ans = moveallX(s.substr(1));
    if (ch=='x')
        return ans+ch;
    return ch+ans;
}
void printSubStrings(string s, string ans) {
    if (s=="") {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    printSubStrings(s.substr(1),ans);
    printSubStrings(s.substr(1),ans+ch);

}
int main() {
    string str;
    getline(cin,str);
    printSubStrings(str,"");  
}