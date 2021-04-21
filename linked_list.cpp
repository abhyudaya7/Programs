#include "bits/stdc++.h"
using namespace std;

class node {
    public :
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) 
    {
        head = n;
        return;
    }
    node* temp = head ;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp->next = n;
}
void display(node* head) { 
    node* temp = head;
    if (head == NULL) 
        cout<<"Empty List\n";
    while (temp != NULL) {
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

int length(node *head) {
    int l=0;
    node *temp = head;
    while (temp!=NULL) {
        l++;
        temp = temp->next;
    }
    return l;
}

void deleteNode(node* &head,int val) {
    node* temp = head;
    if (head == NULL)  
        return ;
    if (head->data == val) { // to delete the node at head
        node* todelete = head;
        head = head->next;
        delete todelete;
        return;
    }
    while (temp->next->data != val) {
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete; 
}
void insertAtHead(node* &head,int val) {
    node* n = new node(val);
    
    n->next = head;
    head = n; 

}

bool search (node* head, int key) {
    node* temp = head;
    while(temp!= NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// function to reverse a linked list 
node* reverse(node* &head) {
    node* prev = NULL;
    node *current = head;
    node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev; //reversing step
        prev = current ;
        current = next;
    }
    return prev; // previous pointer will be last node of the list and therefore will be the head
}
node *reverseRecursive(node *&head) {
    if (head == NULL || head->next == NULL) 
        return head;
    node *newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

node *reversek(node *&head, int k) {
    node *prev = NULL;
    node *current = head;
    node *next;
    int count = 0;
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL) {
        head->next = reversek(next,k);
    }
    return prev;
}

bool detectCycle(node *&head) {
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) 
            return true;
    }
    return false;
}

void makecycle(node *&head,int pos) {
    node *temp=head;
    node *startnode;
    int count =0 ;
    while (temp->next != NULL) {
        if (pos==count) 
            startnode = temp;
        temp = temp->next;
        count++;
    }
    temp -> next = startnode;
}

void removecycle (node *&head) {
    node *fast = head;
    node *slow = head;

   do { 
       slow = slow->next;
       fast = fast->next->next;
   }while (slow != fast);
   fast = head;
   while (slow->next != fast->next) {
       slow = slow->next;
       fast = fast->next;
   }
   slow->next = NULL;
}

node *appendkNodes(node *&head,int k) {
    node *temp = head;
    node *newhead;
    node *newtail;
    // node *tail;
    int count = 0;
    while (temp->next != NULL) {
        if (count+1 == k) {
            newtail = temp;
            newhead = temp->next;
        }
        temp = temp->next;
        count++;
    }
    newtail->next = NULL;
    temp->next = head;
    return newhead;
}

//function to merge two sorted linked lists
node *merge(node *&head1, node *&head2) {
    node *dummy = new node(-1);
    node *p1 = head1;
    node *p2 = head2;
    node *p3 = dummy;
    while (p1 != NULL && p2 != NULL ) {
        if (p1->data < p2->data) {
            p3->next = p1;
            p1 = p1->next;
        }
        else {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL) {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL) {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}

node *oddEven(node *&head) {
    node *temp = head;
    node *oddhead;
    node *evenhead;
    bool o,e = true;
    while(temp != NULL && (o || e)) {
        if (temp->data % 2==0){
            evenhead = temp ;
            e = false;
        }
        else {
            oddhead = temp ;
            o = false;
        }
        temp = temp->next;
    }
    temp = head;
    node *even = evenhead;
    node *odd = oddhead;
    while(temp != NULL) {
        if ((temp->data % 2==0) && temp->data != evenhead->data) {
            even->next = temp;
            even = even->next;
        }
        else if ((temp->data%2 != 0) && temp->data != oddhead->data) {
            odd->next = temp;
            odd = odd->next;
        }
        temp = temp->next;
    }
    odd->next=evenhead;
    even->next=NULL;
    return oddhead;

}

int main() {
    node* head = NULL;
    // node *head2 = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    cout <<"\n";
    // display(head2);
    // cout << "\n";
    // makecycle(head,2);
    // removecycle(head);
    // deleteNode(head,0);
    // node *newhead = reversek(head,2);
    // cout << detectCycle(head);
    // cout << "\n" <<search(head,3);
    node *head1 = oddEven(head);
    display(head1);
    return 0;
}