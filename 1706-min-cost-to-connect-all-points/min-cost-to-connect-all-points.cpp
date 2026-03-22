class Solution {
public:
    int find(vector<int>&parent, int a){
        return parent[a] = (parent[a]==a) ? a: find(parent,parent[a]);
    }
    void Union(vector<int>&parent, vector<int>&rank, int a,int b){
        a = find(parent, a);
        b = find(parent, b);
        if(a==b) return;
        if(rank[a] >= rank[b]){
            rank[a]++;
            parent[b]=a;
        }
        else{
            rank[b]++;
            parent[a] = b;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int,int,int>> graph; //cost,x,y
        int n = points.size();
        for(int i=0; i<n;i++){
            for(int j=i+1; j<n; j++) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph.push_back({cost,i,j});
            }
        }
        sort(graph.begin(),graph.end());
        vector<int> parent(n+1);
        vector<int> rank(n+1,0);
        for(int i=0; i<=n;i++){
            parent[i]= i;
        }
        int edgecount = 0;
        int i=0;
        int ans = 0;
        while(edgecount<n-1 && i<graph.size()){
            auto [cost,u,v] = graph[i];
            int srcpar = find(parent, u);
            int destpar = find(parent, v);
            if(srcpar != destpar) {
                Union(parent,rank,srcpar,destpar);
                ans += cost;
                edgecount++;
            }
            i++;
        }
        return ans;
    }
};