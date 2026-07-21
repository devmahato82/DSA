class Solution {
public:
    bool helper(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
        if( target==0) return true;
        if(ind ==0 ) return (nums[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool nottake = helper(nums, ind-1, target, dp);
        bool take = false;
        if(target >= nums[ind]) {
            take = helper(nums, ind-1, target-nums[ind], dp);
        }
        return dp[ind][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum+= nums[i];
        }
        if(sum%2 != 0) return false;
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        return helper(nums,n-1,target, dp);

    }
};