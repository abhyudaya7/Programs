// to print the zig zag traversal of a BST 
// if first level is traversed left to right then the next level will be traversed right to left and so on 
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

void zigzag(Node *root) {
    if (root == NULL) 
        return;
    stack<Node *> currLevel; // to store elements of current level
    stack<Node *> nextLevel; // to store elements of next level
    bool leftToRight = true;
    currLevel.push(root);

    while (!currLevel.empty()) {
        Node *n = currLevel.top();
        currLevel.pop();
        if (n) {
            cout << n->data << " ";
            // pushing the children of n to nextLevel
            if (leftToRight) {
                if (n->left) {
                    nextLevel.push(n->left);
                }
                if (n->right) {
                    nextLevel.push(n->right);
                }
            }
            else {
                if(n->right) 
                    nextLevel.push(n->right);
                if (n->left)
                    nextLevel.push(n->left);
            }
        }
        if (currLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
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
   zigzag(root);
   return 0;
}