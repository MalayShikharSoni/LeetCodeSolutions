class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i,
            int j) {

        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int maxLength = 0;

        for (auto& dir : directions) {

            int x = i + dir[0];
            int y = j + dir[1];

            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() &&
                matrix[x][y] > matrix[i][j]) {
                maxLength = max(maxLength, dfs(matrix, dp, x, y));
            }
        }

        dp[i][j] = 1 + maxLength;
        return dp[i][j];
        
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        if (matrix.empty()) {
            return 0;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }

        return ans;
    }
};