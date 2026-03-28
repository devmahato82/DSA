class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j,int m, int n,int currXOR,vector<vector<int>>&dp){
        if(i==m-1 && j ==n-1) return dp[i][j] = currXOR^grid[i][j];
        //if(dp[i][j] != -1) return dp[i][j] ;
        int res = INT_MAX;
        if(j+1<n) {
            res = min(res,helper(grid,i,j+1,m,n,currXOR^grid[i][j],dp));
        }
        if(i+1<m){
            res = min(res,helper(grid,i+1,j,m,n,currXOR^grid[i][j],dp));
        }
        return dp[i][j]= res;
    }
    int minCost(vector<vector<int>>& grid) {
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return helper(grid,0,0,m,n,0,dp);

        int n = (int)grid.size();
        int m = (int)grid[0].size();
        int mx = 1LL << 10;
        int dp[n][m][mx];

        memset(dp, 0, sizeof(dp));

        dp[0][0][grid[0][0]] = 1;

        for(int i = 1; i < n; i++){
            for(int mask = 0; mask < mx; mask++){
                dp[i][0][mask] = (dp[i-1][0][mask ^ grid[i][0]]); 
            }
        }

        for(int j = 1; j < m; j++){
            for(int mask = 0; mask < mx; mask++){
                dp[0][j][mask] = dp[0][j-1][mask ^ grid[0][j]];
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                for(int mask = 0; mask < mx; mask++){
                    dp[i][j][mask] = (dp[i][j][mask]  || dp[i-1][j][mask ^ grid[i][j]]);
                    
                    dp[i][j][mask] = (dp[i][j][mask] || dp[i][j-1][mask ^ grid[i][j]]);
                }
            }
        }

        for(int mask = 0; mask < mx; mask++){
            if(dp[n-1][m-1][mask]) return mask;
        }

        return -1;

    }
};