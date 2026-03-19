class Solution {
public:
    void dfs(int src, unordered_set<int> &vis,vector<vector<int>>graph){
        vis.insert(src);
        for(auto neighbour: graph[src]){
            if(vis.find(neighbour) == vis.end()){
                dfs(neighbour,vis,graph);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        vector<vector<int>> graph(n+1);
        unordered_map<int, int> x, y;

        for(int u = 1; u <= n; u++){
            int px = stones[u-1][0];
            int py = stones[u-1][1];

            if(x.count(px)){
                int v = x[px];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }

            if(y.count(py)){
                int v = y[py];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }

            x[px] = u;
            y[py] = u;
        }

        vector<int> mark(n + 1, 0);
        auto F = [&](int u, auto && self) -> void{
            mark[u] = 1;
            for(auto &v: graph[u]){
                if(mark[v]) continue;
                self(v, self);
            }
        };

        int res = n;

        for(int i = 1; i <= n; i++){
            if(mark[i]) continue;
            F(i, F);
            res -= 1;
        }
        return res;

        int cc=0;
        unordered_set<int> vis;
        for(int i=1;i<=n;i++){
            if(vis.find(i)==vis.end()){
                cc++;
                dfs(i,vis,graph);
            }
        }
        return n-cc;
    }
};