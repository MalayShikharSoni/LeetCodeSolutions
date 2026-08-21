class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int len = 2; len < m; len++) {

            for(int left = 0; left < m - len; left++) {

                int right = left + len;
                dp[left][right] = INT_MAX;

                for(int k = left + 1; k < right; k++) {

                    int cost = cuts[right] - cuts[left] + dp[left][k] + dp[k][right];
                    dp[left][right] = min(dp[left][right], cost);

                }

            }

        }

        return dp[0][m - 1];

    }
};