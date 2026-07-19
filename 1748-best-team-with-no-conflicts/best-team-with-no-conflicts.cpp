class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        int n = scores.size();

        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({ages[i], scores[i]});

        sort(v.begin(), v.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {

            for (int prev = i - 1; prev >= -1; prev--) {

                int take = 0;

                if (prev == -1 || v[prev][1] <= v[i][1])
                    take = v[i][1] + dp[i + 1][i + 1];

                int notTake = dp[i + 1][prev + 1];

                dp[i][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};