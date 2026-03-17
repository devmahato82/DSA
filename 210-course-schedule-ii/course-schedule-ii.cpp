class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto c: prerequisites){
            int course = c[0];
            int pre = c[1];
            graph[pre].push_back(course);
            indegree[course]++;
        }
        queue<int>q;
        unordered_set<int> vis;
        for(int i=0; i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                vis.insert(i);
            }
        }
        vector<int> ans;
        while(q.size()>0){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto neighbour: graph[node]){
                if(not vis.count(neighbour)){
                    indegree[neighbour]--;
                    if(indegree[neighbour] ==0){
                        q.push(neighbour);
                        vis.insert(neighbour);
                    }
                }
            }
        }
        return (ans.size()!=numCourses) ? vector<int>{}: ans;
    }
};