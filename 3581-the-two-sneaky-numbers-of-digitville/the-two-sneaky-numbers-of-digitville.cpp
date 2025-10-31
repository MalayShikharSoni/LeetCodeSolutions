class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] != i && nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i && nums[i] < n) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};