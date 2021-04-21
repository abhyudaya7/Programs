#include "bits/stdc++.h"
using namespace std;
#define n 100

class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow"
                 << "\n";
            return;
        }
        arr[++top] = x;
    }
    void pop()
    {
        if (top == -1)
            cout << "Stack empty\n";
        else
            top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "Stack empty\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
};

int main() {
    Stack st;
    st.push(3);
    cout<<st.Top();

}