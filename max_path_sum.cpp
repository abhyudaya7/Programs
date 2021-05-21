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

int maxPathSum(node *root, int &ans) {
    if (root == NULL) 
        return 0;
    
    int left = maxPathSum(root->left, ans);
    int right = maxPathSum(root->right,ans);

    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left,root->data + right));
    ans = max(ans,nodeMax);
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}

int maxSum(node *root) {
    int ans = INT_MIN;
    maxPathSum(root,ans);
    return ans;
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
    cout << maxSum(root);
    return 0;
}