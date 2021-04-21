#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str = "abcdef" ; 
    // to convert the string to upper case
    // for (int i=0;i<str.size();i++) {
    //     if (str[i]>='a' && str[i] <= 'z') 
    //         str[i] -= 32;
    // }
    transform(str.begin(),str.end(), str.begin(), ::toupper);
    cout << str << endl;
    // convert the srting ti upper case 
    // for (int i=0;i<str.length();i++) {
    //     if (str[i]>='A' && str[i]<='Z') 
    //         str[i] += 32;
    // }
    transform(str.begin(),str.end(),str.begin(),::tolower);
    cout << str << endl;
}