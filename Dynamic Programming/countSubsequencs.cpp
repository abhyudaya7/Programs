// count the number of subsequences of the form 'a+b+c+' 
#include <bits/stdc++.h>
using namespace std;

int count(string s) {
    int a = 0;
    int ab = 0;
    int abc = 0;

    for (int i = 0;i < s.size(); i++) {
        if (s[i] == 'a') {
            a = 2 * a + 1;
        }
        else if (s[i] == 'b') {
            ab = 2 * ab + a;
        }
        else if (s[i] == 'c') {
            abc = 2 * abc + ab;
        }
    }

    return abc; 
}

int main() {
    string s;
    cin >> s;

    cout << count(s);
}