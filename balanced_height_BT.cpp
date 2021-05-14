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

int height(node *root) {
    if (root ==  NULL) 
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh) + 1;
}

bool isBalanced(node *root) {
    if (root == NULL)   // check for the leaf nodes
        return true;
    if (!isBalanced(root->left)) // check for the left sub-tree
        return false;
    if (!isBalanced(root->right))  // check for the right sub-tree
        return false;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh-rh) <= 1) // condition for balanced height
        return true;
    else 
        return false;
}

//function to find isBalanced in linear time 
bool isBalancedOptimized(node *root, int *height) {
    if (root == NULL )
        return true;
    int lh = 0, rh = 0;
    if (!isBalancedOptimized(root->left, &lh))
        return false;
    if (!isBalancedOptimized(root->right, &rh))
        return false;
    *height = max(lh,rh) + 1;
    if (abs(lh-rh) <= 1) 
        return true;
    else 
        return false;
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
    int height = 0;
    cout << isBalancedOptimized(root,&height);
    return 0;
}