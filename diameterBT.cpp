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

int calcHeight(node *root) {
    if (root == NULL) 
        return 0;
    int leftHeight = calcHeight(root->left);
    int rightHeight = calcHeight(root->right);
    return max(leftHeight,rightHeight) + 1;
}

int calcDiameter(node* root) {
    if (root == NULL) 
        return 0;
    int leftHeight = calcHeight(root->left);
    int rightHeight = calcHeight(root->right);
    int currDiameter = leftHeight + rightHeight + 1;
    return max(currDiameter , max(calcDiameter(root->left),calcDiameter(root->right)));
}

int diameter(node *root, int *height) { // function to calculate diameter of a BT in linear time 
    if (root == NULL) {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ld = diameter(root->left, &lh);
    int rd = diameter(root->right, &rh);
    *height = max(lh,rh) + 1;
    int curr = lh + rh + 1;
    return max(curr, max(ld,rd));
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
    cout << diameter(root,&height);
    return 0;
}