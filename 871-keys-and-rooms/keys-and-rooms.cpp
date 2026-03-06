class Solution {
public:
void dfs(vector<vector<int>>& rooms, unordered_set<int>& visited, int room){
    if(visited.find(room) != visited.end()) return;
    visited.insert(room);
    for(int neighbour: rooms[room]){
        if(visited.find(neighbour) == visited.end())
            dfs(rooms,visited,neighbour);
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(rooms,visited,0);
        return visited.size() == rooms.size();
    }
};