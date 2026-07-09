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
        queue<Node*> q;
        q.push(root);
        int depth =0;
        while(q.size() != 0){
            int levelsize = q.size();
            for(int i=0; i< levelsize; i++) {
                Node* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            depth++;
        }
        return depth -1;
        
    }
};