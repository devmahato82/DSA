class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> nums(n,vector<int>(m,0));
        vector<vector<int>> x(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 'X'){
                    nums[i][j] =1;
                    x[i][j] = 1;
                }
                if(grid[i][j] == 'Y'){
                    nums[i][j] = -1;
                }
            }
        }
        vector<vector<int>> preSumnums(n,vector<int>(m,0));
        vector<vector<int>> preSumx(n,vector<int>(m,0));
        preSumnums[0][0] = nums[0][0];
        preSumx[0][0] = x[0][0];

        for(int i=1;i<n;i++){
            preSumnums[i][0]= preSumnums[i-1][0] + nums[i][0];
            preSumx[i][0] = preSumx[i-1][0] + x[i][0];
        }
        for(int j=1;j<m;j++){
            preSumnums[0][j]= preSumnums[0][j-1] + nums[0][j];
            preSumx[0][j] = preSumx[0][j-1] + x[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                preSumnums[i][j] = nums[i][j] + preSumnums[i-1][j] + preSumnums[i][j-1] - preSumnums[i-1][j-1];
                preSumx[i][j] = x[i][j] + preSumx[i-1][j] + preSumx[i][j-1] - preSumx[i-1][j-1];
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(preSumnums[i][j]==0 && preSumx[i][j]>=1){
                    count++;
                }
            }
        }
        return count;


    }
};