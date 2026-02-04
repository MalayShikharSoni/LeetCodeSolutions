class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countAtMostK(nums, k) - countAtMostK(nums, k - 1);
    }

    int countAtMostK(vector<int> &nums, int k) {
        
        int left = 0;
        int right = 0;
        int count = 0;
        int ans = 0;
        
        unordered_map<int, int> freq;
        
        while(right < nums.size()) {
            
            if(freq[nums[right]] == 0) {
                count++;
            }
            freq[nums[right]]++;
            right++;
            
            while(count > k) {
                if(freq[nums[left]] == 1) {
                    count--;
                }
                freq[nums[left]]--;
                left++;
            }
            
            ans += right - left;
            
        }
        
        return ans;
        
    }
};