class Solution {
public:

    vector<vector<int>> F(int n, int m, vector<vector<int>> a){

        auto psum = a;

        for(int i = 1; i < n; i++){
            psum[i][0] = psum[i-1][0] + a[i][0];
        }

        for(int j = 1; j < m; j++){
            psum[0][j] = psum[0][j-1] + a[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                psum[i][j] = psum[i-1][j] + psum[i][j-1] + a[i][j] - psum[i-1][j-1];
            }
        }

        return psum;

    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        

        int n = (int)grid.size();
        int m = (int)grid[0].size();

        vector<vector<int>> x(n, vector<int>(m, 0));
        vector<vector<int>> y(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                x[i][j] = (grid[i][j] == 'X');
                y[i][j] = (grid[i][j] == 'Y');
            }
        }

        auto px = F(n, m, x);
        auto py = F(n, m, y);

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(px[i][j] == 0) continue;
                if(px[i][j] == py[i][j]) ans++;
            }
        }

        return ans;
    }
};