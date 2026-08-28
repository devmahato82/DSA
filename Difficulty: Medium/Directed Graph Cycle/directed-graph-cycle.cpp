class Solution {
    private:
    bool dfsCheck(int start, vector<vector<int>>&adjlist, vector<int>& vis, vector<int>& vispath) {
        vis[start] = 1;
        vispath[start] = 1;
        for(int it: adjlist[start]) {
            if(vis[it] == 0){
                if(dfsCheck(it, adjlist, vis, vispath) == true) return true;
            }
            else if(vispath[it] != 0) return true;
        }
        vispath[start] = 0;
        return false;
    }
  public:
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adjlist(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adjlist[u].push_back(v);
        }
        vector<int> vis(V,0);
        vector<int>vispath(V,0);
        for(int i=0; i<V; i++) {
            if(vis[i] == 0)
            if(dfsCheck(i,adjlist,vis,vispath)==true) return true;
        }
        return false;
    }
};