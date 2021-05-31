#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void calcPointers(Node *root, Node **first, Node **mid, Node **last, Node **prev) {
    //base case 
    if(root == NULL) 
        return;
    calcPointers(root->left,first,mid,last,prev);
    if (*prev and root->data < (*prev)->data) {
        if (!*first) {
            *first = *prev;
            *mid = root;
        }
        else { 
            *last = root;
        }
    }
    *prev = root;
    calcPointers(root->right, first,mid,last,prev);
}

void Swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inorder(Node *root) {
    if (root == NULL) 
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void restoreBst(Node *root) {
    Node *first = NULL, *mid = NULL, *last = NULL, *prev = NULL;

    calcPointers(root, &first,&mid,&last,&prev);

    if (first and last) {
        Swap(&(first->data), &(last->data));
    }
    else if (first and mid) {
        Swap(&(first->data) , &(mid->data));
    }
}

int main() {
    /*
            12 
          /   \
         9    15
       /  \   
      5   10 
    */
   Node *root = new Node(15);
   root->left = new Node(9);
   root->right = new Node (12);
   root->left->left = new Node(5);
   root->left->right = new Node(10);
   inorder(root);
   cout << "\n";
   restoreBst(root);
   inorder(root);
   return 0;
}