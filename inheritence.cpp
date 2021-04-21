#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    void func() {
        cout << "Class A\n";
    }
};
class B {
    public: 
    void funcB() {
        cout << "Class B\n";
    }
};
class C : public A, public B {

};
int main() { 
    C obj;
    obj.func();
    obj.funcB();
}