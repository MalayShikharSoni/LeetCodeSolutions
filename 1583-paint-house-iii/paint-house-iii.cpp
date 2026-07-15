class Solution {
public:
    vector<vector<vector<int>>> dp;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

        dp.assign(m, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));

        int ans = solve(houses, cost, m, n, target, 0, 0, 0);

        if(ans == 1e9) {
            return -1;
        }

        return ans;

    }

    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int i, int prevColor, int groups) {

        if(groups > target) {
            return 1e9;
        }

        if(i == m) {

            if(groups == target) { 
                return 0;
            }

            return 1e9;

        }

        if(dp[i][prevColor][groups] != -1) {
            return dp[i][prevColor][groups];
        }

        int ans = 1e9;

        if(houses[i] != 0) {

            int color = houses[i];
            int newGroups = groups;

            if(color != prevColor) {
                newGroups++;
            }

            ans = solve(houses, cost, m, n, target, i + 1, color, newGroups);

        } else {

            for(int color = 1; color <= n; color++) {
    
                int newGroups = groups;

                if(color != prevColor) {
                    newGroups++;
                }

                ans = min(ans, cost[i][color - 1] + solve(houses, cost, m, n, target, i + 1, color, newGroups));
                
            }

        }

        return dp[i][prevColor][groups] = ans;

    }

};