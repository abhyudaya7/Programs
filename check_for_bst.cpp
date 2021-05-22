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

Node *insertBST(Node *root, int val) {
    if (root == NULL) 
        return new Node(val);
    
    if (val < root->data)   
        root->left = insertBST(root->left, val);
    else 
        root->right = insertBST(root->right, val);
    return root;
}

bool isBST(Node *root, Node *min,Node *max) {
    if (root == NULL) 
        return true;
    if (min and root->data <= min->data) 
        return false;
    if (max and root->data >= max->data) 
        return false;
    
    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right,root,max);
    return leftValid and rightValid;
}

int main() {
    Node *root = NULL;
    int arr[] = {5,1,3,4,2,7};
    root = insertBST(root, 5);
    for (int i=1;i<6;i++) {
        insertBST(root, arr[i]);
    }
    Node *min = new Node(INT_MIN);
    Node *max = new Node(INT_MAX);
    bool c = isBST(root,min,max);
    if (c)  
        cout << "BST is Valid\n";
    else 
        cout << "BST is not Valid\n";
    return 0;
}