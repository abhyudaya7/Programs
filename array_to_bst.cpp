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

Node *arrayToBST(int arr[], int start ,int end) {
    if (start > end) 
        return NULL;
    
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = arrayToBST(arr,start,mid-1);
    root->right = arrayToBST(arr,mid+1,end);    
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
    int arr[] = {1,2,3,4,5};
    Node *root = arrayToBST(arr,0,4);
    inorder(root);
    
    return 0;
}