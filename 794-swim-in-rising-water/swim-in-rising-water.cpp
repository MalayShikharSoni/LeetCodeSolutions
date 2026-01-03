class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int left = grid[0][0];
        int right = n * n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSwim(grid, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool canSwim(vector<vector<int>>& grid, int t) {

        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        return dfs(grid, visited, 0, 0, t);
        
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
             int j, int t) {

        int n = grid.size();

        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] ||
            grid[i][j] > t) {
            return false;
        }

        if (i == n - 1 && j == n - 1) {
            return true;
        }

        visited[i][j] = true;

        return (dfs(grid, visited, i - 1, j, t) ||
                dfs(grid, visited, i + 1, j, t) ||
                dfs(grid, visited, i, j - 1, t) ||
                dfs(grid, visited, i, j + 1, t));
    }
};