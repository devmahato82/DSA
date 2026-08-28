class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'X'));
        vector<vector<int>> vis(m,vector<int>(n,-1));
        queue<pair<int,int>> q;

        for(int j=0;j<n;j++){
            if(board[0][j] == 'O') {
                ans[0][j] = 'O';
                vis[0][j] = 1;
                q.push({0,j});
            }
        }
        for(int i=1;i<m;i++){
            if(board[i][0] == 'O') {
                ans[i][0] = 'O';
                vis[i][0] = 1;
                q.push({i,0});
            }
        }
        for(int i=1;i<m;i++){
            if(board[i][n-1] == 'O') {
                ans[i][n-1] = 'O';
                vis[i][n-1] = 1;
                q.push({i,n-1});
            }
        }
        for(int j=1;j<n-1;j++){
            if(board[m-1][j] == 'O') {
                ans[m-1][j] = 'O';
                vis[m-1][j] = 1;
                q.push({m-1,j});
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = r +drow[i];
                int ncol = c+ dcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] ==-1 && board[nrow][ncol] == 'O' ){
                    q.push({nrow,ncol});
                    ans[nrow][ncol] = 'O';
                    vis[nrow][ncol] = 1;
                }
            }
        }
        board = ans;
        return;
    }
};