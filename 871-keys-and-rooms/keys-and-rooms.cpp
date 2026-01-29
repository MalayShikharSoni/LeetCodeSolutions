class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int total = rooms.size();
        vector<bool> visited(total, false);

        visited[0] = true;
        for(int room : rooms[0]) {
            dfs(rooms, visited, room);
        }

        for(bool v : visited) {
            if(!v) {
                return false;
            }
        }

        return true;

    }

    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int room) {

        if(visited[room]) {
            return;
        }

        visited[room] = true;
        for(int r : rooms[room]) {
            dfs(rooms, visited, r);
        }

    }
};