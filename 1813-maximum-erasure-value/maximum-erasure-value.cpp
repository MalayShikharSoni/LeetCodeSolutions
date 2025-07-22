class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int left = 0;
        int sum = 0;
        int maxSum = 0;
        unordered_set<int> visited;

        for (int right = 0; right < nums.size(); right++) {

            while (visited.find(nums[right]) != visited.end()) {
                sum -= nums[left];
                visited.erase(nums[left]);
                left++;
            }

            sum += nums[right];
            visited.insert(nums[right]);

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};