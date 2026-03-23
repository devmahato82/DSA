class Solution {
public:
    int helper(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(n==0 && m==0 ) return dp[n][m] =1;
        if(n<0 || m<0) return 0;
        if(grid[n][m] == 1) return dp[n][m] =0;
        if(dp[n][m] != -1) return dp[n][m];
        return dp[n][m] = helper(n-1,m,grid,dp) + helper(n,m-1,grid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,grid,dp);
        
    }
};