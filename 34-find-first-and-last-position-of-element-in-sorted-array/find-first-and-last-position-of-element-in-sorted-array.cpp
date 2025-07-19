class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                int start = mid;
                int end = mid;

                while (start >= 0 && nums[start] == target) {
                    start--;
                }

                while (end < nums.size() && nums[end] == target) {
                    end++;
                }

                return {start + 1, end - 1};
            } 
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }

        return {-1, -1};
    }
};
