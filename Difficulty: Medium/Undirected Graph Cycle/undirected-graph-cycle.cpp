class Solution {
  public:
    bool detectCycle(int src, vector<vector<int>> &adjlist, vector<int>& vis) {
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it: adjlist[node]) {
                if(vis[it] !=1) {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if(parent != it) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjlist(V);
        
        
        for(auto it : edges) {
            int u= it[0];
            int v = it[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0) {
                if(detectCycle(i,adjlist, vis)==true) return true;
            }
        }
        return false;
        
    }
};