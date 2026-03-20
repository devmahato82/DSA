class Solution {
public:

    const int inf = 1e9;

    int F(int p, int q, int k, vector<vector<int>> &grid){

        set<int> st;
        for(int i = p; i <= p + k - 1; i++){
            for(int j = q; j <= q + k - 1; j++){
               st.insert(grid[i][j]); 
            }
        }

        if(st.size() == 1) return 0;

        int prev = -inf;
        int res = inf;

        for(auto &i: st){
            res = min(res, i - prev);
            prev = i;
        }
        return res;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        vector<vector<int>> ans;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i <= n - k; i++){
            vector<int> currAns;
            for(int j = 0; j <= m - k; j++){
                int res = F(i, j, k, grid);
                currAns.push_back(res);
            }

            ans.push_back(currAns);
        }

        return ans;
    }
};