class Solution {
public:
    int helper(int ind, int target, vector<int> &nums, vector<vector<int>> & dp, int sum) {
        if(target < -sum || target > sum) return 0;
        if(ind==0){
            if(target == nums[0] && target == -nums[0]) return 2;
            if(target == nums[0] || target == -nums[0]) return 1;
            return 0;
        }

        if(dp[ind][target+sum] != -1) return dp[ind][target+sum];
        int plus = helper(ind-1, target-nums[ind],nums,dp,sum);
        int minus = helper(ind-1, target+nums[ind], nums,dp, sum);
        return dp[ind][target+sum]= plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum =0;
        for(int x:nums) sum+=x;
        vector<vector<int>> dp(n, vector<int>(2*sum+1,-1));
        return helper(n-1,target, nums, dp, sum);
    }
};