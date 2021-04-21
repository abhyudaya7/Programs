#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    // how to sort a given string
    string str = "afasfasdfgaggdfgdrgeghghtjrtjuyjgnxfbsbfdgaghtrhwrthsrjyjyjdtjyhgthwethwthryjetyjtdyjghnfgnsgbnsghtrhwrtjyjsrgnsgnsbrhqwgqgf";
    sort(str.begin(), str.end());
    cout << str<<endl;
}