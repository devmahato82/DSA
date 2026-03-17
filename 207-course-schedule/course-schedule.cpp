class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i=0; i<prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            graph[pre].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        unordered_set<int> visited;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                visited.insert(i);
            }
        }
        vector<int> ans;
        while(q.size() >0){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto neighbour: graph[node]){
                if(not visited.count(neighbour)){
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0){
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
        }
        if(ans.size()==numCourses) return true;
        else return false;

    }
};