class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return subArrays(nums, k) - subArrays(nums, k - 1);

    }

    int subArrays(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        int ans = 0;
        
        while(right < nums.size()) {
            
            if(nums[right] % 2 != 0) {
                count++;
            }

            right++;
            
            while(count > k) {
                if(nums[left] % 2 != 0) {
                    count--; 
                }
                
                left++;
            }
            
            ans += right - left;
            
        }
        
        return ans;
    }
};