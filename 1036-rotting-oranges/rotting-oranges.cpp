class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<pair<pair<int,int>, int>>q;
        int fo=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) fo++;
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        int tm = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                int nt = t+1;
                if(nrow >=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1 && vis[nrow][ncol] !=2) {
                    q.push({{nrow,ncol},nt});
                    vis[nrow][ncol] = 2;
                    fo--;
                    tm = max(tm,nt);
                }
            }
        }
        return (fo == 0) ? tm : -1;
    }
};