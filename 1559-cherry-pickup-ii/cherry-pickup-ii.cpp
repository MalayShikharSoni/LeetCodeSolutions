class Solution {
public:
    int INF = -1e9;
    
    int solve(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int r, int c1, int c2) {
        
        if(r >= grid.size() || c1 < 0 || c1 >= grid[0].size() || c2 < 0 || c2 >= grid[0].size()) {
            return INF;
        }

        if(r == grid.size()) {
            return 0;
        }

        if(dp[r][c1][c2] != -1) {
            return dp[r][c1][c2];
        }

        int cherries = 0;

        if(c1 == c2) {
            cherries = grid[r][c1];
        } else {
            cherries = grid[r][c1] + grid[r][c2];
        }

        int best = 0;

        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {

                best = max(best, solve(grid, dp, r + 1, c1 + i, c2 + j));

            }
        }

        return dp[r][c1][c2] = cherries + best;

    }

    int cherryPickup(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        return solve(grid, dp, 0, 0, n - 1);

    }


};