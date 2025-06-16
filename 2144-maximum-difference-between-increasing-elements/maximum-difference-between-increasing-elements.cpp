class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minn = nums[0];
        int maxDiff = -1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minn) {
                maxDiff = max(maxDiff, nums[i] - minn);
            } else {
                minn = nums[i];
            }
        }
        
        return maxDiff;
    }
};
