#include <bits/stdc++.h>
using namespace std;
#define n 100

class Queue {
    int *arr;
    int front,back;

    public:
    Queue() {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x) {
        if(back == n-1) {
            cout << "Queue Overflow\n";
            return;
        }

        arr[++back] = x;
        if (front == -1) 
            front++;
    }
    void pop() {
        if (front == -1 || front > back) {
            cout << "Queue empty\n";
            return ;
        }
        front++;
    }
    int peek() {
        if (front == -1 || front > back) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[front];
    }
    bool empty() {
        if (front == -1 || front > back) 
            return true;
        return false;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    cout << q.peek();
}