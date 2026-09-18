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

        vector<vector<long long>> dp(n, vector<long long>(amount + 1, INT_MAX));

        for(int i = 0; i < n; i++)
            dp[i][0] = 0;

        for(int j = 0; j <= amount; j++) {
            if(j % coins[n-1] == 0)
                dp[n-1][j] = j / coins[n-1];
        }

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= amount; j++) {

                long long nottake = dp[i+1][j];

                long long take = INT_MAX;
                if(j >= coins[i] && dp[i][j - coins[i]] != INT_MAX) {
                    take = 1 + dp[i][j - coins[i]];
                }

                dp[i][j] = min(take, nottake);
            }
        }

        return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
    }

};