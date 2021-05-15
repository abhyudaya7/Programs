#include <bits/stdc++.h>
using namespace std;

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

node *lca(node *root, int n1, int n2) {
    if (root == NULL) 
        return NULL;
    if (root->data == n1 || root->data == n2) 
        return root;
    node *leftLCA = lca(root->left,n1,n2);
    node *rightLCA = lca(root->right, n1,n2);

    if (leftLCA and rightLCA) 
        return root;
    if (leftLCA != NULL) 
        return leftLCA;
    else return rightLCA;
}

int findDist(node *root, int key,int dist) {
    if (root == NULL) 
        return -1;
    if (root->data == key) 
        return dist;
    int left = findDist(root->left,key,dist+1);
    if (left != -1) 
        return left;
    return findDist(root->right,key,dist+1);
}

int distBtwNodes(node *root, int n1,int n2) {
    node *LCA = lca(root,n1,n2);
    int d1 = findDist(LCA,n1,0);
    int d2 = findDist(LCA,n2,0);
    return d1+d2;
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
    cout << distBtwNodes(root,4,6);
    return 0;
}