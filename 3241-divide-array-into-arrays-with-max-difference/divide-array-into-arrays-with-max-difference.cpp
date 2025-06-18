class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 3) {
            int first = nums[i];
            int second = nums[i + 1];
            int third = nums[i + 2];

            if (third - first > k) {
                return {};
            }

            ans.push_back({first, second, third});
        }

        return ans;
    }
};