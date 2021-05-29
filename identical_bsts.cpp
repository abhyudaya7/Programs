#include <bits/stdc++.h>
using namespace std;

// checks for two BSTs if they are identical or not 

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isIdentical(Node *root1, Node *root2) {
    if (root1 == NULL and root2 == NULL) 
        return true;
    if (root1 == NULL or root2 == NULL) 
        return false;
    bool condition1 = root1->data == root2->data;
    bool condition2 = isIdentical(root1->left, root2->left);
    bool condition3 = isIdentical(root1->right, root2->right);
    if (condition1 and condition2 and condition3) 
        return true;
    return false;
}

int main() {
    /*
            12 
          /   \
         9    15
       /  \   
      5   10 
    */
   Node *root1 = new Node(12);
   root1->left = new Node(9);
   root1->right = new Node (15);
   root1->left->left = new Node(5);
   root1->left->right = new Node(10);
   Node *root2 = new Node(12);
   root2->left = new Node(9);
   root2->right = new Node (15);
   root2->left->left = new Node(5);
   root2->left->right = new Node(10);
   cout << isIdentical(root1,root2);
   return 0;
}