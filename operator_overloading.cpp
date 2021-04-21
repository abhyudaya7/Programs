#include "bits/stdc++.h"
using namespace std;

class Complex{
    private :
    int real,imaginary;
    public :
    Complex(int r=0,int i=0) {
        real = r;
        imaginary = i;
    }
    // code for oerator overloading 
    // pass the object by reference using & operator
    Complex operator + (Complex const &obj) { 
        Complex res;
        res.real = real + obj.real;
        res.imaginary = imaginary + obj.imaginary;
        return res;
    }
    void display() { 
        cout <<real<<"+i"<<imaginary;
    }
};
int main() {
    Complex a(2,3);
    Complex b(4,5);
    Complex res =a+b;
    res.display();
}