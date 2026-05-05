class Solution {
public:

    bool backtrack(vector<int>& nums, vector<bool>& visited, int start, int k, int currSum, int target) {

        if(k == 0) {
            return true;
        }

        if(currSum == target) {
            return backtrack(nums, visited, 0, k - 1, 0, target);
        }

        for(int i = start; i < nums.size(); i++) {

            if(!visited[i] && currSum + nums[i] <= target) {

                visited[i] = true;

                if(backtrack(nums, visited, i + 1, k, currSum + nums[i], target)) {
                    return true;
                }

                visited[i] = false;

                if(currSum == 0) {
                    return false;
                }

            }

        }

        return false;

    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }

        if(sum % k != 0) {
            return false;
        }

        sort(nums.begin(), nums.end(), greater<int>());
        
        int target = sum / k;
        vector<bool> visited(nums.size(), false);

        return backtrack(nums, visited, 0, k, 0, target);

    }
};