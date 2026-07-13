class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if(n <= 1) {
            return nums[0];
        }

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        int curr = 0;

        for(int i = 2; i < nums.size(); i++) {
            curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;

    }
};