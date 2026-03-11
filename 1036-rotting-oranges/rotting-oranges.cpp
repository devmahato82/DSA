class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int fo = 0;
        for(int i=0; i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1) fo++;
                else if(grid[i][j] == 2) q.push({i,j}); //multi source bfs step
            }
        }
        // we have added all the source
        q.push({-1,-1});
        int mins =0;
        while(q.size()>0){
            
            auto curr = q.front();
            q.pop();
            int currRow = curr.first;
            int currCol = curr.second;
            if(currRow ==-1 && currCol == -1){
                mins++;
                if(q.size()>0) q.push({-1,-1});
                else break;
                continue;
            }
            if(currRow>0 && grid[currRow-1][currCol]==1) {
                q.push({currRow-1,currCol});
                grid[currRow-1][currCol] = 2;
                fo--;
            }
            if(currRow<rows-1 && grid[currRow+1][currCol]==1) {
                q.push({currRow+1,currCol});
                grid[currRow+1][currCol] = 2;
                fo--;
            }
            if(currCol > 0 && grid[currRow][currCol-1]==1) {
                q.push({currRow,currCol-1});
                grid[currRow][currCol-1] = 2;
                fo--;
            }
            if(currCol < cols-1 && grid[currRow][currCol+1]==1) {
                q.push({currRow,currCol+1});
                grid[currRow][currCol+1] = 2;
                fo--;
            }
        }
        
        return (fo==0) ? mins-1 : -1;
    }
};