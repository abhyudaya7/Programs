// Build tree from preorder and inorder
#include <bits/stdc++.h>
using namespace std;

struct node { 
    int data;
    struct node *left;
    struct node *right;
    node (int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[],int start, int end,int curr) {
    for (int i= start; i<=end;i++) {
        if (inorder[i] == curr) 
            return i;
    }
    return -1;
}

node *buildTree(int preorder[], int inorder[], int start, int end) { 
    static int idx = 0;
    // base case 
    if (start > end) 
        return NULL;
    int curr = preorder[idx];
    idx++;
    node *n = new node(curr);
    if (start == end) 
        return n;
    int pos = search(inorder,start,end,curr); // to get the position of the current node in inorder 
    n->left = buildTree(preorder,inorder,start,pos-1);
    n->right = buildTree(preorder,inorder,pos+1,end);
    return n;
}

void Inorder (node *root) {
    if (root == NULL) 
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main() {
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    node *root = buildTree(preorder,inorder,0,4);
    Inorder(root);
    return 0;
}