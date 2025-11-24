class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        int sum = 0;
        vector<bool> ans;

        for (int num : nums) {

            sum = (sum * 2 + num) % 5;
            ans.push_back(sum == 0);
        }

        return ans;
    }
};