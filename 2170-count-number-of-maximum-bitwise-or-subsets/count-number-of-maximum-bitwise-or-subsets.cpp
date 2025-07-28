class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {

        int maxOr = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxOr |= nums[i];
        }

        return backtrack(nums, maxOr, 0, 0);
    }

    int backtrack(vector<int>& nums, int maxOr, int index, int currOr) {

        if (index == nums.size()) {
            if (currOr == maxOr) {
                return 1;
            }
            return 0;
        }

        if (currOr == maxOr) {
            return 1 << (nums.size() - index);
        }

        return backtrack(nums, maxOr, index + 1, currOr | nums[index]) +
               backtrack(nums, maxOr, index + 1, currOr);
    }
};