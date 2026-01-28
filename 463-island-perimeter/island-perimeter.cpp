class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 1) {
                    perimeter += 4;

                    if(r - 1 >= 0 && grid[r - 1][c]) {
                        perimeter--;
                    }
                    if(r + 1 < rows && grid[r + 1][c]) {
                        perimeter--;
                    }
                    if(c - 1 >= 0 && grid[r][c - 1]) {
                        perimeter--;
                    }
                    if(c + 1 < cols && grid[r][c + 1]) {
                        perimeter--;
                    }

                }
            }
        }

        return perimeter;

    }
};