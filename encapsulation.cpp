#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    int a; 
    void funA() {
        cout << "Fun A\n";
    }
    private:
    int b;
    void funB() {
        cout << "Fun B\n";
    }
    protected:
    int c;
    void funC() {
        cout << "Fun C\n";
    }

};
int main() {
    A obj;
    obj.funA();
    // obj.funB();
}