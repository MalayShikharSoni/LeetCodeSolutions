class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 2;
        for (int j = 0; j < k; ++j) {
            vector<int> dp(k, 0);
            for (int i = 0; i < nums.size(); ++i) {
                int mod = nums[i] % k;
                int prev = (j - mod + k) % k;
                dp[mod] = dp[prev] + 1;
            }

            for (int val : dp) {
                ans = max(ans, val);
            }
        }
        return ans;
    }
};