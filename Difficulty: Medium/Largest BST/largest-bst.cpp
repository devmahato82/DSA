/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

struct node{
    int sz;
    bool isValid;
    int mxval;
    int minval;
};

class Solution {
public:
    int largestBst(Node *root) {
        
        const int inf = 1e9;
        int ans = 0;
        
        auto F = [&](Node* root, auto &&self) -> node {
            
            if(root == NULL){
                return {0, true, -inf, inf};
            }
            
            node left = self(root->left, self);
            node right = self(root->right, self);
            
            node curr;
            
            if(left.isValid && right.isValid &&
               root->data > left.mxval &&
               root->data < right.minval){
                
                curr.sz = left.sz + right.sz + 1;
                curr.isValid = true;
                curr.mxval = max(root->data, right.mxval);
                curr.minval = min(root->data, left.minval);
                
                ans = max(ans, curr.sz);
            }
            else{
                curr.sz = 0;
                curr.isValid = false;
                curr.mxval = inf;
                curr.minval = -inf;
            }
            
            return curr;
        };
        
        F(root, F);
        return ans;
    }
};