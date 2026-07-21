class Solution {
  public:
    bool helper(vector<int>& arr, int ind, int sum, vector<vector<int>>& dp) {
        if(sum==0) return true;
        if(ind == 0 ) return (arr[ind] == sum);
        if(dp[ind][sum] != -1) return dp[ind][sum];
        bool nottake = helper(arr, ind-1, sum, dp);
        bool take = false;
        if(arr[ind]<=sum) {
            take = helper(arr, ind-1, sum-arr[ind], dp);
        }
        return dp[ind][sum] = nottake || take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n =  arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(arr,n-1,sum, dp);
    }
};