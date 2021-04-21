#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *next;
    node (int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val){
    node *n = new node(val);
    node *temp = head;
    if (head == NULL) {
        n->next = n;
        head = n;
        return ;
    }
    n->next = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = n;
    head = n;
}

void insertAtTail(node *&head, int val) {
    node *n = new node(val);
    if (head == NULL) {
        insertAtHead(head,val);
        return;
    }
    node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void display(node *head) {
    node *temp = head;
    while (temp->next != head) {
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void deleteAtHead(node *&head) {
    node *temp = head;
    node *todelete; 
    while (temp->next != head)
        temp = temp->next;
    todelete = head;
    temp->next = head->next;
    head = head->next ;
    delete todelete;
}

void deleteNode(node *&head,int pos) {
    int count = 1;
    if (pos == 1) {
        deleteAtHead(head);
        return ;
    }
    node *todelete;
    node *temp = head;
    while (temp->next != head && count != pos-1) {
        temp = temp->next;
        count++;
    }
    todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main() {
    node *head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,0);
    display(head);
    deleteNode(head,1);
    display(head);
    return 0;
}