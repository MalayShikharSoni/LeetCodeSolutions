class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n - 1][n - 1]) {
            return -1;
        }
        queue<pair<pair<int, int>, int>> q;

        
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, { 1, -1}, {-1, 1}, {-1, -1}};
        q.push({{0, 0}, 1});
        grid[0][0] = 1;
        while(!q.empty()) {
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int d = q.front().second;
            q.pop();

            if(row == n - 1 && col == n - 1) {
                return d;
            }

            for(auto& dir : directions) {
                int x = row + dir[0];
                int y = col + dir[1];
                if(isValid(x, y, grid)) {
                    q.push({{x, y}, d + 1});
                    grid[x][y] = 1;
                }
            }

        }   

        return -1;
    }

    bool isValid(int x, int y, vector<vector<int>>& grid) {
        int n = grid.size();
        return x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0;
    }

};