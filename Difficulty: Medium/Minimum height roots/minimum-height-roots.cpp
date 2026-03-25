class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> graph(V);
        vector<int> indegree(V,0);
        for(auto a: edges){
            int u = a[0];
            int v = a[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            indegree[v]++;
            indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 1) q.push(i);
        }
        vector<int> ans;
        while(q.size()>0){
            int s = q.size();
            ans.clear();
            for(int i =0;i<s;i++){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto neighbour : graph[node]){
                    indegree[neighbour]--;
                    if(indegree[neighbour] ==1) q.push(neighbour);
                }
            }
        }
        return ans;
    }
};