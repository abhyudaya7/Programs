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

vector<Node *> constructTrees(int start, int end) {
    vector<Node *> trees;
    if (start > end) { 
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i<=end; i++) {
        vector<Node *> left_subtrees = constructTrees(start, i-1);
        vector<Node *> right_subtrees = constructTrees(i+1,end);
        
        for (int j=0; j<left_subtrees.size(); j++) {
            Node *left = left_subtrees[j];
            for (int k=0;k<right_subtrees.size();k++) {
                Node *right = right_subtrees[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node); 
            }
        }
    }
    return trees;
}

void preorder(Node *root) {
    if (root == NULL) 
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n; cin >> n;
    vector<Node *> tree_roots = constructTrees(1,n);
    // printing preorder for each tree
    for (Node* root : tree_roots) {
        preorder(root);
        cout << "\n";
    }
    return 0;
}
/*
for n = 3 
output: 
1 2 3 
1 3 2 
2 1 3 
3 1 2 
3 2 1
*/