class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q, int r, int c) {

        if(r < 0 || r >= grid.size() ||  c < 0 || c >= grid[0].size() || grid[r][c] == 0 || visited[r][c]) {
            return;
        }

        visited[r][c] = true;
        q.push({r, c});

        for(auto& dir : directions) {

            int x = r + dir[0];
            int y = c + dir[1];

            dfs(grid, visited, q, x, y);

        }

    }

    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        bool found = false;

        for(int i = 0; i < n && !found; i++) {
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j] == 1) {
                    dfs(grid, visited, q, i, j);
                    found = true;
                    break;
                }

            }
        }

        int flips = 0;
        while(!q.empty()) {

            int size = q.size();

            while(size--) {
               
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(auto& dir : directions) {

                    int x = i + dir[0];
                    int y = j + dir[1];

                    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y]) {
                        continue;
                    }

                    visited[x][y] = true;

                    if(grid[x][y] == 1) {
                        return flips;
                    }

                    q.push({x, y});

                }
    
            }

            flips++;

        }

        return -1;

    }
};