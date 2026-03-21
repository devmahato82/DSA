class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int count =0;
        int ones =0;
        queue<pair<int,int>> q;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j] == 2){
                    q.push({i,j});
                }
                if(mat[i][j] == 1) ones++;
            }
        }
        q.push({-1,-1});
        while(q.size()>0){
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(row == -1 && col== -1){
                count++;
                if(q.size()>0) q.push({-1,-1});
                continue;
            }
            if(row>0 && mat[row-1][col] == 1) {
                mat[row-1][col] = 2;
                ones--;
                q.push({row-1,col});
            }
            if( row<n-1  && mat[row+1][col] == 1) {
                mat[row+1][col] = 2;
                ones--;
                q.push({row+1,col});
            }
            if(col>0 && mat[row][col-1] == 1) {
                mat[row][col-1] = 2;
                ones--;
                q.push({row,col-1});
            }
            if(col<m-1  && mat[row][col+1] == 1) {
                mat[row][col+1] = 2;
                ones--;
                q.push({row,col+1});
            }
            
        }
        return (ones==0)? count-1:-1;
    }
};