class Solution {
public:
    int mod = (int) 1e9+7;
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,0);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) dp[j] = 0;
                else if(i==0 && j==0) dp[j] = 1;
                else{
                    int up =0, left=0;
                    if(i>0) up = dp[j];
                    if(j>0) left = dp[j-1];
                    dp[j] = up+left;
                } 
            }
        }
        return dp[n-1];
    }
};