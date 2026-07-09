/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(root == NULL || (root->left == NULL && root->right == NULL)) return true;
        int sum =0;
        if(root->left !=NULL) sum += root->left->data;
        if(root->right !=NULL) sum += root->right->data;
        if(sum != root->data) return false;
        
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};