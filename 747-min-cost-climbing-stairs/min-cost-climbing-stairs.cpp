class Solution {
public:
    int helper(vector<int>& cost , int n, vector<int>& dp){
        if(n==0 || n==1) return dp[n] = cost[n];
        if(dp[n] !=-1) return dp[n];
        return dp[n] = cost[n] + min(helper(cost,n-1,dp), helper(cost,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()-1;
        vector<int> dp(n+1,-1);
        return min(helper(cost,n,dp), helper(cost,n-1,dp));
    }
};