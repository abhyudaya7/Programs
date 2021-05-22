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

Node *search(Node *root, int key) {
    if (root == NULL) 
        return NULL;
    if (root->data == key) 
        return root;
    if (root->data > key) 
        return search(root->left, key);
    return search(root->right, key);
}

Node *inorderSucc(Node *root) {
    Node *curr = root;
    while(curr and curr->left){
        curr = curr->left;
    }
    return curr;
}

Node *deleteInBST(Node *root, int key) {
    if (root == NULL) 
        return NULL;
    if (key < root->data) 
    {
        root->left = deleteInBST(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteInBST(root->right,key);
    }
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        //case 3 when both left and right are not null
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
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
    cout << "\n";
    Node *n = deleteInBST(root,1);
    inorder(n);
    return 0;
}