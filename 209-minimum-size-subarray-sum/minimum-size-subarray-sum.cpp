class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = INT_MAX;
        bool found = false;

        while(right < nums.size()) {

            sum += nums[right];
            
            while(sum >= target) {
                found = true;
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;

        }

        if(!found) {
            return 0;
        }

        return ans;

    }
};