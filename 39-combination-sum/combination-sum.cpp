class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> combination;

        backTrack(target, ans, combination, 0, candidates);
        return ans;

    }

    void backTrack(int target, vector<vector<int>>& ans, vector<int>& combination, int start, vector<int> candidates) {
        
        if(target == 0) {
            ans.push_back(combination);
            return;
        }

        if(target < 0) {
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            combination.push_back(candidates[i]);
            backTrack(target - candidates[i], ans, combination, i, candidates);
            combination.pop_back();
        }

    }
};