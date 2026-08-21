class Solution {
  public:
  int helper(int ind, int target, vector<int>&arr, vector<vector<int>> &dp) {
      if (ind < 0) return target == 0 ? 1 : 0;
      if(target<0) return 0;
      if(dp[ind][target] != -1 ) return dp[ind][target];
      int nottake = helper(ind-1, target, arr, dp) ;
      int take = 0;
      if(arr[ind]<= target) {
          take = helper(ind-1, target-arr[ind], arr, dp);
      }
      return dp[ind][target] = take+nottake;
  }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum =0;
        for(int i=0; i<n; i++) {
            sum+=arr[i];
        }
        if ((sum - diff) < 0 || (sum - diff) % 2 != 0) return 0;
        int target = (sum-diff)/2;
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        return helper(n-1,target, arr, dp);
    }
};