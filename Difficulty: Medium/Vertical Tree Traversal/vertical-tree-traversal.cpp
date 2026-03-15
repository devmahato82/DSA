/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>>ans;
        map<int,vector<int>> m;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(q.size()!=0){
            Node* temp = q.front().first;
            int col = q.front().second;
            q.pop();
            m[col].push_back(temp->data);
            if(temp->left != NULL) q.push({temp->left,col-1});
            if(temp->right != NULL) q.push({temp->right,col+1});
        }
        for(auto x : m){
            ans.push_back(x.second);
        }
        return ans;
    }
};