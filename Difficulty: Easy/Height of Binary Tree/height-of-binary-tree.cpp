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
        // code here
       if(root == NULL) return -1;
       int lheight = height(root->left);
       int rheight = height(root->right);
       return max(lheight,rheight) +1;
        
    }
};