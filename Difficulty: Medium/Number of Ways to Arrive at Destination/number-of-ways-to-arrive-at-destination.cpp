class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        int ans =0;
        vector<vector<pair<int,int>>> graph(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            graph[u].push_back({v,weight});
            graph[v].push_back({u,weight});
        }
        vector<long long> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(d > dist[u]) continue;

            for(auto [v,w] : graph[u]){
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(dist[v] == d + w){
                    ways[v] += ways[u];  
                }
            }
        }

        return ways[V-1];
    }
    
};