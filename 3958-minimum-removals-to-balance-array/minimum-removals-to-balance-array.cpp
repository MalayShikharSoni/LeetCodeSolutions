class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int window = 0;

        while(right < nums.size()) {

            if((long long)nums[right] <= k * (long long)nums[left]) {
                window = max(window, right - left + 1);
                right++;
            } else {
                left++;
            }

        }

        return nums.size() - window;

    }
};