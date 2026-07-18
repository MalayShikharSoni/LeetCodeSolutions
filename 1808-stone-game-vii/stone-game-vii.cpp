class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        for(int len = 2; len <= n; len++) {

            for(int i = 0; i < n - len + 1; i++) {

                int j = i + len - 1;

                int sumTakeLeft = prefix[j + 1] - prefix[i + 1];
                int takeLeft = sumTakeLeft - dp[i + 1][j];

                int sumTakeRight = prefix[j] - prefix[i];
                int takeRight = sumTakeRight - dp[i][j - 1];

                dp[i][j] = max(takeLeft, takeRight);

            }

        }

        return dp[0][n - 1];

    }
};