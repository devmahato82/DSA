class Solution {
  public:
    int helper(int ind, int w, vector<int>& val, vector<int>& wt, vector<vector<int>> &dp) {
        if(ind==0 ) {
            if(w>=wt[ind]) return val[ind];
            else return 0;
        }
        if(w<0) return 0;
        if(dp[ind][w] != -1) return dp[ind][w];
        int nottake = helper(ind-1,w,val,wt, dp);
        int take = 0;
        if(w>= wt[ind] ){
            take = val[ind] + helper(ind-1, w-wt[ind], val, wt,dp);   
        }
        return dp[ind][w] = max(take, nottake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1,-1));
        return helper(n-1,W,val,wt,dp);
    }
};