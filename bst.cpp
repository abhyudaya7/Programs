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

// insertion in a BST
Node *insertBST(Node *root, int val) {
    if (root == NULL) 
        return new Node(val);
    
    if (val < root->data)   
        root->left = insertBST(root->left, val);
    else 
        root->right = insertBST(root->right, val);
    return root;
}

void inorder(Node *root) {
    if (root == NULL) 
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    int arr[] = {5,1,3,4,2,7};
    root = insertBST(root, 5);
    for (int i=1;i<6;i++) {
        insertBST(root, arr[i]);
    }
    // print inorder
    inorder(root);
    return 0;
}