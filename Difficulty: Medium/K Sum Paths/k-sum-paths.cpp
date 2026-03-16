/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int helper(Node* root, int k, int currSum, unordered_map<int,int> &prefixSum){
      if(root== NULL) return 0;
      currSum += root->data;
      int count =0;
      if(prefixSum.find(currSum-k) != prefixSum.end()){
          count+= prefixSum[currSum-k];
      }
      prefixSum[currSum]++;
      count += helper(root->left,k,currSum,prefixSum);
      count += helper(root->right,k,currSum,prefixSum);
      prefixSum[currSum]--;
      return count;
  }
    int countAllPaths(Node *root, int k) {
        // code here
        unordered_map<int,int> prefixSum;
        prefixSum[0]=1;
        int count = helper(root,k,0,prefixSum);
        return count;
    }
};