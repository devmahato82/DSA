class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cc=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '0'){
                    continue;
                }
                cc++;
                grid[i][j] = '0';
                queue<pair<int,int>> q;
                q.push({i,j});
                while(q.size()>0){
                    auto curr = q.front();
                    q.pop();
                    int currRow = curr.first;
                    int currCol = curr.second;
                    if(currRow>0 && grid[currRow-1][currCol] == '1'){
                        q.push({currRow-1,currCol});
                        grid[currRow-1][currCol] = '0';
                    }
                    if(currRow<rows-1 && grid[currRow+1][currCol] == '1'){
                        q.push({currRow+1,currCol});
                        grid[currRow+1][currCol] = '0';
                    }
                    if(currCol>0 && grid[currRow][currCol-1] == '1'){
                        q.push({currRow,currCol-1});
                        grid[currRow][currCol-1] = '0';
                    }
                    if(currCol<cols-1 && grid[currRow][currCol+1] == '1'){
                        q.push({currRow,currCol+1});
                        grid[currRow][currCol+1] = '0';
                    }
                }
                
            }
        }
        return cc;
    }
};