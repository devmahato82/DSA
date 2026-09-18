class Solution {
public:
    long long f(int n, int amount, vector<int>& coins, vector<vector<long long>>& dp) {
        if(n==0) {
            if(amount%coins[n] == 0) return amount/coins[0];
            else return INT_MAX;
        }

        if(dp[n][amount] != -1) return dp[n][amount];
        
        long long nottake = f(n-1, amount, coins, dp);
        long long take = INT_MAX;
        if(amount>= coins[n]) 
            take = 1 + f(n, amount-coins[n], coins, dp);
        return dp[n][amount] = min(nottake, take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1,-1));

        long long ans = f(n-1, amount, coins, dp);
        return ans==INT_MAX ? -1:ans;
    }
};