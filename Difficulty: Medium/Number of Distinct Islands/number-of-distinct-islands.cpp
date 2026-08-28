class Solution {
  public:
    void bfs(int i, int j,int m, int n, vector<vector<char>>& grid, vector<vector<int>>&vis, set<vector<pair<int,int>>>&s) {
        vector<pair<int,int>> ans;
        queue<pair<int, int>> q;
        q.push({i,j}) ;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            ans.push_back({r-i,c-j});
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==-1 && grid[nrow][ncol]=='L'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                    
                }
            }
        }
        s.insert(ans);
    }
    

    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<int>> vis(m, vector<int>(n,-1));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 'L' && vis[i][j] ==-1) {
                    bfs(i,j,m,n,grid, vis, s);
                }
            }
        }
        return s.size();
        
    }
};
