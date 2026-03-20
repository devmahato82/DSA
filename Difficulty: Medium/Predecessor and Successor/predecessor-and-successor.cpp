/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void dfs(Node* root, vector<Node*> &a , vector<int> &nums){
      if(root== NULL) return;
      dfs(root->left, a,nums);
      a.push_back(root);
      nums.push_back(root->data);
      dfs(root->right, a,nums);
  }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> arr;
        vector<int> nums;
        dfs(root,arr,nums);
        //if(key>= nums[arr.size()-1] || key<= nums[0]) return {NULL,NULL};
        Node* pre = NULL;
        Node* suc = NULL;
        for(int i=0;i<arr.size();i++){
            if(nums[i]==key){
                if(i>0) pre = arr[i-1];
                if(i<arr.size()-1) suc = arr[i+1];
                break;
            }
            else if(nums[i]>key){
                suc = arr[i];
                if(i>0) pre = arr[i-1];
                break;
            }
        }
        if(pre == NULL && key> nums[arr.size()-1]){
            pre = arr[arr.size()-1];
        }
        return {pre,suc};
    }
};