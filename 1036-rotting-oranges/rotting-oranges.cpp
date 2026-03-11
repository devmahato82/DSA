class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
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
                
                continue;
            }
            for(int d=0;d<4;d++){
                int nr = currRow + dir[d][0];
                int nc = currCol + dir[d][1];
                if(nr<0 or nc<0 or nr >=rows or nc >= cols) continue;
                if(grid[nr][nc] !=1) continue;
                fo--;
                grid[nr][nc] = 2;
                q.push({nr,nc});

            }
        }
        
        return (fo==0) ? mins-1 : -1;
    }
};