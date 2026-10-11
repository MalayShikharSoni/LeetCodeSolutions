class Solution {
public:

    bool canSplit(vector<int>& nums, int k, int maxSum) {

        int subArr = 1;
        int currSum = 0;

        for(int num : nums) {

            if(currSum + num > maxSum) {

                subArr++;
                currSum = num;

                if(subArr > k) {
                    return false;
                }

            } else {

                currSum += num;
            
            }

        }

        return true;

    }

    int splitArray(vector<int>& nums, int k) {
        
        int low = nums[0];
        int high = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            low = max(low, nums[i]);
            high += nums[i];

        }

        int ans = high;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }

        return ans;

    }
};