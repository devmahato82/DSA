class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minprice = INT_MAX;
        int profit =0;
        for(int i=0;i<n;i++){
            minprice = min(prices[i],minprice);
            profit = max(profit, prices[i]-minprice);
        }
        return profit;
    }
};