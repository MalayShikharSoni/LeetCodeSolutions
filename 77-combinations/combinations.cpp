class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> curr;

        backtrack(1, curr, ans, n, k);

        return ans;

    }

    void backtrack(int start, vector<int>& curr, vector<vector<int>>& ans, int n, int k) {

        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for(int i = start; i <= n; i++) {

            curr.push_back(i);

            backtrack(i + 1, curr, ans, n, k);

            curr.pop_back();

        }

    }

};