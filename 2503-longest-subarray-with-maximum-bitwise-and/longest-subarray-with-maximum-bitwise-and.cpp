class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        if(nums.size() == 0) {
            return 0;
        }

        int maxx = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxx) {
                maxx = nums[i];
            }
        }

        int maxLength = 0;
        int currLength = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == maxx) {
                currLength++;
            } else {
                maxLength = max(maxLength, currLength);
                currLength = 0;
            }
        }

        return max(maxLength, currLength);

    }
};