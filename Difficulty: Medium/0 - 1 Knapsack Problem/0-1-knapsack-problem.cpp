class Solution {
  public:
    int f(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
        if(ind == 0){
            if(wt[0] <= w) return dp[ind][w] =  val[0];
            return dp[ind][w] =  0;
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int notTake = 0 + f(ind-1, w, wt, val,dp);
        int take  = INT_MIN;
        if(wt[ind] <= w){
            take = val[ind] + f(ind-1, w- wt[ind], wt, val,dp);
        }
        return dp[ind][w] = max(notTake, take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int> (W+1, -1));
        return f(n-1,W, wt,val,dp);
    }
};