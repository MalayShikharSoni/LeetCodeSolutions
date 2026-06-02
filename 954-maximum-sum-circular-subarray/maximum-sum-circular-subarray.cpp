class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int currMax = 0;
        int maxSum = INT_MIN;

        int currMin = 0;
        int minSum = INT_MAX;

        int total = 0;

        for(int num : nums) {

            total += num;

            currMax = max(num, num + currMax);
            maxSum = max(maxSum, currMax);

            currMin = min(num, num + currMin);
            minSum = min(minSum, currMin);

        }

        if(maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, total - minSum);

    }
};