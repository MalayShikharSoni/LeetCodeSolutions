class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        vector<bool> used(n, false);
        vector<int> temp;

        backTrack(ans, temp, nums, used);
        return ans;

    }

    void backTrack(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, vector<bool>& used) {

        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(!used[i]) {
                temp.push_back(nums[i]);
                used[i] = true;

                backTrack(ans, temp, nums, used);

                used[i] = false;
                temp.pop_back();
            }

        }

    }
};