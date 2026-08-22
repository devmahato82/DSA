class Solution {
  public:
    int helper(int ind, int capacity, vector<int> &val, vector<int>&wt, vector<vector<int>> &dp) {
        if(ind == 0) {
            if(wt[0]<= capacity) return val[0] * (capacity/wt[0]);
            return 0;
        }
        if(capacity<0) return 0;
        if(dp[ind][capacity] != -1) return dp[ind][capacity];
        int nottake = helper(ind-1, capacity, val, wt,dp);
        int take =0;
        if(wt[ind]<= capacity) {
            take = val[ind]+ helper(ind,capacity-wt[ind], val, wt,dp);
        }
        return dp[ind][capacity] = max(take, nottake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1,-1));
        return helper(n-1,capacity,val, wt, dp);
    }
};