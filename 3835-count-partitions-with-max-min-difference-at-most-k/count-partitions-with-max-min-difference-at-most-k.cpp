class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = (int)nums.size();
        int P[n];
        multiset<int> S;
        for (int r = 0, l = 0; r < n; r++) {
            S.insert(nums[r]);
            while (*prev(S.end()) - *S.begin() > k) {
                S.erase(S.find(nums[l]));
                l += 1;
            }
            P[r] = l;
        }

        int dp[n + 1];
        int psum[n + 1];

        dp[0] = 1;
        psum[0] = 1;
        for (int r = 0; r < n; r++) {
            int l = P[r];
            int rangedp = psum[r];
            if (l > 0)
                rangedp -= psum[l - 1];
            rangedp %= mod;
            if (rangedp < 0)
                rangedp += mod;
            dp[r + 1] = rangedp;
            psum[r + 1] = (psum[r] + dp[r + 1]) % mod;
        }
        return dp[n];
    }
};