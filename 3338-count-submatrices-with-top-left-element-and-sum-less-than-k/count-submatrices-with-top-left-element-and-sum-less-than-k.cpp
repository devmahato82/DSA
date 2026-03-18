class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> preSum(n+1, vector<int>(m+1, 0));
        preSum[0][0] = grid[0][0];
        for(int j=1;j<m;j++){
            preSum[0][j] = grid[0][j] + preSum[0][j-1];
        }
        for(int i=1;i<n;i++){
            preSum[i][0] = grid[i][0] + preSum[i-1][0];
        }
        for(int i=1; i<n;i++){
            for(int j=1; j<m;j++){
                preSum[i][j] = grid[i][j] + preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1];
            }
        }
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(preSum[i][j]<=k) count++;
            }
        }
        return count;
    }
};