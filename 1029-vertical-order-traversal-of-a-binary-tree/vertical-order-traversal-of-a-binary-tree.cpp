/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(q.size()!=0){
            TreeNode* temp = q.front().first;
            int col = q.front().second.first;
            int row = q.front().second.second;
            q.pop();
            m[col][row].insert(temp->val);
            if(temp->left!= NULL) q.push({temp->left, {col-1,row+1}});
            if(temp->right != NULL) q.push({temp->right, {col+1,row+1}});
        }
        for(auto x: m){
            vector<int> b;
            for(auto y:x.second ){
                b.insert(b.end(),y.second.begin(), y.second.end());
            }
            ans.push_back(b);
        }
        return ans;
    }
};