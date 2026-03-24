class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        const int mod = 12345;

        for(auto &i: grid){
            for(auto &j: i){
                j = (j % mod);
            }
        }

        vector<vector<int>> pre(n, vector<int>(m,1));


        int prod = 1;
        for(int j = 0; j < m; j++){
            prod = (prod * grid[0][j]) % mod;

            pre[0][j] = prod;
        }

        
        for(int i = 1; i < n; i++){
            prod = 1;
            for(int j = 0; j < m; j++){
                prod = (prod * grid[i][j]) % mod;
                pre[i][j] = (prod * pre[i-1][j]) % mod;
                
            }
        }

        for(auto &i: pre){
            for(auto &j: i){
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
        prod = 1;
        vector<vector<int>> suf(n, vector<int>(m,1));

        for(int j = m - 1; j >= 0; j--){
            prod = (prod * grid[n-1][j]) % mod;
            suf[n-1][j] = prod;
        }

        for(int i = n - 2; i >= 0; i--){
            prod = 1;
            for(int j = m - 1; j >= 0; j--){
                prod = (prod * grid[i][j]) % mod;
                suf[i][j] = (prod * suf[i+1][j]) % mod;
            }
        }

        for(auto &i: suf){
            for(auto &j: i){
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;

        vector<vector<int>> ans(n, vector<int>(m, 1));

        for(int i = 0; i < n; i++){
            int u = (i == 0 ? 1 : pre[i-1][m-1]);
            int d = (i == n - 1 ? 1 : suf[i + 1][0]);

            vector<int> currp(m), currs(m);
            prod = 1;
            for(int j = 0; j < m; j++){
                prod = (prod * grid[i][j]) % mod;
                currp[j] = prod;
            }
            prod = 1;
            for(int j = m - 1; j >= 0; j--){
                prod = (prod * grid[i][j]) % mod;
                currs[j] = prod;
            }

            for(int j = 0; j < m; j++){
                int currProd = (u * d) % mod;
                if(j - 1 >= 0){
                    currProd = (currProd * currp[j-1]) % mod;
                }

                if(j + 1 <= m - 1){
                    currProd = (currProd * currs[j + 1]) % mod;
                }

                ans[i][j] = currProd;
            }


        }

        return ans;
    }
};