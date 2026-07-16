class Solution {
public:
    int MOD = 1e9 + 7;

    int checkRecord(int n) {

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, dp, 0, 1, 2);

    }

    int solve(int n, vector<vector<vector<int>>>& dp, int i, int absent, int late) {

        if(i == n) {
            return 1;
        }

        if(dp[i][absent][late] != -1) {
            return dp[i][absent][late];
        }

        int ans = solve(n, dp, i + 1, absent, 2) % MOD; 
        
        if(absent > 0) {
            ans = (ans + solve(n, dp, i + 1, absent - 1, 2) % MOD) % MOD; 
        }

        if(late > 0) {
            ans = (ans + solve(n, dp, i + 1, absent, late - 1) % MOD) % MOD;
        }

        return dp[i][absent][late] = ans;

    }

};