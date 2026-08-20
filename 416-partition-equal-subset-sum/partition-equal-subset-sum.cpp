class Solution {
public:
    bool helper(int ind, int target, vector<int>&nums, vector<vector<int>> &dp) {
        if(target==0) return true;
        if(ind ==0) return (nums[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool nottake = helper(ind-1, target,nums, dp);
        bool take = false;
        if(nums[ind]<= target) {
            take = helper(ind-1, target-nums[ind], nums, dp);
        } 
        return dp[ind][target] = take | nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0; i<n; i++) {
            sum+=nums[i];
        }
        if(sum%2 !=0) return false;
        vector<vector<bool>> dp(n, vector<bool>(sum/2 +1,false));
        //return helper(n-1, sum/2, nums, dp);

        for(int i=0; i<n; i++) dp[i][0] = true;
        if(nums[0]<= sum/2) dp[0][nums[0]] =  true;
        for(int ind =1; ind<n; ind++) {
            for(int target=1; target<= sum/2; target++) {
                bool nottake = dp[ind-1][target];
                bool take = false;
                if(nums[ind]<= target) {
                    take = dp[ind-1][target-nums[ind]];
                } 
                dp[ind][target] = take | nottake;
            }
        }
        return dp[n-1][sum/2];


    }
};