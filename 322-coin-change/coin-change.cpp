class Solution {
public:
    long long f(int ind, int amount,int n, vector<int>& coins, vector<vector<long long>>& dp) {
        if(ind == n) {
            if(amount%coins[ind] == 0) return amount/coins[ind];
            else return INT_MAX;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        long long nottake = f(ind+1,amount,n,coins,dp);
        long long take = INT_MAX;
        if(amount>= coins[ind]) {
            take = 1 + f(ind,amount-coins[ind], n, coins, dp);
        }
        return dp[ind][amount] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long>> dp(n+1, (vector<long long>(amount+1,-1)));
        long long ans = f(0,amount,n-1,coins,dp);
        return ans== INT_MAX ? -1: ans;
    }
};