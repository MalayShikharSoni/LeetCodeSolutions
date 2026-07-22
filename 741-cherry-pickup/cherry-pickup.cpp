class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        
        int ans = solve(grid, dp, 0, 0, 0);
        
        if(ans < 0) {
            return 0;
        }

        return ans;

    }

    int solve(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int r1, int c1, int r2) {

        int c2 = r1 + c1 - r2;
        int n = grid.size();

        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n || c2 < 0) {
            return INT_MIN;
        }

        if(grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }

        if(r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        if(dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        }

        int cherries = 0;

        if(r1 == r2 && c1 == c2) {
            cherries += grid[r1][c1];
        } else {
            cherries += grid[r1][c1] + grid[r2][c2];
        }

        int best = max({
            solve(grid, dp, r1 + 1, c1, r2 + 1),
            solve(grid, dp, r1 + 1, c1, r2),
            solve(grid, dp, r1, c1 + 1, r2 + 1),
            solve(grid, dp, r1, c1 + 1, r2)
        });

        if(best == INT_MIN) {
            return dp[r1][c1][r2] = INT_MIN;
        }

        return dp[r1][c1][r2] = cherries + best;

    }


};