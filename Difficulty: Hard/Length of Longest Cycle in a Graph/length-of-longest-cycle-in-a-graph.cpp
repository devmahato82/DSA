class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edgeList) {
        vector<int> edges(V, -1);
        vector<int> indegree(V, 0);
        
        for(auto &e : edgeList){
            edges[e[0]] = e[1];
            indegree[e[1]]++;
        }
        
        // Remove non-cycle nodes
        queue<int> q;
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            vis[node] = 1;
            int next = edges[node];
            if(next != -1){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }
        
        // Count cycles
        int ans = -1;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                int curr = i, len = 0;
                while(!vis[curr]){
                    vis[curr] = 1;
                    curr = edges[curr];
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};