class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(2, vector<long long>(3,0)));
        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy = 0; buy <2; buy++) {
                for(int cap =1; cap <3; cap++) {
                    if(buy) {
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap], dp[ind+1][1][cap]);
                    }
                    else dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                }
            }
        }
        return dp[0][1][2];
    }
};