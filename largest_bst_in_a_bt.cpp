// returns the size of the largest in a binary tree
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

struct info {  // to store the following information of a node 
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info largestBSTinBT(Node *root) {
    if (root == NULL) {
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if (!root->left and !root->right) {
        return {1,root->data,root->data,1,true};
    }
    info leftst = largestBSTinBT(root->left); // to store info of left sub tree
    info rightst = largestBSTinBT(root->right);

    info curr; // to store the info of current node
    curr.size = 1+leftst.size+rightst.size;

    //checking for valid BSTs
    if (leftst.isBST and rightst.isBST and leftst.max < root->data and rightst.min > root->data) {
        curr.min = min(leftst.min, min(rightst.min, root->data));
        curr.max = max(rightst.max, max(leftst.max, root->data));
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(leftst.ans,rightst.ans);
    curr.isBST = false;
    return curr;
}

int main() {
    /*
            12 
          /   \
         9    15
       /  \   
      5   10 
    */
   Node *root = new Node(12);
   root->left = new Node(9);
   root->right = new Node (15);
   root->left->left = new Node(5);
   root->left->right = new Node(10);
   info answer = largestBSTinBT(root);
   cout << answer.ans;
   return 0;
}