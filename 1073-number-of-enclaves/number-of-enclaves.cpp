class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,-1));
        int count =0;
        int co=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if((i==0 || i==m-1 || j==0 ||j==n-1) && grid[i][j] == 1) {
                    count++; 
                    q.push({i,j});
                    vis[i][j]=1;
                    co++;
                }
                else if(grid[i][j] == 1) co++;
            }
        }


        // for(int i=0; i<m; i++){
        //     for(int j: {0,n-1}){
        //         if(grid[i][j] == 1){
        //             q.push({i,j});
        //             vis[i][j]=1;
        //             count++;
        //         }
        //     }
        // }
        // for(int j=1; j<n-1; j++){
        //     for(int i: {0,m-1}){
        //         if(grid[i][j] == 1){
        //             q.push({i,j});
        //             vis[i][j]=1;
        //             count++;
        //         }
        //     }
        // }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==-1 && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                    count++;
                }
            }
        }
        // int co=0;
        // for(int i=0; i<m; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(grid[i][j] == 1) co++;
        //     }
        // }
        return co-count;
    }
};