class Solution {
public:
    int helper(vector<int>&nums, int i,vector<int>& dp) {
        if(i>=nums.size() ) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = nums[i] + max(helper(nums,i+2,dp),helper(nums,i+3,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return max(helper(nums,0,dp),helper(nums,1,dp));
    }
};