class Solution {
public:

    bool canSplit(vector<int>& nums, int k, int maxSum) {

        int currSum = 0;
        int subarr = 1;

        for(int num : nums) {

            if(currSum + num > maxSum) {
                subarr++;
                currSum = num;

                if(subarr > k) {
                    return false;
                }

            } else {
                currSum += num;
            }

        }

        return true;

    }

    int splitArray(vector<int>& nums, int k) {
        
        long long low = nums[0];
        long long high = 0;

        for(int num : nums) {

            if(num > low) {
                low = num;
            }
            high += num;
        
        }

        long long ans = high;

        while(low <= high) {

            long mid = low + (high - low) / 2;

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