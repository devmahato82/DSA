class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int count =0;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0;j<n; j++) {
                if(grid[i][j] == '1'){
                    count++;
                    grid[i][j] = '0';
                    q.push({i,j});
                    while(!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for(int i=0;i<4; i++) {
                            int nrow = r + drow[i];
                            int ncol = c + dcol[i];
                            if(nrow>=0 && nrow<m && ncol>=0 && ncol< n && grid[nrow][ncol]=='1') {
                                q.push({nrow,ncol});
                                grid[nrow][ncol] = '0';
                            }
                        }

                    }
                }
            }
        }
        return count;
    }
};