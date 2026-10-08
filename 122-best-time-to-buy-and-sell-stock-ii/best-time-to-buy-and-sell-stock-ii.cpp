class Solution {
public:
    int f(int ind , int buy, vector<int>&prices, vector<vector<int>>& dp) {
        if(ind == prices.size()) return 0;
        if(dp[ind][buy] !=-1) return dp[ind][buy];
        int profit =0;
        if(buy) {
            profit = max(-prices[ind] + f(ind+1, 0, prices,dp), f(ind+1, 1, prices,dp));
        }
        else {
            profit = max(prices[ind] + f(ind+1, 1, prices,dp), f(ind+1, 0, prices,dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       
       int aheadbuy, aheadnotbuy, currbuy, currnotbuy;
       aheadbuy = aheadnotbuy = 0;
        for(int ind =n-1; ind >=0; ind--) {
            currbuy = max(-prices[ind] + aheadnotbuy, aheadbuy);
            currnotbuy = max(prices[ind] + aheadbuy, aheadnotbuy);
            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
        return aheadbuy;
    }
};