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
    int helper(TreeNode* root,int target, long long currSum, unordered_map<long long,int> &prefixSum) {
        if(root == NULL) return 0;
        currSum += root->val;
        int count = 0;
        if(prefixSum.find(currSum-target) != prefixSum.end()){
            count += prefixSum[currSum-target];
        }
        prefixSum[currSum]++;
        count += helper(root->left,target,currSum, prefixSum) + helper(root->right,target,currSum, prefixSum);
        prefixSum[currSum]--;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> prefixSum;
        prefixSum[0]=1;
        return helper(root,targetSum,0,prefixSum);
    }
};