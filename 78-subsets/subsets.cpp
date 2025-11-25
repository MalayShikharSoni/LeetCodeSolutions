class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        generateSubsets(0, temp, nums, ans);
        return ans;

    }

    void generateSubsets(int index, vector<int>& temp, vector<int> nums, vector<vector<int>>& ans) {

        ans.push_back(temp);

        for(int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            generateSubsets(i + 1, temp, nums, ans);
            temp.pop_back();
        }

    }
};