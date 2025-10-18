class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int ans = 0;
        int prev = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int j = max(nums[i] - k, prev + 1);

            if (j <= nums[i] + k) {
                prev = j;
                ans++;
            }
        }

        return ans;
    }
};