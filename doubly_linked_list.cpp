#include "bits/stdc++.h"
using namespace std;

class node {
    public :
    int data;
    node *next;
    node *prev;

    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtTail(node *&head, int val) {
    node *n = new node(val);
    node *temp = head;
    if (head == NULL) { 
        head = n;
        return;
    }
    while (temp->next !=NULL) 
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void insertAtHead(node *&head, int val) {
    node *n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    head->prev = n ;
    n->next = head;
    head = n;
}

void display (node *head){
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void deleteAtHead(node *&head) {
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deleteNode(node *&head,int pos) {
    node *temp = head;
    int count =1 ;
    if (pos == 1) 
    {
        deleteAtHead(head);
        return;
    }
    while (temp != NULL && count!=pos) {
        temp = temp->next;
        count++;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
}
int main() {
    node *head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,0);
    deleteNode(head,2);
    display(head);
}