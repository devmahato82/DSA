class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,-1));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    vis[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty() ) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int level = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = r+ drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] ==-1){
                    q.push({{nrow,ncol},level+1});
                    vis[nrow][ncol] = level+1;
                }
            }
            
        }
        return vis;
        
    }
};