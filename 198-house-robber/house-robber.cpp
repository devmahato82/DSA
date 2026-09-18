class Solution {
public:
    int find(int ind, int n, vector<int>& nums, vector<int>& dp) {
        if(ind>=n) return 0;
        
        if(dp[ind] != -1) return dp[ind];

        int houserob = nums[ind] + find(ind+2, n, nums, dp);
        int housenotrob = find(ind+1, n, nums,dp);
        return dp[ind] = max(houserob, housenotrob);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return find(0,n,nums,dp);
    }
};