class Solution {
public:
    int f(int n, vector<int>& nums, vector<int>& dp) {
        if(n<0) return 0;
        if(n==0) return nums[n];
        if(dp[n] != -1 ) return dp[n];
        int take = nums[n] + f(n-2, nums,dp);
        int nottake = f(n-1, nums, dp);
        return dp[n] = max(take, nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return f(n-1,nums,dp);
    }
};