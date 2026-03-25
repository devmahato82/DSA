class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> preSum(n,vector<long long>(m,0));
        preSum[0][0]= grid[0][0];
        for(int j=1;j<m;j++){
            preSum[0][j] = preSum[0][j-1] + grid[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0) preSum[i][j] = preSum[i-1][m-1] + grid[i][j];
                else{
                    preSum[i][j] = preSum[i][j-1] + grid[i][j];
                }
            }
        }
        vector<vector<long long>> preSumC(n,vector<long long>(m,0));
        preSumC[0][0]= grid[0][0];
        for(int i=1;i<n;i++){
            preSumC[i][0] = preSumC[i-1][0] + grid[i][0];
        }
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                if(i==0) preSumC[i][j] = preSumC[n-1][j-1] + grid[i][j];
                else{
                    preSumC[i][j] = preSumC[i-1][j] + grid[i][j];
                }
            }
        }
        if(preSum[n-1][m-1]%2==0) {
            for(int i=0;i<n-1;i++){
                if(preSum[i][m-1]==preSum[n-1][m-1]/2) return true;
            }
            for(int j=0;j<m-1;j++){
                if(preSumC[n-1][j] == preSum[n-1][m-1]/2) return true;
            }
        }
        else return false;
        return false;
    }
};