#include<iostream>
using namespace std;
int main() {
    int a=10;
    int *p = new int(); // allocate memory in a heap
    *p=10; // store value at pointed memory address in heap
    delete(p); // deallocate memory to prevent memory leak 
    p = new int[4]; // to store an array of integers in a heap
    delete[] p; // to delete the array of integers
    p=NULL; // to delete the pointer

}