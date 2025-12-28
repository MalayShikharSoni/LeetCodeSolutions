class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {

                if(grid[r][c] < 0) {
                    ans += cols - c;
                    break;
                }

            }
        }

        return ans;

    }
};