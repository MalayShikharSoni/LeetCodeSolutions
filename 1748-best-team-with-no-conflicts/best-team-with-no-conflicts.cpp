class Solution {
public:
    int rec(int i, vector<vector<int>>& v, vector<int>& dp) {

        if (dp[i] != -1)
            return dp[i];

        int ans = v[i][1];  

        for (int j = 0; j < i; j++) {
            if (v[j][1] <= v[i][1]) {
                ans = max(ans, rec(j, v, dp) + v[i][1]);
            }
        }

        return dp[i] = ans;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        int n = scores.size();

        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({ages[i], scores[i]});

        sort(v.begin(), v.end());

        vector<int> dp(n, -1);

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, rec(i, v, dp));

        return ans;
    }
};