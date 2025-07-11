class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        set<vector<int>> sett;
        for (int i = 0; i < nums.size(); i++) {

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    sett.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        vector<vector<int>> ans;

        for (auto& triplet : sett) {
            ans.push_back(triplet);
        }
        return ans;
    }
};