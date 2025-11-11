class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto& str : strs) {

            int c0 = count(str.begin(), str.end(), '0');
            int c1 = str.size() - c0;

            for (int i = m; i >= c0; --i) {
                for (int j = n; j >= c1; --j) {

                    dp[i][j] = max(dp[i][j], 1 + dp[i - c0][j - c1]);
                }
            }
        }

        return dp[m][n];
    }
};
