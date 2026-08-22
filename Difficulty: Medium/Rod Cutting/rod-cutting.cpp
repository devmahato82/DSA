class Solution {
  public:
    int helper(int ind, int len , vector<int> &price, vector<vector<int>>&dp){
        if(ind==0) return len*price[0];
        
        if(dp[ind][len] != -1) return dp[ind][len];
        int nottake = helper(ind-1,len, price,dp);
        int rodLength = ind + 1; // piece length
        int take =0;
        if(len >= rodLength) {
            take = price[ind] + helper(ind, len - rodLength, price,dp);
        }
        return dp[ind][len] = max(take,nottake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return helper(n-1,n,price,dp);
    }
};