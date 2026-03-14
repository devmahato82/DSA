/*
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
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
         vector<int> ans;
         map<int,int> mp;
         queue<pair<Node*, int>> q;
         q.push({root,0});
         while(q.size()>0){
             Node* temp = q.front().first;
             int level = q.front().second;
             q.pop();
             if(mp.find(level)==mp.end()){
                 mp[level] = temp->data;
             }
             if(temp->left != NULL) {
                 q.push({temp->left,level-1});
             } 
             if(temp->right != NULL) {
                 q.push({temp->right,level+1});
             }
         }
         for(auto x:mp){
             ans.push_back(x.second);
         }
         return ans;
    }
};