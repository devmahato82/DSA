/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        if(root == NULL) return 0;
        int ltree = height(root->left);
        int rtree = height(root->right);
        return max(ltree, rtree) +1;
    }
    bool isBalanced(Node* root) {
        // code here
        if(root==NULL) return true;
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        if(abs(rheight - lheight) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};