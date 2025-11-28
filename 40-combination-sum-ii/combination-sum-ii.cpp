class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combination;

        backTrack(target, ans, combination, 0, candidates);
        return ans;

    }

    void backTrack(int target, vector<vector<int>>& ans, vector<int>& combination, int start, vector<int>& candidates) {
        
        if(target == 0) {
            ans.push_back(combination);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {

            if(i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if(target - candidates[i] < 0) {
                break;
            }

            combination.push_back(candidates[i]);
            backTrack(target - candidates[i], ans, combination, i + 1, candidates);
            combination.pop_back();
        }

    }
};