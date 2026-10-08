class Solution {
public:
    int f(int ind, int trans, vector<int>& prices, vector<vector<int>>& dp) {
        if(ind == prices.size() || trans ==4) return 0;
        if(dp[ind][trans] != -1) return dp[ind][trans];

        if(trans%2==0) return 
        dp[ind][trans] = max(-prices[ind] + f(ind+1, trans+1, prices, dp), f(ind+1,trans, prices, dp));

        else 
        return 
        dp[ind][trans] = max(prices[ind] + f(ind+1, trans+1 , prices, dp), f(ind+1, trans, prices, dp));

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>> dp(n+1, vector<int>(5,0));
        vector<int> after(5,0);

        for(int ind= n-1; ind>=0; ind--) {
            vector<int> curr(5,0);
            for(int trans = 3; trans>=0; trans--) {
                if(trans%2==0) curr[trans] = max(-prices[ind] + after[trans+1], after[trans]);
                else curr[trans] = max(prices[ind] + after[trans+1], after[trans]);
            }
            after = curr;
        }

        return after[0];
    }
};