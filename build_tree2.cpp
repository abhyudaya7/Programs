// To build binary tree from postorder and inorder traversal
#include <bits/stdc++.h>
using namespace std;
#define null NULL

struct Node {
    int data;
    Node *left;
    Node *right;
    Node (int val) {
        data = val;
        left = null;
        right = null;
    }
};

int search(int in[], int start,int end,int x) {
    for(int i=start;i<=end;i++) {
        if(in[i] ==x) 
            return i;
    }
    return -1;
}

Node *buildTree(int postorder[], int inorder[], int start, int end) {
    static int idx = end;
    if (start > end) 
        return null;
    int curr = postorder[idx--];
    Node *n = new Node(curr);
    if (start == end )
        return n;
    int pos = search(inorder,start,end,curr);
    n->right = buildTree(postorder,inorder,pos+1,end);
    n->left = buildTree(postorder, inorder, start, pos-1);
    return n;
}

void Inorder(Node *root) {
    if (root == null) 
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main() {
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};
    Node *root = buildTree(postorder, inorder, 0,4);
    Inorder(root);
    return 0;
}