class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        int low = 0;
        int high = rows * rows - 1;
        int ans = high;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(canSwim(grid, mid)) {
                ans = mid;
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return ans;

    }

    bool canSwim(vector<vector<int>>& grid, int t) {

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        return dfs(grid, visited, 0, 0, t);

    }

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int t) {

        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] > t || visited[r][c]) {
            return false;
        }

        if(r == grid.size() - 1 && c == grid.size() - 1) {
            return true;
        }

        visited[r][c] = true;

        return dfs(grid, visited, r + 1, c, t) || dfs(grid, visited, r - 1, c, t) || dfs(grid, visited, r, c + 1, t) || dfs(grid, visited, r, c - 1, t);

    }
};