class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (grid[r][c] == '1') {
                    islands++;
                    dfs(r, c, grid);
                }
            }
        }

        return islands;
    }

    void dfs(int row, int col, vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols ||
            grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        vector<vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        for(auto& dir : directions) {
            dfs(row + dir[0], col + dir[1], grid);
        }
    }
};