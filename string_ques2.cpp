#include<iostream>
#include<string>

using namespace std;
int main() {
    string str = "abssadewfaadfgggggggg";
    int freq[26];
    for(int i=0;i<26;i++)
        freq[i] = 0;
    for (int i=0;i<str.size();i++) {
        freq[str[i]-97]++;
    }
    char ans = 'a';
    int maxF = 0;
    for (int i=0;i<26;i++) {
        if (freq[i] > maxF) {
            maxF = freq[i];
            ans = 'a'+i;
        }
    }
    cout << maxF <<" "<< ans<<endl;
}