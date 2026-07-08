class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for(int a = 0; a <= amount; a++) {

            for(int j = 0; j < coins.size(); j++) {

                int coinVal = coins[j];

                if(coinVal <= a) {

                    dp[a] = min(dp[a], 1 + dp[a - coinVal]);

                }

            }

        }

        if(dp[amount] == amount + 1) {
            return -1;
        }

        return dp[amount];

    }
};