class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {

        vector<long long> dp(n+1, 0);
        dp[1] = 1;
        long long share = 0;
        long long mod = 1000000007;

        for(int d = 2; d <= n; d++) {

            if(d - delay > 0) {
                share = (share + dp[d - delay] + mod) % mod;
            }

            if(d - forget > 0) {
                share = (share - dp[d - forget] + mod) % mod;
            }

            dp[d] = share;

        }

        long long know = 0;

        for(int i = n - forget + 1; i <= n; i++) {
            know = (know + dp[i]) % mod;
        }

        return (int)know;

    }
};