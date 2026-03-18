/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int dfs(Node* root, int& ans){
        if(root== NULL) return 0;
        int l = dfs(root->left,ans);
        int r = dfs(root->right,ans);
        ans += abs(l)+abs(r);
        return root->data+l+r-1;
    }
    int distCandy(Node* root) {
        // code here
        int ans =0;
        dfs(root,ans);
        return ans;
    }
};