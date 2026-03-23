class Solution {
public:
    int helper(int sr, int sc, int m,int n, vector<vector<int>>& dp){
        if(sr ==m && sc == n) return dp[sr][sc] =1;
        if(sr>m || sc >n) return 0;
        if(dp[sr][sc] != -1) return dp[sr][sc];
        return dp[sr][sc] = helper(sr+1,sc,m,n,dp) + helper(sr,sc+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(0,0,m-1,n-1,dp);
    }
};