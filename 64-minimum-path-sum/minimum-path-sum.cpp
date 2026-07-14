class Solution {
public:
    int minPath(int i, int j, vector<vector<int>>&grid, vector<vector<int>>& dp) {
        if(i==0 && j==0) return dp[i][j] = grid[i][j];
        
        if(dp[i][j] != -1) dp[i][j];
        int up = INT_MAX, left = INT_MAX;
        if(i>0) up = grid[i][j] + minPath(i-1, j, grid, dp);
        if(j>0) left = grid[i][j] + minPath(i, j-1, grid, dp);
        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++) {
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else {
                    int right = INT_MAX, down = INT_MAX;
                    if(i>0) right = grid[i][j] + dp[i-1][j];
                    if(j>0) down = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(right, down);
                }
            }
        }
        return dp[m-1][n-1];

       // return minPath(m-1, n-1, grid, dp);
    }
};