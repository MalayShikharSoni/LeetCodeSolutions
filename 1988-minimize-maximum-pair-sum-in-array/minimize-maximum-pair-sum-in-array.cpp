class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        int maxSum = INT_MIN;

        while(left <= right) {
            maxSum = max(maxSum, nums[left] + nums[right]);
            left++;
            right--;
        }

        return maxSum;

    }
};