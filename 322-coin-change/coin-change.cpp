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
        // vector<vector<long long>> dp(n, vector<long long>(amount+1,-1));

        // long long ans = f(n-1, amount, coins, dp);
        // return ans==INT_MAX ? -1:ans;

        vector<vector<long long>> dp(n, vector<long long>(amount+1));
        for(int i=0; i<n; i++) {
            dp[i][0] = 0;
        }
        for(int j=1; j<= amount; j++) {
           if(j%coins[0] == 0) dp[0][j] = j/coins[0];
           else dp[0][j] = INT_MAX;
        }

        for(int i=1; i<n;i++) {
            for(int j=1; j<= amount; j++) {
                long long nottake = dp[i-1][j];
                long long take = INT_MAX;
                if(j>=coins[i]) take = 1 + dp[i][j-coins[i]];
                dp[i][j] = min(nottake, take);
            }
        }
        int ans = dp[n-1][amount];
        return ans==INT_MAX ? -1:ans;

        

    }
};