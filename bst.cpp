#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;  
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

Node *getMinNode(Node *root) {
    Node *current = root;

    while (current and current->left) {
        current = current->left;
    }

    return current;
}

Node *deleteNode(Node *root, int Key) {
    if (root == NULL) 
        return NULL;
    
    if (Key < root->data) {
        root->left = deleteNode(root->left, Key);
    }

    else if (Key > root->data) {
        root->right = deleteNode(root->right, Key);
    }

    else {
        if (!root->left and !root->right) {
            return NULL;
        }

        else if (!root->left) {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        else if (!root->right) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // when both left and right child are not null
        // find the indorder succesor -> the leftmost (smallest) node in the right subtree

        Node *minNode = getMinNode(root->right);

        root->data = minNode->data;

        root->right = deleteNode(root->right, minNode->data);
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
    Node *newRoot = deleteNode(root, 1);
    inorder(newRoot);
    return 0;
}