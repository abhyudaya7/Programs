#include "bits/stdc++.h"
using namespace std;
class base {
    public :
    virtual void print() {
        cout << "Base class\n";
    }
};
class derived : public base{
    public:
    void print() {
        cout << "Derived Class\n";
    }
};
int main() {
    base *baseptr;
    derived d;
    baseptr = &d;
    baseptr -> print();
}