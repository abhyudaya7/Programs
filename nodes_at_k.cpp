#include <bits/stdc++.h>
using namespace std;
#define null NULL

struct node {
    int data;
    node *left;
    node *right;
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
}; 

// case 1: 
//find nodes in the subtree of target node
void printSubtreeNodes(node *root, int k) {
    if (root == null || k<0) 
        return;
    
    if (k==0) {
        cout << root->data << " ";
        return ;
    }

    printSubtreeNodes(root->left, k-1);
    printSubtreeNodes(root->right, k-1);
}

//case 2: 
// print nodes at ancesteral level
int printNodesAtK (node *root, node *target, int k) {
    if (root == null) 
        return -1; // returns -1 if the target node is not found in the tree
    if (root == target) {
        printSubtreeNodes(root,k);
        return 0;
    }
    int dl = printNodesAtK(root->left,target, k);
    if (dl != -1) {
        if (dl + 1 == k) 
            cout << root->data << " ";
        else 
            printSubtreeNodes(root->right,k-dl-2);
        return 1+dl;
    }
    int dr = printNodesAtK(root->right,target, k);
    if (dr != -1) {
        if (dr + 1 == k) 
            cout << root->data << " ";
        else 
            printSubtreeNodes(root->left,k-dl-2);
        return 1+dr;
    }
    return -1; 
}

int main() {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    /* 
              1 
            /   \
           2     3 
         /  \   /  \ 
        4    5 6    7    
    */
    printNodesAtK(root,root->left,3);
    return 0;
}


