class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //vector<vector<int>>dp(n+1, vector<int>(2,0));
        vector<int> after(2,0);
        for(int ind=n-1; ind>=0; ind--) {
            vector<int> curr(2,0);
            for(int buy=0; buy<2; buy++) {
                if(buy) curr[buy] = max(-prices[ind] + after[0], after[1]);
                else curr[buy] = max(prices[ind] + after[1]-fee, after[0]);
            }
            after = curr;
        }
        return after[1];
    }
};