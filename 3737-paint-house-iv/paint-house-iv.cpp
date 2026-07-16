class Solution {
public:
    vector<vector<vector<long long>>> dp;

    long long minCost(int n, vector<vector<int>>& cost) {

        dp.assign(n, vector<vector<long long>>(4, vector<long long>(4, -1)));

        return solve(n, cost, 0, 3, 3);

    }

    long long solve(int n, vector<vector<int>>& cost, int i, int prev, int equiPrev) {

        if(i == n / 2) {
            return 0;
        }

        if(dp[i][prev][equiPrev] != -1) {
            return dp[i][prev][equiPrev];
        }

        long long ans = LLONG_MAX;

        for(int color = 0; color < 3; color++) {
            for(int eq = 0; eq < 3; eq++) {

                if(color != prev && eq != equiPrev && color != eq) {
                    ans = min(ans, cost[i][color] + cost[n - i - 1][eq] + solve(n, cost, i + 1, color, eq));
                }

            }
        }

        return dp[i][prev][equiPrev] = ans;

    }
};