/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void leftBoundry(Node* root, vector<int>& ans) {
        if(root==NULL || (root->left == NULL && root->right == NULL)) return ;
        ans.push_back(root->data);
        if(root->left) leftBoundry(root->left,ans);
        else leftBoundry(root->right, ans);
    }
    
    void leafBoundry(Node* root, vector<int>& ans){
        if(root==NULL) return;
        if(root->left == NULL && root->right==NULL) {
            ans.push_back(root->data);
            return;
        }
        leafBoundry(root->left, ans);
        leafBoundry(root->right,ans);
    }
    
    void rightBoundry(Node* root, stack<int>& st) {
        if(root==NULL || (root->left == NULL && root->right == NULL)) return ;
        st.push(root->data);
        if(root->right) rightBoundry(root->right,st);
        else rightBoundry(root->left, st);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        ans.push_back(root->data);
        stack<int> st;
        leftBoundry(root->left,ans);
        leafBoundry(root->left, ans);
        leafBoundry(root->right, ans);
        rightBoundry(root->right,st);
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};