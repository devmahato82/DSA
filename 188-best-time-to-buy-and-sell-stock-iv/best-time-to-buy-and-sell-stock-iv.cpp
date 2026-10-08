class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));
        vector<vector<int>> after(2, vector<int>(k+1,0));

        for(int ind=n-1; ind>=0; ind--) {
            vector<vector<int>> curr(2, vector<int>(k+1,0));
            for(int buy =0; buy<2; buy++) {
                for(int trans =1; trans <=k; trans++) {
                    if(buy)
                    curr[buy][trans] = max(-prices[ind] + after[0][trans], after[1][trans]);
                    else 
                    curr[buy][trans] = max(prices[ind] + after[1][trans-1], after[0][trans]);
                }
            }
            after =  curr;
        }
        return after[1][k];
    }
};