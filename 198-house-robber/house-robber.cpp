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
        // vector<int> dp(n+2,-1);
        // return find(0,n,nums,dp);
        vector<int> dp(n+2);

        dp[n] = dp[n+1] = 0;

        for(int i=n-1; i>=0; i--) {
            int robhouse = nums[i] + dp[i+2];
            int notrobhouse = dp[i+1];
            dp[i] = max(robhouse, notrobhouse);
        }

        return dp[0];
    }
};