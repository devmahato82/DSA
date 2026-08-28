class Solution {
public:
    bool bfs(int start,vector<vector<int>>& graph, vector<int> &vis){
        queue<int> q;
        q.push(start);
        vis[start] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int x : graph[node]){
                if(vis[x] == -1){
                   vis[x] =  (vis[node]==0) ? 1:0;
                   q.push(x);
                }
                else if(vis[node] == vis[x]) return false;
            }

        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i=0; i<n; i++) {
            if(vis[i]==-1) {
                if(bfs(i,graph,vis)==false) return false;
            }
        }
        return true;
    }
};