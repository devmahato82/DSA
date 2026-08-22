class Solution {
public:
    int helper(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(ind ==0) {
            if(amount % coins[0]==0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int nottake = helper(ind-1, amount, coins, dp);
        int take =1e9;
        if(amount>= coins[ind]) {
            take = 1+helper(ind, amount-coins[ind], coins, dp);
        }
        return dp[ind][amount] =  min(nottake, take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = helper(n-1,amount,coins, dp);
        return ans==1e9 ?-1: ans;
    }
};