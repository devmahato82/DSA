class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        vector<int> ans;
        for(auto a: prerequisites){
            int c = a[0];
            int pre = a[1];
            graph[pre].push_back(c);
            indegree[c]++;
        }
        queue<int>q;
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) {
                q.push(i);
                vis.insert(i);
            }
        }
        while(q.size()>0){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for(auto neighbour : graph[curr]){
                if(not vis.count(neighbour)){
                    indegree[neighbour]--;
                    if(indegree[neighbour] ==0){
                        q.push(neighbour);
                        vis.insert(neighbour);
                    }
                }
                
            }
        }
        return (ans.size()!=n) ? false: true;
    }
};