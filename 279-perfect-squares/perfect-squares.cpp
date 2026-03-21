class Solution {
public:
    int numSquares(int n) {
        
        vector<int> squares;

        for(int i = 1; i * i <= n; i++) {
            if(i * i <= n) {
                squares.push_back(i * i);
            }
        }

        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        for(int i = 0; i <= n; i++) {

            for(int j = 0; j < squares.size(); j++) {

                if(squares[j] <= i) {
                    dp[i] = min(dp[i], 1 + dp[i - squares[j]]);
                }

            }

        }

        return dp[n];

    }
};